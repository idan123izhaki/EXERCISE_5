#pragma once
#include <string>

class BankAccount
{
protected:
	std::string name;
	double balance = 0;

public:
	BankAccount(std::string name = "");
	std::string getName();
	double getBalance();
	virtual double withDraw(double);
	void deposit(double);
};