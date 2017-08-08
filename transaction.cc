#include <iostream>
#include <vector>
#include <random>
#include <map>
#include "transaction.h"


	/**
	 * Class Transaction functions
	 * */

	Transaction::Transaction(double TransactionSizeBytes)
	{
		m_TransactionSizeBytes = TransactionSizeBytes;
	}

	Transaction::Transaction()
	{
		Transaction(0);
	}
	
	Transaction::~Transaction(void)
	{
	}

	double
		Transaction::GetTransactionSizeBytes (void) const
		{
			return m_TransactionSizeBytes;
		}

	void
		Transaction::SetTransactionSizeBytes (double TransactionSizeBytes)
		{
			m_TransactionSizeBytes = TransactionSizeBytes;

		}

	/**
	 * Class BlockTransactions functions
	 * */

BlockTransactions::BlockTransactions(void){
	Transaction genesisTransaction(350);
	AddTransaction(genesisTransaction);
}

BlockTransactions::~BlockTransactions(void)
{
}

void
BlockTransactions::AddTransaction( const Transaction& newTransaction)
{
	m_Transactions.push_back(newTransaction);
}


int main()
{
	//declarations
	std::vector<double> interval,weight,iSize,iWeight;
	std::piecewise_constant_distribution<double> m_TransactionCountDistribution, m_TransactionSizeDistribution;

	std::random_device rd;
	std::mt19937 m_gen(rd());
	int TransactionCount,i;
	double TransactionSize;

	//declarations end
	 interval={1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300};
	 weight={2,0,3,7,10,10,17,13,30,29,27,26,6};

	 iSize= {250,450,650};
	 iWeight= {1,1};

	m_TransactionCountDistribution = std::piecewise_constant_distribution<double> (interval.begin(), interval.end(), weight.begin());
	m_TransactionSizeDistribution = std::piecewise_constant_distribution<double> (iSize.begin(), iSize.end(), iWeight.begin());

	TransactionCount = (int) m_TransactionCountDistribution(m_gen);

	//std::cout<<"Count is " << TransactionCount << "\n";
	//std::cout<<"Size is " << TransactionSize << "\n";
	
	for(i = 0; i< TransactionCount; i++)
	{
		TransactionSize = m_TransactionSizeDistribution(m_gen);
		Transaction newTransaction(TransactionSize);
		m_Transactions.push_back(newTransaction);
	}

	return 0;

}
