#include<iostream>
using namespace std;

void check()
{
	if (cin.bad())
	{
		cout << "cin is bad!" << endl;
	}
	else
	{ 
		cout << "cin is not bad" << endl;
	}
		

	if (cin.fail())
	{
		cout << "cin is fail!" << endl;
	}
		
	else
	{
		cout << "cin is not fail!" << endl;
	}
		

	if (cin.eof())
		cout << "cin is eof" << endl;
	else
		cout << "cin is not eof" << endl;
	cout << endl;
}
int main()
{

	int i;
	cin >> i;

	//01 设置条件状态位

	//cin.setstate(istream::badbit);
	cin.setstate(istream::failbit);
	//这两个条件状态设置可以只有一个，也可以两个同时存在.当bad标志位被置位时，fail返回值也会变成true

	//cin.setstate(istream::failbit| istream::badbit);
	check();

	//02 清除异常状态
	//cin.clear(); //清理全部状态
	//cin.clear(cin.rdstate()&~cin.badbit);
	cin.clear(cin.rdstate() & ~cin.failbit); //清除fail标志位
	
	check();
	//03 异常条件状态的保存与恢复
	cout << "设置" << endl;
	cin.setstate(istream::failbit | istream::badbit);
	check();
	cout << "保存状态" << endl;
	istream::iostate state = cin.rdstate();
	cout << "删除状态" << endl;
	cin.clear();
	check();
	cout << "恢复状态" << endl;
	cin.setstate(state);
	check();

	return 0;
}


