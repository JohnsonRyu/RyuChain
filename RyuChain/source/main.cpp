#include "stdafx.h"
#include "CBlock.h"
#include "CMining.h"

// unordered_map
std::map<int, CBlock*> Blockchain;
uint32_t BlockHeight = 0;		// BlockHeight 변수 저장 위치에 대해서는 생각해보자. CBlockIndex?

void main()
{
	CMining* m_CMining = CMining::Instance();

	// Genesis Block 생성
	CBlockHeader* blockHeader = new CBlockHeader;
	blockHeader->nHeight = BlockHeight;
	CBlock* genesisBlock = new CBlock(*blockHeader);

	BlockHeight++;

	CBlock* prevBlock = genesisBlock;

	// 이건.. Height 값을 Key로 줄지 다시 생각해보자..
	Blockchain.insert(std::make_pair(genesisBlock->nHeight, genesisBlock));
	
	for (BYTE by = 0; by < 10; by++)
	{
		// 블록 헤더 생성, nBits 지정하고, 이를 통해 POW 에서 난이도 생성 nonce 대입 함수
		CBlockHeader* CurBlockHeader = new CBlockHeader;
		CurBlockHeader->previousblockhash = prevBlock->GetBlockHash();
		CurBlockHeader->nHeight = BlockHeight;
		CurBlockHeader->nBits = 0;

		m_CMining->SetBlockHeader(CurBlockHeader);

		while (!m_CMining->IsComplete())
		{
			m_CMining->Update();
		}
		
		// Nonce값을 찾았다면 해당 블록헤더를 가지고 온다.
		CurBlockHeader = m_CMining->GetBlockHeader();
		
		CBlock* CurBlock = new CBlock(*CurBlockHeader);
		Blockchain.insert(std::make_pair(CurBlock->nHeight, CurBlock));
		prevBlock = CurBlock;

		BlockHeight++;
	}	
	
	return;
}