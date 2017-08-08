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

	std::mt19937 m_gen(rd());
	int i;
	interval={1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300};
	weight={2,0,3,7,10,10,17,13,30,29,27,26,6};

	iSize= {250,450,650};
	iWeight= {1,1};

	m_TransactionCountDistribution = std::piecewise_constant_distribution<double> (interval.begin(), interval.end(), weight.begin());
	m_TransactionSizeDistribution = std::piecewise_constant_distribution<double> (iSize.begin(), iSize.end(), iWeight.begin());

	transactionCount = (int) m_TransactionCountDistribution(m_gen);

	//std::cout<<"Count is " << TransactionCount << "\n";
	//std::cout<<"Size is " << TransactionSize << "\n";

	for(i = 0; i< transactionCount; i++)
	{
		transactionSize = m_TransactionSizeDistribution(m_gen);
		Transaction newTransaction(transactionSize);
		m_Transactions.AddTransaction(newTransaction);
	}

}

int main()
{
	BlockMiner a;
	a.MineBlock();
	

	return 0;

}

