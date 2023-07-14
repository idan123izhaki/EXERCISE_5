#include <iostream>
#include <vector>
#include "bankAccount.hpp"
#include "limitedBankAccount.hpp"
#include "overDraftAccount.hpp"

int main()
{
	int option;
	double limit, maxOverDraft, temp, val;
	bool flag = false, loopFlag = true;
	std::string name;
	std::vector<BankAccount*> bankSystem;
	BankAccount* ptrAccount = nullptr;
	while (loopFlag)
	{
		std::cout << "Welcome to MagshiBank,\n1 to add new account\n2 to make \
transaction from existing account\n3 to list all accounts, type and \
balance\n4 to exit" << std::endl;
		std::cout << "Your choise: ";
		std::cin >> option;
		switch (option)
		{
		case 1:
			if (bankSystem.size() >= 5)
				std::cout << "\nThere are 20 accounts in the bank. The bank is full.\nPlease try another option.\n" << std::endl;
			else
			{
				std::cout << "\nWhich type of account do you want to create?\n1 to regular bank account\n2 to limited account\n3 to over draft account\nYour choise: ";
				std::cin >> option;
				std::cout << "\nPlease enter the name of the account owner: "; std::cin >> name;
				switch (option)
				{
				case 1:
					ptrAccount = new BankAccount(name);
					bankSystem.push_back(ptrAccount);
					std::cout << "Your bank account has been successfully added to the system.\n" << std::endl;
					break;
				case 2:
					std::cout << "\nPlease enter your withdraw limit: "; std::cin >> limit;
					ptrAccount = new LimitedBankAccount(name, limit);
					bankSystem.push_back(ptrAccount);
					std::cout << "\nYour bank account has been successfully added to the system.\n" << std::endl;
					break;
				case 3:
					std::cout << "\nPlease type your max over draft limit: "; std::cin >> maxOverDraft;
					ptrAccount = new OverDraftAccount(name, maxOverDraft);
					bankSystem.push_back(ptrAccount);
					std::cout << "\nYour bank account has been successfully added to the system.\n" << std::endl;
					break;
				default:
					std::cout << "\nInvalid input, please start from the beginning." << std::endl;
					break;
				}
			}
			break;

		case 2:
			std::cout << "What is the name of the account owner you want to access? "; std::cin >> name;
			for (auto ptr : bankSystem)
			{
				ptrAccount = ptr;
				if (ptr->getName() == name)
				{
					flag = true;
					ptrAccount = ptr;
					break;
				}
			}
			if (flag)
			{
				std::cout << "\nWelcome " << name << "!\n1 to deposit money\n2 to withdraw money\n3 to show current balance\n4 back to main menu\nYour choise: ";
				std::cin >> option;
				switch (option)
				{
				case 1:
					std::cout << "\nHow much money would you like to deposit? "; std::cin >> temp;
					ptrAccount->deposit(temp);
					std::cout << "\nThe deposit was made successfully.\n" << std::endl;
					break;
				case 2:
					std::cout << "\nHow much money would you like to withdraw? "; std::cin >> temp;
					val = ptrAccount->withDraw(temp);
					if (val != -1) std::cout << "The withdraw was made successfully.\n" << std::endl;
					break;
				case 3:
					std::cout << "\nYour current balance is: " << ptrAccount->getBalance() << std::endl << std::endl;
					break;
				case 4:
					std::cout << "\nReturns to the main menu.\n" << std::endl;
					break;
				default:
					std::cout << "\nInvalid input, please start from the beginning.\n" << std::endl;
					break;
				}
			}
			else
				std::cout << "\nNo Such Account.Please try again.\n" << std::endl;
			break;

		case 3:
			if (bankSystem.empty())
				std::cout << "The bank is empty...\nPlease try another option.\n";
			else
			{
				std::cout << "\nPrinting all existing bank accounts in the system:\n" << std::endl;
				for (auto ptr : bankSystem)
				{
					std::cout << "Name of the account owner: " << ptr->getName() << std::endl;
					std::cout << "Account type: " << typeid(*ptr).name() << "." << std::endl;
					std::cout << "The account balance is: " << ptr->getBalance() << "." << std::endl << std::endl;
				}
			}
			break;

		case 4:
			std::cout << "\n\nYou have successfully logged out.\nhave a nice day!\n" << std::endl;
			loopFlag = false;
			break;

		default:
			std::cout << "\nInvalid input... Please try again!." << std::endl;
			break;
		}
	}

	for (auto ptr : bankSystem)
		delete ptr;
	bankSystem.clear();
	return 0;
}
