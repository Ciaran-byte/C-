#include<iostream>
using namespace std;

//01 mutableʹ�ó�����A����һ����Ա�����ܹ��޸�A�ĳ�Ա����
//01-1
//������A
class A
{
public:
	A(int val):_val(val),outTime(0){}
	void display(void)
	{
		cout << _val << endl;
		outTime++;
		cout << outTime << endl;
	}


private:
	int outTime;
	int _val;
};
//���崫��ֵΪcosnt&�ĺ���

void funA(const A& a)
{
	//a.display(); //�ᱨ����Ϊdisplay���޸����еı�������¼����Ĵ���
}

//01-2
//������B
class B
{
public:
	B(int val) :_val(val), outTime(0) {}
	void display(void) const
	{
		cout << _val << endl;
		outTime++;
		cout << outTime << endl;
	}


private:
	mutable int outTime;
	int _val;
};
//���崫��ֵΪcosnt&�ĺ���

void funB(const B& b)
{
	b.display(); //�����display�ĳ�const�ģ�funB���ܹ�����display��������
	//ͬʱ����display�޸ĵĲ������mutable�ģ�˵�����ֵ���޸Ķ���B������Ӱ�죬�ǿ����޸ĵ�
}
int main()
{
	


	return 0;
}

