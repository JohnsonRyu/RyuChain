//--------------------------------------------------------------------------------------------------
//
// File Name : CBlockHeader.h
// Date : 2018/03/27
// Description : Block�� �⺻���� �����͸� ��´�.
//				 1. version / 2. previousblockhash / 3. merklehash / 4. time / 5. bits / 6. nonce
// Creator : �� �� �� (rkh1206)
//
//--------------------------------------------------------------------------------------------------
#include "stdafx.h"

class CBlockHeader
{
public:
	CBlockHeader();
	~CBlockHeader();

	void	Init();
	void	LogData();
	bool	IsNull();
	void	SetBlockTime();
	int64_t GetBlockTime();
	vector<BYTE> GetBlockHash();

public:
	vector<BYTE> previousblockhash;
	uint32_t m_nHeight;		// Height�� ��ġ�� �ٽ� ���
	uint32_t m_nTime;			// Micro Seconds
	uint32_t m_nBits;
	uint32_t m_nNonce;
};