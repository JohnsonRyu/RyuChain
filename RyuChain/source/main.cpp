#include "stdafx.h"
#include "CBlock.h"

// unordered_map
std::map<int, CBlock*> Blockchain;

void main()
{
	// Genesis Block ����
	CBlockHeader* blockHeader = new CBlockHeader;
	CBlock* genesisBlock = new CBlock(*blockHeader);

	// �̰�.. Height ���� Key�� ���� �ٽ� �����غ���..
	Blockchain.insert(std::make_pair(0, genesisBlock));
	
	CBlock* prevBlock = genesisBlock;

	for (BYTE by = 0; by < 10; by++)
	{
		// ��� ��� ����, nBits �����ϰ�, �̸� ���� POW ���� ���̵� ���� nonce ���� �Լ�
		CBlockHeader* CurBlockHeader = new CBlockHeader;

		// if nonce���� ã�Ҵٸ�
		// �����͸� �־��ְ�, ��Ͽ� �־���
		CurBlockHeader->nNonce = 123421 + by;
		CurBlockHeader->previousblockhash = prevBlock->GetBlockHash();

		CBlock* CurBlock = new CBlock(*CurBlockHeader);

		Blockchain.insert(std::make_pair(by + 1, CurBlock));
		prevBlock = CurBlock;
	}

	
	
	return;
}