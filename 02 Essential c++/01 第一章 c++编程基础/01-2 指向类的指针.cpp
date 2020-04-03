#include<iostream>
#include<vector>
using namespace std;
int main()
{
	//01判断vector是否非空，并且判断第2个参数是否为2
	vector<int> m = { 1,2,3,4 };
	bool rst;
	if (!m.empty() && m[1] == 2)
	{
		rst = true;
	}
	else
	{
		rst = false;
	}

	cout << rst << endl;

	//02 指向类的指针实现上面一个过程
	vector<int>* p = &m;
	
	//访问成员变量的方法
	bool emp = p->empty();
	cout << emp << endl;
	//访问下标的方法
	cout << (*p)[2] << endl;

	
	//注意事项：使用指针，一定要判断指针是否为非空，使用短路运算实现这一过程即可
	//最终写法如下：
	bool rst2;
	if (p && !p->empty() && (*p)[1] == 2)
	{
		rst2 = true;
	}
	else
	{
		rst2 = false;
	}
	cout << rst2 << endl;
	return 0;
}
