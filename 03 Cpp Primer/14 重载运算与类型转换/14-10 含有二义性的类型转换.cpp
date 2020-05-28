#include<iostream>
using namespace std;
class B;
class A
{
public:
	friend class B;
	A(int a):_a(a){}
	A(const B& b); 
private:
	int _a;
};

class B
{
public:
	friend class A;
	B(int b):_b(b){}
	operator A()const { return A(_b); }
private:
	int _b;
};
A::A(const B& b) { _a = b._b; }
A f(const A& a)
{
	return a;
}

class C
{
public:
	C(int a) :_a(a) { cout << "int" << endl; }
	C(double a) :_a(a) { cout << "double" << endl; }

	operator int() { return _a; }
	operator double() { return _a * 1.0; }
private:
	double _a;
};
void f2(long double m)
{

}
int main()
{
	
	//01 ��һ�ֶ����������������ͬ����ͬʱ������ͬһ������ת��
	B b(6);
	//A a = f(b); //��bת��Ϊa������;����һ����A�Ĺ��캯����һ����B������ת�����������ߵ�ͬ�����ϵͳ��֪���õ���˭��
	A m = f(A(b)); //���ⷽ������ȷʹ�õ����ĸ���������A�Ĺ��캯��������B������ת������
	A n = f(b.operator A());

	//02 ��������ת��
	//������c��֧������int��double�������͵����룬�����ܹ�ת��Ϊint��double����ô
	long db = 10;
	//C c(db);  //�����ڶ����ԣ�����ж�������ܹ��ɹ�ƥ�䣬����������û�����ŵ�
	//f2(c);
	return 0;
}

