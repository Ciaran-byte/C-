#include<iostream>
using namespace std;

//01 ����ָ��Ķ����ʹ��
bool lengthCompare(const string& s1, const string& s2)
{
	return s1.size() == s2.size();
}
//02 ����ָ����Ϊ�����б�
//�ǵ�һ��Ҫʹ�����ţ���ʹ�����žͲ��Ǻ���ָ����
bool moreComepare(const string& s1, const string& s2, bool(*pf)(const string& s1, const string& s2))
{
	return (*pf)(s1, s2);
}

//03 ����ָ����Ϊ����ֵ
int F1(int num)
{
	return num;
}

int (*FFF(int i))(int num)  
{
	int (*q)(int num) = &F1;
	return q;
 }
//�������⿴������������ű�ʾ FFF��һ����������Ҫһ������Ϊi������ֵ�Ǹ�*��˵���Ǹ�ָ��
//���������ϸ�����������ָ��ָ�����һ����������������Ϊ int func(int num)

//04 ����ָ��ļ�

//04-2 ������Ϊ�����б�ļ�

//һ�ֱ�������
typedef bool(*DEF_B)(const string& s1, const string& s2); 
bool moreCompare2(const string& s1, const string& s2, DEF_B ptr2)
{
	return ptr2(s1, s2);
}

//���ֱ������巽��
typedef decltype(lengthCompare)* DEF_C;
bool moreCompare3(const string& s1, const string& s2, DEF_C ptr3)
{
	return ptr3(s1, s2);
}

//�����ֶ�������ķ���
using DEF_D = bool (*)(const string & s1, const string & s2);
bool moreCompare4(const string& s1, const string& s2, DEF_D ptr4)
{
	return ptr4(s1, s2);
}

//04-3 ������Ϊ�������͵�ʹ�ü�
//��һ�ַ���
typedef int(*F_A)(int num);
F_A FFF2(int i)
{
	F_A ptr1 = &F1;
	return ptr1;
}
//�ڶ��ַ���
typedef decltype(F1)* F_B;
F_B FFF3(int i)
{
	F_B ptr2 = &F1;
	return ptr2;
}
//�����ַ���
using F_C = int (*)(int num);
F_C FFF4(int i)
{
	F_C ptr3 = &F1;
	return ptr3;
}

//�����ַ��� ���˶���������⣬������ʹ��β�÷��ط���
auto FFF5(int i)->int(*)(int i)
{
	F_C ptr4 = &F1;
	return ptr4;
}

int main()
{
	//01 ����ָ��Ķ����ʹ��

	//����ָ��Ķ�������к���������ȫ��ͬ
	//01-1 ����ָ��Ķ���
	bool (*ptr)(const string & s1, const string & s2);

	//01-2 ����ָ��ĸ�ֵ
	//����������ָ������һ����ͨ��ȡ������ַ�Ϳ��ԶԺ���ָ����и�ֵ
	ptr = &lengthCompare;
	//������Ϊ������������Ա�����Ϊָ�룬����ȡ��ַ��Ҳ�ǿ��Ե�
	ptr = lengthCompare;

	//01-3 ����ָ���ʹ��
	cout << (*ptr)("hell0", "hi") << endl;
	cout << ptr("hell0", "hi") << endl; //��ʹ�ý����÷���Ҳ��
	cout << lengthCompare("hell0", "hi") << endl;//���Կ�������ԭ���ĺ���Ч����һ����

	//02 ����ָ����Ϊ�����б�
	//����ָ��Ҳ�ǿ��Ե��������б��
	//ʹ�õ�ʱ�򼴿��Դ��뺯��ָ�룬Ҳ���Դ���ԭ���ĺ���
	cout << endl;
	cout << moreComepare("123", "321", lengthCompare)<<endl;
	cout << moreComepare("123", "321", ptr) << endl;;


	//03 ����ָ����Ϊ����ֵ
	//����ָ��Ҳ���Ե�������ֵʹ�ã��������������ǳ����鷳
	cout << endl;
	cout << FFF(1)(5) << endl;
	//��һ������FFF(1)�ǵ����˺���FFF������ֵ��int fun(int num); 
	//����FFF��1����Ϊһ���������ͼ������ã�fun(5)������ֵ����5

	//04 ʹ�ñ����ķ����򻯺���ָ��
//����ͨ����������ķ�������Щ����

	//04-1 ����ָ���ʹ�ü�
	cout << endl;
	cout << "04-1" << endl;
	typedef bool(*DEF_A)(const string& s1, const string& s2);
	DEF_A ptr1; //DEF��һ������ָ��
	ptr1 = &lengthCompare; //���������ָ����и�ֵ
	cout<<ptr1("hi", "hello")<<endl; //ʹ���������ָ��
	//04-2 ������Ϊ�����б��ʹ�ü�
	cout << endl;
	cout << "04-2" << endl;
	cout << moreCompare2("123", "321", lengthCompare)<<endl;
	cout << moreCompare2("123", "321", ptr1)<<endl;
	cout << moreCompare3("123", "321", lengthCompare) << endl;
	cout << moreCompare4("123", "321", lengthCompare) << endl;

	//04-3 ������Ϊ�������͵�ʹ�ü�
	cout << endl;
	cout << "04-3" << endl;
	cout << FFF2(2)(5) << endl;
	cout << FFF3(2)(5) << endl;
	cout << FFF4(2)(5) << endl;
	cout << FFF5(2)(5) << endl;

	//05 ָ�����غ����ĺ���ָ��
	//ָ�����غ�����ָ��Ƚϼ򵥣����Ǻ���ָ����������һ�����غ�����ȫƥ�伴�ɣ����ﲻ��������

}