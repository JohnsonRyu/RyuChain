//--------------------------------------------------------------------------------------------------
//
// File Name : CBlockHeader.cpp
// Date : 2018/03/27
// Description : Block�� �⺻���� �����͸� ��´�.
//				 1. nHeight / 2. nTime / 3. nBits / 4. nNonce / 5. hashPrevBlock
// Creator : �� �� �� (rkh1206)
//
//--------------------------------------------------------------------------------------------------
#include "CBlockHeader.h"
#include "CHash.h"
//--------------------------------------------------------------------------------------------------
CBlockHeader::CBlockHeader()
{
	Init();
}
//--------------------------------------------------------------------------------------------------
CBlockHeader::~CBlockHeader(){}
//--------------------------------------------------------------------------------------------------
void CBlockHeader::Init()
{
	previousblockhash.clear();

	nHeight = 0;
	nTime	= 0;
	nBits	= 0;
	nNonce	= 0;
}
//--------------------------------------------------------------------------------------------------
void CBlockHeader::LogData()
{
	printf("Block Info\n");
	printf("PrevBlockHash\n");

	if (0 == previousblockhash.size())
		printf("Genesis Block");
	else
	{
		for(BYTE by = 0; by < previousblockhash.size(); by++)
		{
			printf("%02X", previousblockhash[by]);
		}
	}

	printf("\nCurBlockHash\n");

	vector<BYTE> thisBlockHash = GetBlockHash();
	for (BYTE by = 0; by < thisBlockHash.size(); by++)
	{
		printf("%02X", thisBlockHash[by]);
	}

	printf("\n");
}
//--------------------------------------------------------------------------------------------------
bool CBlockHeader::IsNull()
{
	return nBits == 0;
}
//--------------------------------------------------------------------------------------------------
int64_t CBlockHeader::GetBlockTime()
{
	// TimeStamp

	return 0;
}
//--------------------------------------------------------------------------------------------------
vector<BYTE> CBlockHeader::GetBlockHash()
{
	return Hash->GetObjectHash(*this);
}
//--------------------------------------------------------------------------------------------------