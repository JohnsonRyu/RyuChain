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
	int64_t GetBlockTime();
	vector<BYTE> GetBlockHash();

public:
	vector<BYTE> previousblockhash;
	uint32_t nHeight;		// Height�� ��ġ�� �ٽ� ���
	uint32_t nTime;
	uint32_t nBits;
	uint32_t nNonce;
};