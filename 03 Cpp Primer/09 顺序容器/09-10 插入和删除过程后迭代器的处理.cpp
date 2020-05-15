#include<iostream>
#include<vector>
#include<list>
using namespace std;

int main()
{
	//由于插入或者删除容器中原有的数据之后，迭代器结构会改变，所以这个时候如果以迭代器为循环依据的话，需要修改一些东西

	//比如有这样一个例子，希望在vector容器中删除所有的偶数，并且复制所有的奇数，怎么做呢？

	//let’s get start it
	vector<int> vec = { 1,2,3,4,5,6,7,8,9,10 };

	auto it = vec.begin();
	while (it != vec.end())//首先注意循环的条件，插入或者删除元素后尾后迭代器会发生改变，所有尾后指针不能用一个
							//变量来保存这个值，必须要每次都更新
	{
		if ((*it) % 2 != 0)
		{
			it = vec.insert(it, *it);//复制自身，并且插入。但是返回的迭代器是插入变量的前一个位置，
									//如果想让循环继续，就要把迭代器往后移动两位
			it ++;
			it++;
		}
		else
		{
			it = vec.erase(it); //删除就直接保存迭代器位置就好了，因为返回的是删除变量的后面那个值
		}
	}

	for (auto i : vec)
	{
		cout << i << endl;
	}
	return 0;
}

