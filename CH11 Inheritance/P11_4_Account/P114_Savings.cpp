#include "stdafx.h"
#include "P114_Savings.h"

Savings::Savings()
	:Account()
{

}

Savings::Savings(double initialBalance)
	:Account(initialBalance)
{

}

void Savings::daily_interest()
{
	Account::daily_interest(0.06);
}