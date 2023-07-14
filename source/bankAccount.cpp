#include<iostream>
#include "bankAccount.hpp";

BankAccount::BankAccount(std::string name) : name(name){}

std::string BankAccount::getName()
{
	return this -> name;
}

double BankAccount::getBalance()
{
	return this->balance;
}

double BankAccount::withDraw(double withDraw)
{
	if (withDraw <= this->balance)
	{
		this->balance -= withDraw;
		return this->getBalance();
	}
	std::cout << "\nThe action was not approved. You reach a negative balance (BankAccount class).\n" << std::endl;
	return -1;
}

void BankAccount::deposit(double deposit)
{
	this->balance += deposit;
}