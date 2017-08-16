#ifndef BLOCK_MINER_H
#define BLOCK_MINER_H

#include <iostream>
#include <vector>
#include <map>
#include <random>
#include <string>
#include "block.h"

class BlockMiner
{
	public:
		BlockMiner();
		~BlockMiner(void);

	 	virtual void MineBlock (void);

	protected:

		std::vector<double> interval,weight,iSize,iWeight;
		std::piecewise_constant_distribution<double> m_TransactionCountDistribution, m_TransactionSizeDistribution;

		std::random_device rd;
		int transactionCount;
		double transactionSize;
		int transactionHeight;
		Transaction transaction;
		std::vector<Transaction> newTransactions;


};


#endif /* BLOCKMINER_H */
