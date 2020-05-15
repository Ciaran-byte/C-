#include<iostream>
#include<forward_list>
using namespace std;
void fun(forward_list<string>& fl,const string& s1, const string& s2)
{
	auto before = fl.before_begin();
	auto begin = fl.begin();
	auto end = fl.end();

	while (begin != end)
	{
		if ((*begin) == s1)
		{
			fl.insert_after(begin, s2);
			return;
		}
		before = begin;
		begin++;
	}
	fl.insert_after(before, s2);
}
int main()
{

	//01 前向列表的删除
	//forward_lst插入和删除与别的容器不一样，删除命令删除的是下一个元素，要实现这一点，就必须要保存删除元素
	//前面那个元素的迭代器。为了适应这个需要，forward_list类型的容器也有一个before_begin 的首前指针函数
	
	forward_list<int> flt = { 1,2,3,4,5,6,7,8,9 };
	auto bf_flt = flt.before_begin();
	auto begin = flt.begin();
	auto end = flt.end();

		while (begin != end)
		{
			if ((*begin) % 2 == 0)
				begin=flt.erase_after(bf_flt); //删除命令是删除送入元素的下一个元素，返回被删除元素的下一个元素的迭代器
			else
			{
				bf_flt = begin;
				begin++;

			}
		}

		//02 前向列表的插入
		forward_list<string> fl = { "hell0","hi","how are you" };
		fun(fl, "hi", "ok");
		fun(fl, "wow", "but");
		for (auto i : fl)
		{
			cout << i << endl;
		}
	
	return 0;
}

