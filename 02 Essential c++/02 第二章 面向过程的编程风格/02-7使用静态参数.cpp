#include<iostream>
#include<vector>
using namespace std;


bool FibnoPrint(int index);


int main()
{

	//问题：斐波那契数列打印中，返回的vector变量十分相近，如果提高程序效率

	//01 法一，把vector做在file scope中 缺点：局限性太大
	//02 法二，使用局部静态变量的方法,这样每次都只需要计算多出来的长度部分即可。
	while (1)
	{
		cout << "打印多长的数列" << endl;
		int index;
		cin >> index;
		if(FibnoPrint(index));
		else
		{
			cerr << "输入数据有误" << endl;
		}
	}
	

}


bool FibnoPrint(int index)
{

	static vector<int> fib;

	const int max_num = 1024;
	if (index <= 0 || index >= max_num)
	{
		
		return false;
	}
	
		for (int i = fib.size(); i < index; i++)
		{
			if (i == 0 || i == 1)fib.push_back(1);
			else fib.push_back(fib[i - 1] + fib[i - 2]);
		}

	
	for (int i = 0; i < index; i++)
	{
		cout << fib[i] << endl;
	}
	return true;
}

