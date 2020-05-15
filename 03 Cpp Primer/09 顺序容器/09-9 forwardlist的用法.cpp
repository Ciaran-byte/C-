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

	//01 ǰ���б��ɾ��
	//forward_lst�����ɾ������������һ����ɾ������ɾ��������һ��Ԫ�أ�Ҫʵ����һ�㣬�ͱ���Ҫ����ɾ��Ԫ��
	//ǰ���Ǹ�Ԫ�صĵ�������Ϊ����Ӧ�����Ҫ��forward_list���͵�����Ҳ��һ��before_begin ����ǰָ�뺯��
	
	forward_list<int> flt = { 1,2,3,4,5,6,7,8,9 };
	auto bf_flt = flt.before_begin();
	auto begin = flt.begin();
	auto end = flt.end();

		while (begin != end)
		{
			if ((*begin) % 2 == 0)
				begin=flt.erase_after(bf_flt); //ɾ��������ɾ������Ԫ�ص���һ��Ԫ�أ����ر�ɾ��Ԫ�ص���һ��Ԫ�صĵ�����
			else
			{
				bf_flt = begin;
				begin++;

			}
		}

		//02 ǰ���б�Ĳ���
		forward_list<string> fl = { "hell0","hi","how are you" };
		fun(fl, "hi", "ok");
		fun(fl, "wow", "but");
		for (auto i : fl)
		{
			cout << i << endl;
		}
	
	return 0;
}

