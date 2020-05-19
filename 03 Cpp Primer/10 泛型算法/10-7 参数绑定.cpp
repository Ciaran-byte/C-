#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;
using namespace placeholders;

bool check_size(const string& str, string::size_type sz)
{
	return str.size() > sz;
}

void print(int a, int b, int c, int d,int e)
{
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;
	cout << "d: " << d << endl;
	cout << "e: " << e << endl;
}
void fun(ostream& os, int a)
{
	os << a << endl;
}
int main()
{
	//01 ��ʱ��ʹ��ν�ʣ���Ҫ�ṩһԪν�ʣ�����find_if������ʱ�����Ǻ�ϣ�������������֣������������5�����֣����5
	//����Ǹ������ͺ��ˡ����Գ����˲��������ַ������ܹ�ͨ��ռλ�ķ������̶�һ��ֵ���Ӷ��Ѷ�Ԫν�ʱ��һԪν��

	//01-1 bind������ʹ�÷���
	//bind�����ܹ�ʵ�ֲ����󶨣��﷨ auto f = bind(funtion,arg_list);
	//bind��������������ģ�bind(��������ռλ�����̶�ֵ);ռλ����ʾ�����еĵڼ���λ��Ҫ����������̶�ֵ����������̶�λ�õ�ֵ
	auto check6 = bind(check_size, _1, 6);
	bool a = check6("hellssssssss0!");
	cout << a << endl;

	//01-2����Ӧ��
	vector<string> s = { "1233333","22222","sadfadf","Qwe" };
	auto iter=find_if(s.begin(), s.end(), bind(check_size, _1, 6));
	cout << *iter << endl;

	//02 bind�����Ĳ���

	//���ʹ��bind�������ɵĺ������󣬴���ֵ��ʱ���ռλ����λ���й�ϵ������
	int a1 = 1;
	int b2 = 2;
	auto f = bind(print, a1, b2, _3, _2, _1);
	f(5, 6, 7);
	//����Ĳ����ᰴ��ռλ����˳�����뺯��������5���뵽ռλ��_3,����print����������;
	// 6���뵽ռλ��_2����Ӧ��print�ĵ��ĸ�����;7���뵽ռλ��_1����Ӧ��print�ĵ��������

	//03 ������������
	//ͨ������ref����ʵ�ִ�����������

	auto ff = bind(fun, ref(cout), _1);
	ff(5);
	//����fun������һ��������һ��ostream��ֻ��ͨ�����ô�����ֵ�����Ծ�ʹ��ref��������cout��Ϊ���ô���
	

	//04 ������

	//bind1st��bind2nd



	return 0;

}

