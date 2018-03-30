//--------------------------------------------------------------------------------------------------
//
// File Name : CBlock.cpp
// Date : 2018/03/28
// Description : /* transaction */ blockheader
//				 
// Creator : ·ù ±â Çõ (rkh1206)
//
//--------------------------------------------------------------------------------------------------
#include "CBlock.h"

//--------------------------------------------------------------------------------------------------
CBlock::CBlock(const CBlockHeader& a_cBlockHeader)
{
	*((CBlockHeader*)this) = a_cBlockHeader;

	this->LogData();
}
//--------------------------------------------------------------------------------------------------
CBlock::~CBlock(){}
//--------------------------------------------------------------------------------------------------
CBlockHeader CBlock::GetBlockHeader() const
{
	CBlockHeader block;
	
	block.nTime  = CBlock::nTime;
	block.nBits  = CBlock::nBits;
	block.nNonce = CBlock::nNonce;

	return block;
}
//--------------------------------------------------------------------------------------------------