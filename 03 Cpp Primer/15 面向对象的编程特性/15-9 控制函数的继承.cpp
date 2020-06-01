#include<iostream>
using namespace std;
//���ƺ���������û������غ�����ʵ��
class A
{
public:
	A(int a) :a(a) { cout << "A�Ĺ��죡" << endl; }
	A(const A& A1)
	{
		cout << "A�Ŀ������죡" << endl;
		a = A1.a;
	}
	A(A&& A1)noexcept
	{
		cout << "A���ƶ����죡" << endl;
		a = A1.a;
	}
	A& operator=(const A& A1)
	{
		cout << "A�Ŀ�����ֵ��" << endl;
		a = A1.a;
		return *this;
	}
	virtual ~A() { cout << "A������" << endl; }
private:
	int a;
};

class B:public A
{
public:
	B(int a, int b) :A(a), b(b) { cout << "B�Ĺ���" << endl; }
	
	B(const B& B1) :A(B1)
	{
		cout << "B�������죡" << endl;
		b = B1.b;
	}
	B(B&& B1)noexcept :A(move(B1))
	{
		cout << "B�ƶ�����" << endl;
		b = B1.b;
		
	}
	B& operator=(const B& rhs)
	{
		cout << "B������ֵ" << endl;
		A::operator=(rhs);
		b = rhs.b;
		return *this;
	}
	virtual ~B() { cout << "B������" << endl; }

private:
	int b;
};
int main()
{
	B b(1, 2);
	B c = b;
	B d(b);
	d = c;

	

	return 0;
}

