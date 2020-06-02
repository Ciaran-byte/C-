#include<iostream>
using namespace std;


//01 ֻ�ܷ���ͬ����ģ�������Ԫ
template<typename T>
class A
{
	friend bool operator==<T>(const A<T>&, const A<T>&);
public:
	A( T m) :_m(m){}
private:
	T _m;
};
template<typename T>
bool operator==(const A<T>& a1, const A<T>& a2)
{
	return a1._m == a2._m;
}

//02 �����ض�����Ϊ��Ԫ
template<typename T> class B1; //��Ҫǰ������
template<typename T> class B2
{
	friend class B1<int>; //ֻ��int���͵�B1��B2����Ԫ
};

//03 �����������Ͷ�����Ԫ
template<typename T> class C1
{
	template<typename T> friend class C2;//����Ҫǰ������������C2��ʵ�������Է���c1
};

//04 ��ģ���ඨ��Ϊ��Ԫ
template<typename T> class D1
{
	friend class D2; //����Ҫǰ������
};


int main()
{
	//01 ֻ�ܷ���ͬ����ģ�������Ԫ
	A<int> a(5);
	A<int> b(5);
	cout << operator==<int>(a, b) << endl;

	A<double> c(0.5);
	A<double> d(0.5);
	//cout << operator==<int>(c, d) << endl; //����ʹ��

	//02 ��ʵ����������������ԪȨ��
	

	return 0;
}

