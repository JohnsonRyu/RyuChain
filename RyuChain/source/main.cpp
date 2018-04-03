#include "stdafx.h"
#include "CBlock.h"
#include "CMining.h"

// unordered_map
std::map<int, CBlock*> Blockchain;
uint32_t BlockHeight = 0;		// BlockHeight 변수 저장 위치에 대해서는 생각해보자. CBlockIndex?

void main()
{
	CMining* m_pMining = CMining::Instance();

	// Genesis Block 생성
	CBlockHeader* blockHeader = new CBlockHeader;
	blockHeader->m_nHeight = BlockHeight;
	CBlock* genesisBlock = new CBlock(*blockHeader);
	Blockchain.insert(std::make_pair(genesisBlock->m_nHeight, genesisBlock));
	
	CBlock* prevBlock = genesisBlock;
	BlockHeight++;
	
	for (BYTE by = 0; by < 10; by++)
	{
		CBlockHeader* CurBlockHeader = new CBlockHeader;
		CurBlockHeader->previousblockhash = prevBlock->GetBlockHash();
		CurBlockHeader->m_nHeight = BlockHeight;
		CurBlockHeader->m_nBits = 0;

		m_pMining->SetBlockHeader(CurBlockHeader);

		// Cur Target Hash (난이도) > Block Hash
		while (!m_pMining->IsComplete())
		{
			m_pMining->Update();
		}
		
		// Target Hash 값에 만족한 Nonce를 가지고 있는 BlockHeader
		CurBlockHeader = m_pMining->GetBlockHeader();
		
		CBlock* CurBlock = new CBlock(*CurBlockHeader);
		Blockchain.insert(std::make_pair(CurBlock->m_nHeight, CurBlock));
		prevBlock = CurBlock;

		BlockHeight++;
	}	
	
	return;
}