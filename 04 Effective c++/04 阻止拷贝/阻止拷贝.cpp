#include<iostream>
using namespace std;


//01 ʹ�ðѿ�������Ϳ�����ֵ����Ϊ˽�к���������ֻ������ʵ�ֵķ�������ֹ��A�Ŀ���
class A
{
public:
	A(){}
	~A() {}
private:
	A(const A&);
	A& operator=(const A&);
};

//02 ͨ�����岻�ɸ��ƵĻ��࣬���ҽ��м̳�

class BaseB
{
protected:
	BaseB(){}
	~BaseB(){}
private:

	BaseB(const BaseB&);
	BaseB& operator=(const BaseB&);
};


class B : private BaseB
{

};

//03 ͨ��delete�ؼ���ʵ��

class C
{
public:
	C(){}
	~C() {	}
	C(const C&) = delete;
	C& operator=(const C&)=delete;
};
int main()
{

	//01 ��һ
	A a;
	//A b = a;
	//A b(a);

	//02 ����
	B b;
	//B m = b;
	//B m(b);

	//03 ����
	C c;
	//C m = c;
	//C n(c);


}