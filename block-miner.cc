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
	std::vector<double> interval{1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300};
	std::vector<double> weight{2,0,3,7,10,10,17,13,30,29,27,26,6};

	std::vector<double> iSize {250,450,650};
	std::vector<double> iWeight {1,1};

	m_TransactionCountDistribution = std::piecewise_constant_distribution<double> (interval.begin(), interval.end(), weight.begin());
	m_TransactionSizeDistribution = std::piecewise_constant_distribution<double> (iSize.begin(), iSize.end(), iWeight.begin());

	transactionCount = (int) m_TransactionCountDistribution(m_gen);
	transactionSize = m_TransactionSizeDistribution(m_gen);
	messageToAdd = "Hello world";
	transactionHeight = 1;

	Transaction transaction(transactionSize, messageToAdd, transactionHeight);

	std::cout<<"Transaction Size is :"<<transaction.GetTransactionSizeBytes()<<"\n";
	std::cout<<"Transaction message is :"<<transaction.GetTransactionMessage()<<"\n";
	std::cout<<"Transaction Height is :"<<transaction.GetTransactionHeight()<<"\n";


	//std::cout<<"Count is " << transactionCount << "\n";
	//std::cout<<"Size is " << transactionSize << "\n";

	//for(i = 0; i< transactionCount; i++)
	//{
	//	transactionSize = m_TransactionSizeDistribution(m_gen);
	//	Transaction newTransaction(transactionSize);
	//}


}


