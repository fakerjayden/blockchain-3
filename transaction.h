#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <vector>
#include <string>

class Transaction
{

	public:
		Transaction (double transactionSizeBytes,int transactionHeight);
		Transaction();
		~Transaction(void);

		double GetTransactionSizeBytes (void) const;
		void SetTransactionSizeBytes (double TransactionSizeBytes);

		int GetTransactionHeight (void) const;
		void SetTransactionHeight (int transactionHeight);

	private:
		double m_transactionSizeBytes;
		int m_transactionHeight;

};

#endif /*TRANSACTION_H */

