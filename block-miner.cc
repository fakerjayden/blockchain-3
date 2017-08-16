#include <iostream>
#include <vector>
#include <map>
#include <random>
#include "block-miner.h"

/*
 * Class Block-miner functions
 */

BlockMiner::BlockMiner()
{
}

BlockMiner::~BlockMiner(void)
{
}

	void
BlockMiner::MineBlock ()
{

	std::vector<double> interval{1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300};
	std::vector<double> weight{2,0,3,7,10,10,17,13,30,29,27,26,6};

	std::vector<double> iSize {250,450,650};
	std::vector<double> iWeight {1,1};

	std::mt19937 m_gen_count(rd());
	m_TransactionSizeDistribution = std::piecewise_constant_distribution<double> (iSize.begin(), iSize.end(), iWeight.begin());
	m_TransactionCountDistribution = std::piecewise_constant_distribution<double> (interval.begin(), interval.end(), weight.begin());

	transactionCount = m_TransactionCountDistribution(m_gen_count);

	std::vector<Transaction> myNewTransactions;
	myNewTransactions.reserve(transactionCount);

	transactionHeight=0;
	int i=0;

	for(i=0;i<transactionCount;i++)
	{
		std::mt19937 m_gen(rd());

		transactionSize = m_TransactionSizeDistribution(m_gen);
		transactionHeight=i + 1;

		Transaction transaction(transactionSize, transactionHeight);
		std::cout<<"transaction height : "<<transaction.GetTransactionHeight()<<"\n";

		myNewTransactions.push_back(transaction);
	}

	Block myBlock(transactionCount,myNewTransactions);

	std::cout<<"Transaction Count :"<<myBlock.GetTransactionCount()<<"\n";

}


