#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	//01 lambda�Ĳ���
	//01 -1 ֵ���Ͳ���
	//������ֵ��lambda������ʱ�򱻿���
	int sz = 42;
	auto f = [sz]() {return sz; };
	sz = 5;
	cout << f() << endl; //���Ƿ���lambda�����sz�Ƕ���ʱ���sz�������Ǻ������Ǹ���
	//���ԣ�lambda�����ֵ���͵ı��������ڲ���ʱ����Լ���ֵ��ת����ȥ��

	//01 -2 �������Ͳ���
	int sz2 = 42;
	auto f2 = [&sz2] {return sz2; };
	sz2 = 5;
	cout << f2() << endl;
	//�������õ�lambda��sz2��ֵ��������仯���仯
	

	//02 ��ʽ����
	//�����ñ������Լ��²���Ҫ������Щ����
	//02 -1 ��ʽֵ����
	int sz3 = 42;
	auto f3 = [=] {return sz3; };
	sz3 = 5;
	cout << f3() << endl;
	//02-2 ��ʽ���ò���
	int sz4 = 42;
	auto f4 = [&] {return sz4; };
	sz4 = 5;
	cout << f4() << endl;

	//02 -3 ��ϲ���
	vector<string> str = { "123","234","456" };
	char c = '\n';
	ostream& os = cout;
	for_each(str.begin(), str.end(), [](const string& str) {cout << str << endl; });//��д����İ汾
	cout << endl;
	for_each(str.begin(), str.end(), [=, &os](const string& str) {os << str << c; });//��һ�ֻ�ϲ���


	cout << endl;
	for_each(str.begin(), str.end(), [&, c](const string& str) {os << str << c; });//�ڶ��ֻ�ϲ���

	//03 �ɱ��lambad
	int v = 42;
	auto f5 = [v]()mutable {return ++v; };
	int v1=f5();
	int v2 = f5();
	int v3 = f5();
	cout << v1 << ends << v2 << ends<<v3<<ends << endl;
	



	return 0;
}

