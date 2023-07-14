#pragma once
#include "BankAccount.hpp"

class OverDraftAccount : public BankAccount
{
	double maxOverDraft;

public:
	OverDraftAccount(std::string, double);
	double getMax();
	double withDraw(double);
};