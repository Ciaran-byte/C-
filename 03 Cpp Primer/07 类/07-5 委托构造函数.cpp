#include<iostream>
using namespace std;


//01 ί�й��캯���Ķ��巽��
//��νί�й��캯��������ͨ��һ�����е������Ĺ��캯����ʵ���Լ��Ĺ���

class myClass
{
public:
	//��ί�й��캯��
	myClass(int a, int b, int c):_a(a),_b(b),_c(c){}


	//�����ί�й��캯����ͨ�����������Ĺ��캯��������Լ��Ĺ���
	myClass() :myClass(0, 0, 0){} 
	myClass(int a):myClass(a,0,0){} 

private:
	int _a;
	int _b;
	int _c;
};

//02 ί�й��캯����ִ��˳��
//��ʱ���캯���п��ܻ����������䣬��ô������һ����������һ�����캯���Ľṹ�У���������ִ��˳��������ô�����أ�
//���ǿ�����ʵ��һ��
class testClass
{
public:
	testClass(int a,int b,int c):_a(a),_b(b),_c(c)
	{
		cout << "��ί�й��캯��" << endl;
	}


	//ί�й��캯��
testClass():testClass(0, 1, 2)
{
	cout << "ί�й��캯��1" << endl;
}

testClass(int a) :testClass(a, 1, 2)
{
	cout << "ί�й��캯��2" << endl;
}


//�������ί�п�ֵ���캯�����й��죬����ֵ�Ĺ��캯����ί����ֵ�Ĺ��캯�������죬��˾��������ί�й�ϵ
testClass(istream& is) :testClass()
{
	cout << "ί�й��캯��3" << endl;
}
private:
	int _a;
	int _b;
	int _c;
};

int main()
{

	//01 ί�й��캯���Ķ���
	myClass cls;
	myClass cls2(1);
	myClass cls3(1, 2, 3);


	//02 ί�й��캯����ִ��˳��
	testClass ts(cin);
	//��������������������ֵ�Ĺ��캯��ִ�У�Ȼ���ǿ�ֵ���캯��ִ�У��������Լ�ִ��
	//���ԣ�ί�й��캯����ִ��˳���������ǴӶ����׵Ĵ���ִ�С���ִ�г�ʼ����ί�к�����Ȼ��ִ����ί�к���
	//���������ݣ�Ȼ���ٽ�����Ȩ����ί���ߡ�
	return 0;
}


