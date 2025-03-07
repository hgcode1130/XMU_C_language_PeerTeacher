#include "TicketMachine.h"

int main()
{
	TicketMachine tm;
	tm.initialization();
	tm.insertMoney(100);
	tm.showBalance();

	return 0;
}