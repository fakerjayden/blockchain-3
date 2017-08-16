#include <iostream>
#include <vector>
#include <string>
#include "transaction.h"


/**
 * Class Transaction functions
 * */

Transaction::Transaction(double transactionSizeBytes, int transactionHeight ) : m_transactionSizeBytes(transactionSizeBytes), m_transactionHeight(transactionHeight) 
{} 

Transaction::Transaction() = default; //needed for initialization

Transaction::~Transaction(void)
{
}

double
Transaction::GetTransactionSizeBytes (void) const
{
	return m_transactionSizeBytes;
}

	void
Transaction::SetTransactionSizeBytes (double transactionSizeBytes)
{
	m_transactionSizeBytes = transactionSizeBytes;

}

int
Transaction::GetTransactionHeight (void) const
{
	return m_transactionHeight;
}

	void
Transaction::SetTransactionHeight (int transactionHeight)
{
	m_transactionHeight = transactionHeight;
}


