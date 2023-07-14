#include <iostream>
#include "LimitedBankAccount.hpp"

LimitedBankAccount::LimitedBankAccount(std::string name, double limit) : BankAccount(name)
{
	this->limit = limit;
}

void LimitedBankAccount::setLimit(double newLimit)
{
	this->limit = newLimit;
}

double LimitedBankAccount::getLimit()
{
	return this->limit;
}

double LimitedBankAccount::withDraw(double withDraw)
{
	if (withDraw <= this->balance && withDraw <= limit)
	{
		this->balance -= withDraw;
		return this->getBalance();
	}
	std::cout << "\nThe action was not approved. (LimitedBankAccount class).\n" << std::endl;
	return -1;
}
