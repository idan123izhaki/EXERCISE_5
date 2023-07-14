#include <iostream>
#include <string>
#include "overDraftAccount.hpp"

OverDraftAccount::OverDraftAccount(std::string name, double max) : BankAccount(name), maxOverDraft(max) {}

double OverDraftAccount::getMax()
{
	return this->maxOverDraft;
}
double OverDraftAccount::withDraw(double withDraw)
{
	if (this->balance - withDraw >= this->maxOverDraft)
	{
		this->balance -= withDraw;
		return this->getBalance();
	}
	std::cout << "\nThe action was not approved. (OverDraftAccount class).\n" << std::endl;
	return -1;
}