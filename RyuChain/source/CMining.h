//--------------------------------------------------------------------------------------------------
//
// File Name : CMining.h
// Date : 2018/03/31
// Description : nonce �� ���� Ŭ����
//				 
// Creator : �� �� �� (rkh1206)
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
	bool	 bIsComplete;			// ����� ã�Ҵٸ� Nonce���� �ʱ�ȭ �Ѵ�.
	uint32_t nNonce;

private:
	static CMining* GCMining;
	CBlockHeader*	m_pCurBlockHeader;
	CPow*			m_pPow;
};