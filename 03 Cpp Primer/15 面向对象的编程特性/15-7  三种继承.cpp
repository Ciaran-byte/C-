#include<iostream>
using namespace std;
class A
{
public:
	int a = 1;
protected:
	int b = 2;
private:
	int c = 3;

};
//01 public�̳�
class B1 :public A
{
	void f()
	{
		cout << a << endl;
		cout << b << endl;
		//cout << c << endl; //���ɷ���
	}
};
class B2 :public B1
{
public:
	void f()
	{
		cout << a << endl;
		cout << b << endl;
		//cout << c << endl; //���ɷ���
	}
};

//02 protected�̳�
class C1 : protected A
{
public:
	void f()
	{
		cout << a << endl;
		cout << b << endl;
		//cout << c << endl; //���ɷ���
	}
};
class C2 :public C1
{
public:
	void f()
	{
		//C1�е�a��b��protected�ģ�c��private��
		cout << a << endl;
		cout << b << endl;
		//cout << c << endl; //���ɷ���
	}
};

//03 private�̳�
class D1 :private A
{
public:
	void f()
	{
		cout << a << endl;
		cout << b << endl;
		//cout << c << endl; //���ɷ���
	}
};

class D2 :public D1
{
public:
	void f()
	{
		//ȫ�����ɷ��ʣ�D1�е�a��b��c����private��
		//cout << a << endl;
		//cout << b << endl;
		//cout << c << endl; //���ɷ���
	}
};
class E :private A
{
	
public:
	using A::a;
private:
	
};
int main()
{
	//01 ��������Դӻ��������ַ�ʽ���м̳У��ֱ���public��private��protected
	//public �̳�
	//public�̳���ζ�ţ�B1���м̳е�A����󣬱���ԭʼ���ʼ���
	//�ȼ��� a��b��c��Ȼ�ֱ�Ϊpublic��protected��privated
	
	//01-1 B1���û��ķ���Ȩ��
	A a;
	cout << a.a << endl;
	//cout << a.b << endl;
	//cout << a.c << endl;
	//�û����ܷ���˽�к��ܱ����Ķ���
	B1 b;
	cout << b.a << endl;
	// b�̳е�a��b��c����һ���ķ���Ȩ�ޣ����ܵ���b.b��b.c

	//01-2 B1��������B2�ķ���Ȩ��
	B2 bb;
	bb.f();// B2���Է���B1��a��b����Ϊ��public��protected�����ܷ���c


	//02 protected �̳�
	//protected�̳��൱�ڸ���protected�����public����Ȩ�ޱ�Ϊprotected
	//Ҳ���Ǽ̳���A��a��b��c����C1�б����protected,protected��private
	C1 c;
	//��Ϊ����C1��public��a�����protected�����c1�������û����ܷ��ʣ�����C1��������C2���ԣ���Ϊ��protected��
	//cout << c.a << endl;
	//cout<<c.b<<endl;
	//cout<<c.c<<endl;
	c.f();

	//03 private�̳�
	//�൱��D1�е�a��b��c����ת������private��
	D1 d;
	//ʲô����Ҳ����ʹ��,���ʼ�����private

	//04 ȥ�������Ա
	//��E��private����ʽ�̳�A������ϣ������a����public��
	E e;
	cout << e.a << endl; //Ҫ��public������using��������
	return 0;
}

