#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <vector>
#include "transaction.h"

class Block
{
	public:
		Block (int transactionCount,std::vector<Transaction> blockTransactions);
		Block();
		~Block (void);

		int GetTransactionCount (void) const;
		void SetTransactionCount (int transactionCount);

	protected:
		int m_transactionCount;
		std::vector<Transaction> m_blockTransactions;
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
