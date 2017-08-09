#include <iostream>
#include <vector>
#include "block.h"

/*
 * Block functions
 */


Block::Block(int transactionCount,std::vector<Transaction> transactions  )
{
	m_transactionCount = transactionCount;
	m_transactions = transactions;
}

Block::Block()
{
	Block(0,{ {Transaction(0,"hello",0),Transaction(1,"hello again",1) } });
}

Block::~Block (void)
{
}

int
Block::GetTransactionCount (void) const
{
	return m_transactionCount;
}

void
Block::SetTransactionCount (int transactionCount)
{
	m_transactionCount = transactionCount;
}

/*
 * Blockchain functions
 */

Blockchain::Blockchain(void)
{
	Block genesisBlock(0);
	AddBlock(genesisBlock);
}

Blockchain::~Blockchain(void)
{
}

void
Blockchain::AddBlock (const Block& newBlock)
{
	m_blocks.push_back(newBlock);
}
