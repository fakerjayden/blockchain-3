#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include <vector>

class Transaction
{

	public:
		Transaction (double transactionSizeBytes);
		Transaction();
		virtual ~Transaction(void);

		double GetTransactionSizeBytes (void) const;
		void SetTransactionSizeBytes (double TransactionSizeBytes);

	private:
		double m_TransactionSizeBytes;

};

class BlockTransactions
{
	public:
		BlockTransactions (void);
		virtual ~BlockTransactions (void);

		void AddTransaction (const Transaction& newTransaction);

	private:
		std::vector<Transaction> m_Transactions; //vector of Transactions

};


#endif /*TRANSACTION_H */

