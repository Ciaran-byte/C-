#include<iostream>
using namespace  std;

class myClass
{
public:
	myClass(void) {}
	//01 ��ָ����ĳ�Ա������ָ����м�
	typedef void (myClass::* Ptr)(void);
	//02 ���������뺯��ָ�������ͬ���͵ĺ���
	void print1()
	{
		cout << "1" << endl;
	}
	void print2()
	{
		cout << "2" << endl;
	}
	//03 ���ڵ��ú���ָ��
	void print(int num)
	{
		if (num == 1)
		{
			 p = &myClass::print1;
		}
		else
		{
			p = &myClass::print2;
		}
		(*this.*p)();

	}
	Ptr p;
private:
	
};
//��ΪPtrֻ�������ܱ��ҵ���ʹ��ʱ����Ҫ����������ţ�Ϊ�˼�㣬Ϊ�䶨�����

typedef myClass::Ptr Ptr;
int main()
{
	//���ڵ��ú���ָ�����
	myClass cs1;
	cs1.print(1);

	//05 �������ú���ָ��
	myClass cs2;
	Ptr q=&myClass::print2;
	(cs2.*q)();
	//�ȼ��� cs2.print2();

	//06 ָ�����ָ�����ָ����ĳ�Ա��������
	myClass* cs3=&cs2;
	Ptr m = &myClass::print1;
	(cs3->*m)();
	//�ȼ��� cs3->print1();

}