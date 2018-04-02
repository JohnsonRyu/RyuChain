//--------------------------------------------------------------------------------------------------
//
// File Name : CMining.cpp
// Date : 2018/03/31
// Description : nonce 값 대입 클래스
//				 
// Creator : 류 기 혁 (rkh1206)
//
//--------------------------------------------------------------------------------------------------
#include "CMining.h"
#include "CBlockHeader.h"
#include "CPow.h"

CMining* CMining::GCMining = nullptr;
//--------------------------------------------------------------------------------------------------
CMining* CMining::Instance()
{
	if (nullptr == GCMining)
	{
		GCMining = new CMining();
		GCMining->Init();
	}

	return GCMining;
}
//--------------------------------------------------------------------------------------------------
CMining::~CMining(){}
//--------------------------------------------------------------------------------------------------
void CMining::Init()
{
	bIsComplete = false;
	nNonce = 0;

	m_pCurBlockHeader = nullptr;
	m_pPow = new CPow;
}
//--------------------------------------------------------------------------------------------------
void CMining::Update()
{
	if (nullptr != m_pPow && !bIsComplete)
	{
		if (m_pPow->SetNonce(nNonce))
		{
			m_pCurBlockHeader->nNonce = nNonce;
			FindBlock();
		}
		else
			nNonce++;
	}
}
//--------------------------------------------------------------------------------------------------
void CMining::SetBlockHeader(CBlockHeader* a_cBlockHeader)
{
	Init();

	if (nullptr != m_pPow)
		m_pPow->SetCurBlockHeader(a_cBlockHeader);

	m_pCurBlockHeader = a_cBlockHeader;
}
//--------------------------------------------------------------------------------------------------
CBlockHeader* CMining::GetBlockHeader()
{
	return m_pCurBlockHeader;
}
//--------------------------------------------------------------------------------------------------
void CMining::FindBlock()
{
	bIsComplete = true;
}
//--------------------------------------------------------------------------------------------------
bool CMining::IsComplete() { return bIsComplete; }
//--------------------------------------------------------------------------------------------------