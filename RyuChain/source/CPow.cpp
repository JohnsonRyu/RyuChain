//--------------------------------------------------------------------------------------------------
//
// File Name : CPow.cpp
// Date : 2018/03/31
// Description : nBits�� cur_target �� ���ϱ� & nonce�� ����
//				 
// Creator : �� �� �� (rkh1206)
//
//--------------------------------------------------------------------------------------------------
#include "CPow.h"
#include "CBlockHeader.h"
//--------------------------------------------------------------------------------------------------
CPow::CPow()
{
	Init();
}
//--------------------------------------------------------------------------------------------------
CPow::~CPow(){}
//--------------------------------------------------------------------------------------------------
void CPow::SetCurBlockHeader(CBlockHeader* a_cBlockHeader)
{
	Init();

	m_CBlockHeader = a_cBlockHeader;
	SetCurTarget();
}
//--------------------------------------------------------------------------------------------------
bool CPow::SetNonce(uint32_t a_unNonce)
{
	if (nullptr == m_CBlockHeader)
	{
		printf("CPOW::SetNonce m_CBlockHeader null\n");
		return false;
	}

	m_CBlockHeader->nNonce = a_unNonce;

	return CompareHash();
}
//--------------------------------------------------------------------------------------------------
void CPow::Init()
{
	m_CBlockHeader = nullptr;
	vCurTartget.clear();
}
//--------------------------------------------------------------------------------------------------
void CPow::SetCurTarget()
{
	// nBits�� target�� ���ϱ�
	vCurTartget.clear();

	// ���� �ش� �Լ��� ���̵� �Լ��� ��ȯ����!
	string_to_bytearray("00006F5123AB213490045110FE85F428FA54F8014C7B11C00DB190DCCDEB9C55");
}
//--------------------------------------------------------------------------------------------------
bool CPow::CompareHash()
{
	if (nullptr == m_CBlockHeader)
	{
		printf("CPOW::CompareHash m_CBlockHeader null\n");
		return false;
	}

	//��ǥ Hash ���� ���� �������� ���ϴ� ���� �ƴ� �ӽ�.
	vector<BYTE> CurBlockHash = m_CBlockHeader->GetBlockHash();

	for (BYTE by = 0; by < vCurTartget.size(); by++)
	{
		if (CurBlockHash[by] < vCurTartget[by])
		{
			// printf("\n\n#####%02X & %02X\n", CurBlockHash[by], vCurTartget[by]);
			// Success!
			return true;
		}
		else if (CurBlockHash[by] == vCurTartget[by]);
		else
			return false;
	}

	return false;
}
//--------------------------------------------------------------------------------------------------
void CPow::string_to_bytearray(std::string str)
{
	// ��� �迭�� �޸� �Ҵ�
	BYTE curTarget[32];

	std::stringstream sstr(str);
	for (int i = 0; i < sizeof(curTarget); i++)
	{
		char ch1, ch2;
		sstr >> ch1 >> ch2;
		int dig1, dig2;
		if (isdigit(ch1)) dig1 = ch1 - '0';
		else if (ch1 >= 'A' && ch1 <= 'F') dig1 = ch1 - 'A' + 10;
		else if (ch1 >= 'a' && ch1 <= 'f') dig1 = ch1 - 'a' + 10;
		if (isdigit(ch2)) dig2 = ch2 - '0';
		else if (ch2 >= 'A' && ch2 <= 'F') dig2 = ch2 - 'A' + 10;
		else if (ch2 >= 'a' && ch2 <= 'f') dig2 = ch2 - 'a' + 10;
		curTarget[i] = dig1 * 16 + dig2;
	}

	for (BYTE by = 0; by < sizeof(curTarget); by++)
	{
		vCurTartget.push_back(curTarget[by]);
	}
}
//--------------------------------------------------------------------------------------------------