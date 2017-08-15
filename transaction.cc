#include <iostream>
#include <vector>
#include <string>
#include "transaction.h"


/**
 * Class Transaction functions
 * */

Transaction::Transaction(double transactionSizeBytes, std::string transactionMessage, int transactionHeight ) : m_transactionSizeBytes(transactionSizeBytes), m_transactionMessage(transactionMessage), m_transactionHeight(transactionHeight) { std::cout<<"First constructor, no delegation yet"<<"\n";} 
//{
//	m_transactionSizeBytes = transactionSizeBytes;
//	m_transactionMessage = transactionMessage;
//	m_transactionHeight = transactionHeight;
//}

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

std::string
Transaction::GetTransactionMessage (void) const
{
	return m_transactionMessage;
}

	void
Transaction::SetTransactionMessage (std::string transactionMessage)
{
	m_transactionMessage = transactionMessage;
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


