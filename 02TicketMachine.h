#pragma once
#ifndef TicketMachine_H_
#define TicketMachine_H_

class TicketMachine
{
private:
	int price;
	int balance;
	int left;
public:
	TicketMachine(int b);
	void showprompt(void);
	void insertmoney(int money);
	void showbalance(void);
	void printticket(void);



};

#endif