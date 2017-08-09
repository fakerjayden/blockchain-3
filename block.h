#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <vector>
#include "transaction.h"

class Block
{
	public:
		Block (int transactionCount=0, std::vector<Transaction> transactions = { {Transaction(0,"hello",0) } });
		Block();
		virtual ~Block (void);
		int GetTransactionCount (void) const;
		void SetTransactionCount (int transactionCount);
		

	protected:
		int m_transactionCount;
		std::vector<Transaction> m_transactions;
};

class Blockchain
{
	public:
		Blockchain (void);
		virtual ~Blockchain(void);

		void AddBlock(const Block& newBlock);

	private:
		std::vector<Block> m_blocks; //vector of blocks

};


#endif /* BLOCK_H */
