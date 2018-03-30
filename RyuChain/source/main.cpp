#include "stdafx.h"
#include "CBlock.h"

// unordered_map
std::map<int, CBlock*> Blockchain;

void main()
{
	CBlockHeader* blockHeader = new CBlockHeader;
	CBlock* genesisBlock = new CBlock(*blockHeader);
	Blockchain.insert(std::make_pair(0, genesisBlock));
	
	CBlock* prevBlock = genesisBlock;
	BYTE* aa = prevBlock->GetBlockHash();

	BYTE hashValue[32] = prevBlock->GetBlockHash();

	printf("%02X\n\n\n", aa);

	for (int i = 0; i < sizeof(hashValue); i++)
	{
		printf("%02X", hashValue[i]);
	}

	printf("\n");


	/*BYTE encypt[32];

	stringstream ss;
	string zs = "";
	ss << uint32_t(123);
	ss << uint32_t(230485);
	ss << uint32_t(98);
	ss << uint32_t(12);

	printf("Æò¹® : ");
	scanf_s("%s", plain, sizeof(plain));

	ss << plain;
	ss >> zs;

	BYTE* by = (BYTE*)zs.c_str();

	SHA256_Encrpyt(by, zs.length(), encypt);

	for (int i = 0; i < sizeof(encypt); i++)
	{
	printf("%02X", encypt[i]);
	}
	printf("\n");*/
	
	return;
}