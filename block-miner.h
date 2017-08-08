#ifndef BLOCK_MINER_H
#define BLOCK_MINER_H

#include <iostream>
#include <vector>
#include <map>
#include <random>
#include "block.h"

class BlockMiner
{
	public:
		BlockMiner();
		virtual ~BlockMiner(void);
	 	virtual void MineBlock (void);

	protected:

		std::vector<double> interval,weight,iSize,iWeight;
		std::piecewise_constant_distribution<double> m_TransactionCountDistribution, m_TransactionSizeDistribution;

		std::random_device rd;
		int transactionCount;
		double transactionSize;
		BlockTransactions m_Transactions;


};


#endif /* BLOCKMINER_H */
