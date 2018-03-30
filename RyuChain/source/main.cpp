#include "stdafx.h"
#include "CBlock.h"

// unordered_map
std::map<int, CBlock*> Blockchain;

void main()
{
	// Genesis Block 생성
	CBlockHeader* blockHeader = new CBlockHeader;
	CBlock* genesisBlock = new CBlock(*blockHeader);

	// 이건.. Height 값을 Key로 줄지 다시 생각해보자..
	Blockchain.insert(std::make_pair(0, genesisBlock));
	
	CBlock* prevBlock = genesisBlock;

	for (BYTE by = 0; by < 10; by++)
	{
		// 블록 헤더 생성, nBits 지정하고, 이를 통해 POW 에서 난이도 생성 nonce 대입 함수
		CBlockHeader* CurBlockHeader = new CBlockHeader;

		// if nonce값을 찾았다면
		// 데이터를 넣어주고, 블록에 넣어줌
		CurBlockHeader->nNonce = 123421 + by;
		CurBlockHeader->previousblockhash = prevBlock->GetBlockHash();

		CBlock* CurBlock = new CBlock(*CurBlockHeader);

		Blockchain.insert(std::make_pair(by + 1, CurBlock));
		prevBlock = CurBlock;
	}

	
	
	return;
}