#include<iostream>
using namespace std;
int main()
{
	int i;
	int sum = 0;
	while (cin >> i, !cin.eof())  //使用了逗号标志符，右边那个条件作为循环的标志条件
	{
		if (cin.bad())//遇到系统级错误，我们无能为力，只能抛出异常
			throw runtime_error("system is bad");
		if (cin.fail())
		{
			cerr << "你输入有问题，输入一个有效数字" << endl;
			cin.clear();//清除当前错误的标志位
			cin.ignore(200,'\n');//清理cin流中的200个字母，如果遇到换行符就提前终止清除数据
			continue;
		}
		sum += i;
		cout << "sum is " << sum << endl;
	}

	return 0;
}

