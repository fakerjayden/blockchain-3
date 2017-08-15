#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <vector>
#include <string>

class Transaction
{

	public:
		Transaction (double transactionSizeBytes, std::string transactionMessage, int transactionHeight);
		Transaction();
		~Transaction(void);

		double GetTransactionSizeBytes (void) const;
		void SetTransactionSizeBytes (double TransactionSizeBytes);

		std::string GetTransactionMessage (void) const;
		void SetTransactionMessage (std::string transationMessage);

		int GetTransactionHeight (void) const;
		void SetTransactionHeight (int transactionHeight);

	private:
		double m_transactionSizeBytes;
		int m_transactionHeight;
		std::string m_transactionMessage;

};

#endif /*TRANSACTION_H */

