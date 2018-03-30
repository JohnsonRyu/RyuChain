//--------------------------------------------------------------------------------------------------
//
// File Name : CBlock.h
// Date : 2018/03/28
// Description : /* transaction */ blockheader
//				 
// Creator : �� �� �� (rkh1206)
//
//--------------------------------------------------------------------------------------------------
#include "CBlockHeader.h"

class CBlock : public CBlockHeader
{
public:
	CBlock(const CBlockHeader& a_cBlockHeader);
	~CBlock();

	CBlockHeader GetBlockHeader() const;	
};