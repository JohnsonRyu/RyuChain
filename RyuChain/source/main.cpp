#include "stdafx.h"
#include "CBlock.h"
#include "CMining.h"

// unordered_map
std::map<int, CBlock*> Blockchain;
uint32_t BlockHeight = 0;		// BlockHeight ���� ���� ��ġ�� ���ؼ��� �����غ���. CBlockIndex?

void main()
{
	CMining* m_CMining = CMining::Instance();

	// Genesis Block ����
	CBlockHeader* blockHeader = new CBlockHeader;
	blockHeader->nHeight = BlockHeight;
	CBlock* genesisBlock = new CBlock(*blockHeader);

	BlockHeight++;

	CBlock* prevBlock = genesisBlock;

	// �̰�.. Height ���� Key�� ���� �ٽ� �����غ���..
	Blockchain.insert(std::make_pair(genesisBlock->nHeight, genesisBlock));
	
	for (BYTE by = 0; by < 10; by++)
	{
		// ��� ��� ����, nBits �����ϰ�, �̸� ���� POW ���� ���̵� ���� nonce ���� �Լ�
		CBlockHeader* CurBlockHeader = new CBlockHeader;
		CurBlockHeader->previousblockhash = prevBlock->GetBlockHash();
		CurBlockHeader->nHeight = BlockHeight;
		CurBlockHeader->nBits = 0;

		m_CMining->SetBlockHeader(CurBlockHeader);

		while (!m_CMining->IsComplete())
		{
			m_CMining->Update();
		}
		
		// Nonce���� ã�Ҵٸ� �ش� �������� ������ �´�.
		CurBlockHeader = m_CMining->GetBlockHeader();
		
		CBlock* CurBlock = new CBlock(*CurBlockHeader);
		Blockchain.insert(std::make_pair(CurBlock->nHeight, CurBlock));
		prevBlock = CurBlock;

		BlockHeight++;
	}	
	
	return;
}