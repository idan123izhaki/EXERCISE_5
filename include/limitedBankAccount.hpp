# include "bankAccount.hpp"
#pragma once
class LimitedBankAccount : public BankAccount
{
	double limit;
public:
	LimitedBankAccount(std::string, double);
	void setLimit(double);
	double getLimit();
	double withDraw(double);
};