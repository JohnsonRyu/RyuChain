//--------------------------------------------------------------------------------------------------
//
// File Name : CBlockHeader.cpp
// Date : 2018/03/27
// Description : Block의 기본적인 데이터를 담는다.
//				 1. nHeight / 2. nTime / 3. nBits / 4. nNonce / 5. hashPrevBlock
// Creator : 류 기 혁 (rkh1206)
//
//--------------------------------------------------------------------------------------------------
#include "CBlockHeader.h"
#include "CHash.h"
//--------------------------------------------------------------------------------------------------
CBlockHeader::CBlockHeader()
{
	Init();
}
//--------------------------------------------------------------------------------------------------
CBlockHeader::~CBlockHeader(){}
//--------------------------------------------------------------------------------------------------
void CBlockHeader::Init()
{
	previousblockhash.clear();

	nHeight = 0;
	nTime	= 0;
	nBits	= 0;
	nNonce	= 0;
}
//--------------------------------------------------------------------------------------------------
void CBlockHeader::LogData()
{
	time_t time_now;
	struct tm *tm;

	time(&time_now);
	tm = localtime(&time_now);

	printf("Block Info\n");
	printf("%d년 %d월 %d일 %d시 %d분 %d초\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
	printf("PrevBlockHash : ");

	if (0 == previousblockhash.size())
		printf("Genesis Block");
	else
	{
		for (BYTE by = 0; by < previousblockhash.size(); by++)
		{
			printf("%02X", previousblockhash[by]);
		}
	}
	
	printf("\nCurBlockHash : ");

	vector<BYTE> thisBlockHash = GetBlockHash();
	for (BYTE by = 0; by < thisBlockHash.size(); by++)
	{
		printf("%02X", thisBlockHash[by]);
	}

	printf("\n-CurBlockHeingt : %d", nHeight);
	printf("\n--CurBlockTime : %"PRIu64"", nTime);
	printf("\n---CurBlockBits : %d", nBits);
	printf("\n----CurBlockNonce : %d", nNonce);

	printf("\n\n");
}
//--------------------------------------------------------------------------------------------------
bool CBlockHeader::IsNull()
{
	return nBits == 0;
}
//--------------------------------------------------------------------------------------------------
void CBlockHeader::SetBlockTime()
{
	nTime = chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now().time_since_epoch()).count();
}
//--------------------------------------------------------------------------------------------------
int64_t CBlockHeader::GetBlockTime()
{
	return static_cast<int64_t>(nTime);
}
//--------------------------------------------------------------------------------------------------
vector<BYTE> CBlockHeader::GetBlockHash()
{
	return Hash->GetObjectHash(*this);
}
//--------------------------------------------------------------------------------------------------