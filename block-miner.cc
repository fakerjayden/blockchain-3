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

	m_TransactionCountDistribution = std::piecewise_constant_distribution<double> (interval.begin(), interval.end(), weight.begin());
	std::vector<double> iSize {250,450,650};
	std::vector<double> iWeight {1,1};

	m_TransactionSizeDistribution = std::piecewise_constant_distribution<double> (iSize.begin(), iSize.end(), iWeight.begin());

	std::vector<Transaction> myNewTransactions;

	transactionHeight=0;
	int i=0;

	//for(i=0;i<10;i++)
	//{
		std::cout<<i<<"\n";
		std::mt19937 m_gen(rd());

		transactionSize = m_TransactionSizeDistribution(m_gen);
		messageToAdd = "Hello world";
		transactionHeight++;

		Transaction transaction(transactionSize, messageToAdd, transactionHeight);

		std::cout<<"transaction size: "<<transactionSize<<"\n";

		std::cout<<"Transaction size from object: "<<transaction.GetTransactionSizeBytes()<<"\n";
		std::cout<<"Vector size : "<<myNewTransactions.size()<<"\n";

		std::cout<<"Reserve vector space"<<"\n";
		// myNewTransactions.reserve(10 * sizeof(Transaction));

		std::cout<<"Vector size : "<<myNewTransactions.size()<<"\n";

		myNewTransactions.push_back(transaction);
		std::cout<<myNewTransactions.size();

	//}
}


