#include "stdafx.h"
#include "CBlock.h"
#include "CMining.h"

// unordered_map
std::map<int, CBlock*> Blockchain;
uint32_t BlockHeight = 0;		// BlockHeight ���� ���� ��ġ�� ���ؼ��� �����غ���. CBlockIndex?

void main()
{
	CMining* m_pMining = CMining::Instance();

	// Genesis Block ����
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

		// Cur Target Hash (���̵�) > Block Hash
		while (!m_pMining->IsComplete())
		{
			m_pMining->Update();
		}
		
		// Target Hash ���� ������ Nonce�� ������ �ִ� BlockHeader
		CurBlockHeader = m_pMining->GetBlockHeader();
		
		CBlock* CurBlock = new CBlock(*CurBlockHeader);
		Blockchain.insert(std::make_pair(CurBlock->m_nHeight, CurBlock));
		prevBlock = CurBlock;

		BlockHeight++;
	}	
	
	return;
}