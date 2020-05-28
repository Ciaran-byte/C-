#include<iostream>
#include<functional>
#include<map>
using namespace std;
int add(int a, int b) { return a + b; }
auto mod = [](int a, int b) {return a % b; };
class divide
{
public:
	int operator()(int denominator, int divisor)
	{
		return denominator / divisor;
	}
};
int main()
{
	//01 function���͵�ʹ�ã��Ǹ�ģ�����ͣ�ͨ�������б�ͷ���ֵ������������Ӧ�Ŀɵ��ö���
	function<int(int, int)> f1 = add;
	function<int(int, int)> f2 = mod;
	function<int(int, int)> f3 = divide();

	cout << f1(1, 2) << endl;
	cout << f2(4, 2) << endl;
	cout << f3(4, 2) << endl;

	int(*p)(int, int);
	p = add;
	//02 ʹ��map��function����ɵ��ö���ĺ�����
	map<string, function<int(int, int)>> binops =
	{
		{"+",add},
		{"-",minus<int>()},
		{"/",divide()},
		{"%",mod},
		{"+2edtion",p}
	};
	cout << endl;
	cout<<binops["+"](1, 2)<<endl;

	//03 �����ֺ�������ͬ�����غ���ʱ������ֱ����������������ƣ�Ӧ��ȡ��Ϊ����ָ��
		
	cout << binops["+2edtion"](3, 4) << endl;
	return 0;
}

