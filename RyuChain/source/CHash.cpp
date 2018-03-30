//--------------------------------------------------------------------------------------------------
//
// File Name : CHash.cpp
// Date : 2018/03/28
// Description : 객체를 직렬화 하여 해시값을 얻는 클래스.
//				 
// Creator : 류 기 혁 (rkh1206)
//
//--------------------------------------------------------------------------------------------------
#include "CHash.h"
#include "CBlockHeader.h"

CHash* CHash::GCHash = nullptr;
//--------------------------------------------------------------------------------------------------
CHash* CHash::Instance()
{
	if (nullptr == GCHash)
	{
		GCHash = new CHash();
	}

	return GCHash;
}
//--------------------------------------------------------------------------------------------------
CHash::~CHash(){}
//--------------------------------------------------------------------------------------------------
vector<BYTE> CHash::GetObjectHash(CBlockHeader& a_cBlockHeader)
{
	// Serialization lib 찾아보기.
	BYTE encypt[32];

	stringstream ss;
	string kStr;
	ss << a_cBlockHeader.GetBlockTime();
	ss << a_cBlockHeader.nTime;
	ss << a_cBlockHeader.nBits;
	ss << a_cBlockHeader.nNonce;	
	
	for (BYTE by = 0; by < a_cBlockHeader.previousblockhash.size(); by++)
	{
		ss << a_cBlockHeader.previousblockhash[by];
	}

	ss >> kStr;

	BYTE* by = (BYTE*)kStr.c_str();
	SHA256_Encrpyt(by, kStr.length(), encypt);

	vector<BYTE> vBy;


	for (BYTE by = 0; by < sizeof(encypt); by++)
	{
		vBy.push_back(encypt[by]);
	}

	return vBy;
}
//--------------------------------------------------------------------------------------------------