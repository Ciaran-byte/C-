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

double Account::_interest = 0.015;  //因为_interest是私有的，所以不能直接使用，但是在初始化阶段，可以直接使用。
int main()
{
	Account a("张三", 1000);
	Account b("李四", 2000);

	a.deposit(1000);
	b.deposit(2000);

	cout<<a.getmoney()<<endl;
	cout << b.getmoney() << endl;
	
}

