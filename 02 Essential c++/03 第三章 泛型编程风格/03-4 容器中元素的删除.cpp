#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
int main()
{
	list<int> ilist = { 1,2,3,4,5,6 };
	
	//01 第一种删除的方法-按位置删除
	list<int>::iterator it = find(ilist.begin(), ilist.end(), 5);
	ilist.erase(it);

	//02 删除一组
	list<int>::iterator begin = find(ilist.begin(), ilist.end(), 2);
	list<int>::iterator end = find(ilist.begin(), ilist.end(), 4);
	ilist.erase(begin, end);
	//最后应该剩下1,4,6因为删左不删右，右边的边界4是被保留下来的
	begin = ilist.begin();
	end = ilist.end();
	for (; begin != end; begin++)
	{
		cout << *(begin) << endl;
	}

	//注意，由于list是一种双向链表的容器，不支持偏移运算，使用+修改地址是非法的
	


	return 0;
}

