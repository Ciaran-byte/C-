#include<iostream>
using namespace std;
class Account
{
public:
	Account(const string& name, double money) :_name(name), _money(money){}

	void deposit(double money)
	{
		_money += money;
	}

	static double rate() { return _interest; }
	static void rate(double interest) { _interest = interest; }

	double getmoney() { return _money += _money * _interest; }
	
private:
	string _name;
	double _money;
	static double _interest;
	
	
};

double Account::_interest = 0.015;  //��Ϊ_interest��˽�еģ����Բ���ֱ��ʹ�ã������ڳ�ʼ���׶Σ�����ֱ��ʹ�á�
int main()
{
	Account a("����", 1000);
	Account b("����", 2000);

	a.deposit(1000);
	b.deposit(2000);

	cout<<a.getmoney()<<endl;
	cout << b.getmoney() << endl;
	
}

