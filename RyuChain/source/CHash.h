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
	BYTE* GetObjectHash(CBlockHeader& a_cBlockHeader);

private:
	static CHash* GCHash;
};

//template<typename T>
//CHashWriter& operator<<(const T& obj) {
//	// Serialize to this stream
//	::Serialize(*this, obj);		// "��ü ����ȭ" 
//	return (*this);