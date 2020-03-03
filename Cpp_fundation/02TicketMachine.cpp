#include "02TicketMachine.h"
#include <iostream>

using namespace std;

void TicketMachine::showprompt(void)
{
	cout << "something"<<endl;

}

void TicketMachine::insertmoney(int money)
{
	balance+=money;


}
void TicketMachine::showbalance(void)
{
	cout<< balance;
}
void TicketMachine::printticket(void)
{

}
TicketMachine::TicketMachine(int b)
{
	TicketMachine::balance = b;
}
