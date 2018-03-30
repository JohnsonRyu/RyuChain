//--------------------------------------------------------------------------------------------------
//
// File Name : CHash.h
// Date : 2018/03/28
// Description : 객체를 직렬화 하여 해시값을 얻는 클래스.
//				 
// Creator : 류 기 혁 (rkh1206)
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