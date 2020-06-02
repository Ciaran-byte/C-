#include<iostream>
#include<vector>
using namespace std;

class DebugDelete
{
public:
	DebugDelete(ostream&s = cerr):os(s){}
	template<typename T>
	void operator()(T* p)const
	{
		os << "deleting unique_ptr" << endl;
		delete p;
	}
private:
	ostream& os;
};


//02 ģ���ຬ��ģ��ĳ�Ա����
template<typename T>
class A
{
public:
	template<typename LT>
	void fun(T a, LT b);
	
private:
	T _a;
};

//��Աģ����������ж���

//��Ϊ�漰������ģ���������Ҫд��������ģ�������ǰ��������ģ������ں�
template<typename T>
template<typename LT>
void A<T> ::fun(T a, LT b)
{
	cout << a << " " << b << endl;
}
int main()
{
	//01 ��ͨ���к���ģ��
	double* p = new double;
	DebugDelete d;
	d(p);

	unique_ptr<int, DebugDelete> q(new int, DebugDelete());

	////02 ģ�����к���ģ�庯��
	A<int> a;
	a.fun<double>(1, 2.5);

	return 0;
}

