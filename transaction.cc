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


