#include <iostream>
#include "TicketMachine.h"
using namespace std;
//definitions
//declaration's body

void TicketMachine::showPrompt()
{
	cout << "something";
}
void TicketMachine::insertMoney(int money)
{
	balance += money;
}
void TicketMachine::showBalance()
{
	cout << balance;
}
int TicketMachine::refundBalance()
{
	int amountToRefund; //本地变量local variables
	amountToRefund = balance;
	balance = 0;		//成员变量fields
	return amountToRefund;
}
void TicketMachine::initialization()
{
	balance = 20;
	money = 10;
}