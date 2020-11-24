#include<iostream>
using namespace std;
class base
{
public:
	virtual void out()
	{
		cout << "base" << endl;
	}
	virtual ~base(){}

};

class A:public base
{
public:
	virtual void out()
	{
		cout << "A" << endl;
	}
	virtual ~A(){}
};
int main()
{
	//��static_cast��dynamic_cast���Ա�
	//01 ����ȫ�����������У�dynamic���ؿ�ָ�룬��staticʵ���ˣ����Ǹ��಻�ܵ��������ػ��Ķ���
	base b;
	A a;
	base* p = &b;
	A* pa = dynamic_cast<A*>(p);
	cout << (pa == nullptr) << endl;
	
	A* pa1 = static_cast<A*>(p);
	cout << (pa1 == nullptr) << endl;

	//02 ��������
	A* p2 = &a;
	base* pb = dynamic_cast<base*>(p2);
	cout << (pb == nullptr) << endl;

	base* pb2 = static_cast<base*>(p2);
	cout << (pb2 == nullptr) << endl;
	return 0;
}




