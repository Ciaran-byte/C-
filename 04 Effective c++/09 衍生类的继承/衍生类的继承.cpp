#include<iostream>
using namespace std;
//01 B��˵�����̳��У������ͬ�������Ḳ�Ǹ��ຯ��
//02 C��˵����ʹ��using�����Կ���A�е�ͬ�����������¹�������
//03 D��˵����ͨ��private�̳У�����ת�������ķ���A::f1()������ʵ��ֻ���ظ����в��ֺ���
class A
{
public:
	void f1() { cout << "A::f1" << endl; }
	void f1(int x) { cout << "A::f1" << endl; }
	void f1(string x) { cout << "A::f1" << endl; }
	void f2() { cout << "A::f2" << endl; }
	
private:

};
class B:public A
{
public:
	void f1(int x) { cout << "B::f1" << endl; }
};

class C:public A
{
public:
	using A::f1;
	void f1(int x) { cout << "C::f1" << endl; }
};


class D :private A
{
public:
	void f1(int x) { cout << "D::f1" << endl; }
	void f1() { A::f1(); }
};
int main()
{
	B b;
	//b.f1(); //��������ͬ��������������
	b.f1(5);
	b.f2();
	cout << endl;

	C c;
	c.f1(); //c���Ե��ã���Ϊͨ��using��䣬ʹ��A�е�����f1���ɼ���
	c.f1(5);
	c.f1("12");
	c.f2();
	cout << endl;

	D d;
	d.f1();
	d.f1(5);
	//d.f1(("12"); //���ܵ��ã���Ϊͨ��private�̳У�A�еĺ��������ܼ̳У�ͨ��ת�������ķ���������ʵ��ֻ�̳в���A�еĺ���
	return 0;
}

