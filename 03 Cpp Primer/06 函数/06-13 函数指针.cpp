#include<iostream>
using namespace std;

//01 ����ָ��Ķ��巽��
bool (*p) (const string& str1, const string& str2); //����Ҫ�����ţ���Ȼ�ͳ��˷���ֵΪbool*�ĺ���
bool compare(const string& str1, const string& str2)
{
	return str1.size() > str2.size() ? true : false;
}

//04 ���غ����ĺ���ָ��
void pp(int) { cout << "int" << endl; }
void pp(double) { cout << "double" << endl; }

//05 ����ָ����Ϊ�����Ĳ����б�
//����ط����Բ�д*������ʽת��Ϊָ��
void func(bool(*p)(const string& str1, const string& str2))
{
	cout<<p("hell0", "hi")<<endl;

}

//06 ʹ�ñ����򻯺����Ĳ����б�
typedef bool (FUNC1)(const string& str1, const string& str2);  //����һ���������͵ı���
typedef decltype(compare) FUNC2;  //����һ���������͵ı���
void funcA(FUNC1* q)//
{
	cout << q("hell0", "hi") << endl;

}


void funcB(FUNC2 *q)
{
	cout << q("hell0", "hi") << endl;

}
//07 ���غ���ָ��
using FUN3 = bool (*)(const string & str1, const string & str2);//FUNC3�Ǻ���ָ�����͵ı���
using FUN4 = bool (const string & str1, const string & str2);//FUNC4�Ǻ������͵ı���
FUN3 funC(FUN3 q)
{
	return q;
}
FUN4* funD(FUN4* q)
{
	return q;
}

//08 ʹ��β�÷�������
auto funE(int)->bool (*)(const string& str1, const string& str2);
int main()
{
	//02 ����ָ�븳ֵ
	//���ͱ�����ȫƥ�䣬����������ת��
	p = compare;
	//p = &compare; //����д������

	//03 ����ָ���ʹ��
	bool a=p("hell0", "h1");
	//bool b = (*p)("hell0", "h1"); //�Ƿ�Ժ���ָ��ʹ�ý����þ���

	//04 ���غ����ĺ���ָ��
	//����������һ��������ȫƥ��
	void (*ptr)(int);
	ptr = pp;

	//05 ����ָ����Ϊ�����б�
	func(compare);
	//���԰Ѻ�����ֱ����Ϊʵ�δ��룬ʵ�ʴ��ݵ���ָ������

	//06 ʹ�ñ����򻯺���ָ������
	//typedef bool (FUNC1)(const string& str1, const string& str2);  //����һ���������͵ı���
	//typedef decltype(compare) FUNC2;  //����һ���������͵ı���
	

	return  0;

}

