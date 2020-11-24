#include<iostream>
using namespace std;


//01 typename两重性：用于定义template需要一个类型，用于表明嵌套从属的名称
template<typename T>
void print2nd(const T& container)
{
	if (constainer.size() > 2)
	{
		//T::const_iterator iter(container.begin());//这行不能编译成功，因为我们并不知道T::const_iterator 是个变量还是个类型
		typename T::const_iterator iter(container.begin()); //只有前面加了typename以后，才能确定是个类型不是变量名
		++iter;
		int value = *iter;
		cout << value;
	}
}
//02 typename不用于表明嵌套从属名称的特例--继承的基类名前和initialization list中不能使用


int main()
{

	return 0;
}

