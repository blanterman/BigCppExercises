/*	Exercise P12.14. A bank keeps all bank accounts in a random access file in 
which each line has the format

account_number balance

Wirte a program that simulates an automatic teller machine. A user can deposit 
money to an account by specifying the account number and amount, withdraw money,
query the account balance, or transfer money from one account to another.

Bryson Lanterman 20200306

This program is pretty bad, with a lot of duplicate code, but when I am just 
trying to get through and use the skills that are being focused on, I just
wanted to get it working. I like how this works overall.

The necessary file is bankroll.dat or any bankroll.dat file where each line 
has an account and where the first 30 characters are devoted to the account
number and the last 10 characters of the line are devoted to the account
balance.
*/
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

#include "Account.h"

const int NEWLINE_LENGTH = 2; /* or 1 on Unix */
const int RECORD_SIZE = 30 + 10 + NEWLINE_LENGTH;

/**
	Converts a string to a floating-point value, e.g.,
	"3.14" -> 3.14.
	@param s a string representing a floating-point value
	@return the equivalent floating-point value
*/
double string_to_double(std::string s)
{
	std::istringstream instr(s);
	double x;
	instr >> x;
	return x;
}

/**
	Raises or lowers an accounts balance.
	@param a account with transaction
	@param amount the amount by which to change the balance
*/
void change_amount(Account& a, double amount)
{
	double new_balance = a.get_balance() + amount;
	a.set_balance(new_balance);
}

/**
	Reads an account record from a file.
	@param a filled with the account
	@param in the stream to read from
*/
void read_account(Account& a, std::istream& in)
{
	std::string line;
	getline(in, line);
	if (in.fail()) return;
	std::string number = line.substr(0, 30);
	double balance = string_to_double(line.substr(30, 10));
	a = Account(number, balance);
}

/**
	Writes an account record to a stream.
	@param a the account record to write
	@param out the stream to write to
*/
void write_account(Account a, std::ostream& out)
{
	out << a.get_number() << setw(10 + (30 - a.get_number().length()))
		<< fixed << setprecision(2)
		<< a.get_balance()
		<< "\n";
}

int main()
{
	std::string filename = "bankroll.dat";
	std::fstream fs;
	fs.open(filename.c_str());
	fs.seekg(0, ios::end); /* go to end of file */
	int nrecord = fs.tellg() / RECORD_SIZE; /* Number of Records */

	int option = 0;
	Account current_account;
	Account current_trans_account;
	Account a;
	int current_record = -1;
	int current_trans_record;
	std::string choice;

	std::cout << "Please enter the account number: ";
	std::string account_num;
	std::getline(std::cin, account_num);

	while (account_num.size() < 30)
	{
		account_num += " ";
	}
	for (int i = 0; i < nrecord; i++) /* Go through all records */
	{
		fs.seekg(i * RECORD_SIZE, ios::beg);
		read_account(a, fs);
		if (a.get_number() == account_num)
		{
			current_account = a;
			std::cout << "Account number " << current_account.get_number().substr(0,8) 
				<< " successfully found. " << "\n\n";
			current_record = i;
			break;
		}
	}
	if (current_record == -1)
	{
		std::cout << "Could not find account.\n\n";
		return 0;
	}

	while(true)
	{
		if (option == 1) // Option 1 is making a withdrawl 
		{
			double amount = 0;
			std::string line;
			std::cout << "How much are you withdrawing?\n";
			std::getline(cin, line);
			amount = string_to_double(line);
			if (amount > 0 && amount < current_account.get_balance())
			{
				change_amount(current_account, -amount);
				fs.seekp(current_record * RECORD_SIZE, std::ios::beg);
				write_account(current_account, fs);
				std::cout << "$" << amount << " successfully withdrawn from account number "
					<< current_account.get_number().substr(0,8) << ".\nNew balance is: $"
					<< fixed << setprecision(2)
					<< current_account.get_balance() << "\n\n";
			}
			else
			{
				std::cout << "Can not withdraw that amount.\n\n";
			}
		}

		if (option == 2) // Option 2 is making a deposit
		{
			double amount = 0;
			std::string line;
			std::cout << "How much are you depositing?\n";
			std::getline(cin, line);
			amount = string_to_double(line);
			if (amount > 0)
			{
				change_amount(current_account, amount);
				fs.seekp(current_record * RECORD_SIZE, std::ios::beg);
				write_account(current_account, fs);
				std::cout << "$" << amount << " successfully deposited into account number "
					<< current_account.get_number().substr(0,8) << ".\nNew balance is: $"
					<< fixed << setprecision(2)
					<< current_account.get_balance() << "\n\n";
			}
			else
			{
				std::cout << "Can not deposit that amount.\n\n";
			}
		}

		if (option == 3) // Option 3 is displaying account balance
		{
			std::cout << "Balance for account " << current_account.get_number().substr(0,8) << "\n"
				<< fixed << setprecision(2)	
				<< "$" << current_account.get_balance() << "\n\n";
		}

		if (option == 4) // Option 4 is switching accounts
		{
			std::cout << "Please enter the account number: ";
			std::string account_num;
			std::getline(std::cin, account_num);

			while (account_num.size() < 30)
			{
				account_num += " ";
			}
			current_record = -1;
			for (int i = 0; i < nrecord; i++)
			{
				fs.seekg(i * RECORD_SIZE, ios::beg);
				read_account(a, fs);
				if (a.get_number() == account_num)
				{
					current_account = a;
					std::cout << "Account number " << current_account.get_number().substr(0,8) 
							<< " successfully found. " << "\n\n";
					current_record = i;
					break;
				}
			}
			if (current_record == -1)
			{
				std::cout << "Could not find account.\n\n";
			}
		}

		if (option == 5) // Option 5 is transferring money to another account
		{
			std::cout << "Please enter the account number to transfer to: ";
			std::string trans_account_num;
			std::getline(std::cin, trans_account_num);

			while (trans_account_num.size() < 30)
			{
				trans_account_num += " ";
			}
			current_trans_record = -1;
			for (int i = 0; i < nrecord; i++)
			{
				fs.seekg(i * RECORD_SIZE, ios::beg);
				read_account(a, fs);
				if (a.get_number() == trans_account_num)
				{
					current_trans_account = a;
					std::cout << "Account number " << current_trans_account.get_number().substr(0,8) 
							<< " successfully found. Ready for transfer." << "\n\n";
					current_trans_record = i;
					break;
				}
			}
			if (current_trans_record == -1)
			{
				std::cout << "Could not find account for transfer.\n\n";
			}
			else
			{
				double amount = 0;
				std::string line;
				std::cout << "How much are you transferring?\n";
				std::getline(cin, line);
				amount = string_to_double(line);
				if (amount > 0 && amount <= current_account.get_balance())
				{
					change_amount(current_account, -amount);
					change_amount(current_trans_account, amount);
					fs.seekp(current_record * RECORD_SIZE, std::ios::beg);
					write_account(current_account, fs);
					fs.seekp(current_trans_record * RECORD_SIZE, std::ios::beg);
					write_account(current_trans_account, fs);
					std::cout << "$" << amount << " transfer successfull. \n"
						<< "New balance for account " << current_account.get_number().substr(0,8)
						<< " is: " << fixed << setprecision(2) << current_account.get_balance() 
						<< "\nNew balance for account " << current_trans_account.get_number().substr(0,8)
						<< " is: " << current_trans_account.get_balance() 
						<< "\n\n";
				}
				else
				{
					std::cout << "Can not deposit that amount.\n\n";
				}
			}
		}

		std::cout << "What would you like to do now? Please please choose from list.\n"
			<< "(1) Make a withdrawl \n"
			<< "(2) Make a deposit. \n"
			<< "(3) Display your balance. \n"
			<< "(4) Switch Accounts. \n"
			<< "(5) Make a balance transfer to another account. \n"
			<< "(99) quit.\n\n";

		std::getline(std::cin, choice);
		option = std::stoi(choice);

		if (option == 99)
		{
			return 0;
		}
		
	}
	fs.close();
	return 0;
}