//--------------------------------------------------------------------------------------------------
//
// File Name : CMining.h
// Date : 2018/03/31
// Description : nonce 값 대입 클래스
//				 
// Creator : 류 기 혁 (rkh1206)
//
//--------------------------------------------------------------------------------------------------
#include "stdafx.h"

class CBlockHeader;
class CPow;
class CMining
{
public:
	static CMining* Instance();
	~CMining();

private:
	void Init();
public:
	void Update();
	void SetBlockHeader(CBlockHeader* a_cBlockHeader);
	CBlockHeader* GetBlockHeader();
	void FindBlock();
	bool IsComplete();
	
private:
	bool	 bIsComplete;			// 블록을 찾았다면 Nonce값을 초기화 한다.
	uint32_t nNonce;

private:
	static CMining* GCMining;
	CBlockHeader*	m_pCurBlockHeader;
	CPow*			m_pPow;
};