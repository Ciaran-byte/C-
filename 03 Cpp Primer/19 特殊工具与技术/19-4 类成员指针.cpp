#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
class A
{
public:
	int a;
	int b = 1;
	void f()
	{
		cout << 1 << endl;
	}
	int A::* ff()
	{
		return &A::b;
	}
};

class B
{
public:
	void B1()
	{
		cout << "B1" << endl;
	}
	void B2()
	{
		cout << "B2" << endl;
	}
	void B3()
	{
		cout << "B3" << endl;
	}
	enum element { b1, b2, b3 };

	void move(element a)
	{
		(this->*Menu[a])();
	}

	using Action =void (B::*)();
private:
	static Action Menu[];
	


};
B::Action B::Menu[] = { &B::B1,&B::B2,&B::B3 };
int main()
{
	
	//01 ָ�����Ա��ָ�붨��
	//ָ�����Ա������ָ��
	int A::* p = &A::a;


	//ָ�����Ա������ָ��
	void(A:: * q)() = &A::f;


	//02 ָ�����Ա��ָ���ʹ��
	A a;
	int m = a.*p;

	(a.*q)();

	//03 �������ݳ�Աָ��ĺ���
	int A::* pp = a.ff();
	cout << a.*pp << endl;

	//04 ����ָ���
	B b;
	b.move(B::b1);


	//05 ��Ա������Ϊ�ɵ��ö���
	vector<string> str;
	
	string s = "123";
	str.push_back(s);
	str.push_back("");
	str.push_back("12344");

	//����str�е�һ���յ��ַ���


	function<bool(const string&)> fp = &string::empty;
	find_if(str.begin(), str.end(), fp);


	
	
	return 0;
}

