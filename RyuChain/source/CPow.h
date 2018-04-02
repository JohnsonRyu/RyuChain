//--------------------------------------------------------------------------------------------------
//
// File Name : CPow.h
// Date : 2018/03/31
// Description : nBits�� cur_target �� ���ϱ� & nonce�� ����
//				 
// Creator : �� �� �� (rkh1206)
//
//--------------------------------------------------------------------------------------------------
#include "stdafx.h"

class CBlockHeader;
class CPow
{
public:
	CPow();
	~CPow();

public:
	void SetCurBlockHeader(CBlockHeader* a_cBlockHeader);
	bool SetNonce(uint32_t a_unNonce);

private:
	void Init();
	void SetCurTarget();
	bool CompareHash();
	void string_to_bytearray(std::string str);

private:
	CBlockHeader* m_CBlockHeader;

	vector<BYTE> vCurTartget;
};