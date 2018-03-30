//--------------------------------------------------------------------------------------------------
//
// File Name : CHash.h
// Date : 2018/03/28
// Description : ��ü�� ����ȭ �Ͽ� �ؽð��� ��� Ŭ����.
//				 
// Creator : �� �� �� (rkh1206)
//
//--------------------------------------------------------------------------------------------------
#include "stdafx.h"

#define Hash	CHash::Instance()

class CBlockHeader;
class CHash
{
public:
	static CHash* Instance();
	~CHash();

public:
	vector<BYTE> GetObjectHash(CBlockHeader& a_cBlockHeader);

private:
	static CHash* GCHash;
};