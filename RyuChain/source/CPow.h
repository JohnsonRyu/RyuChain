//--------------------------------------------------------------------------------------------------
//
// File Name : CPow.h
// Date : 2018/03/31
// Description : nBits로 cur_target 값 구하기 & nonce값 대입
//				 
// Creator : 류 기 혁 (rkh1206)
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