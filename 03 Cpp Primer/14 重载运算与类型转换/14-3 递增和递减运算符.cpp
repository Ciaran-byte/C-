#include<iostream>
using namespace std;
class mycls
{
public:
	mycls() = default;
	mycls(int a):_a(a){}
	//ǰ�ð汾�����ظı�����ı����_a++��Ȼ�󷵻ض���
	mycls& operator++()
	{
		_a++;
		return *this;
	}

	//���ð취����++ǰ��״̬�����Ԥ�ȱ���*this�����ݣ����ظı�ǰ������

	mycls operator++(int)
	{
		mycls ret = *this;
		++* this;
		return ret;
	}

	int _a;
};
int main()
{
	mycls m1(6);
	mycls m2 = m1++;
	cout << m2._a << endl;
	cout << m1._a << endl;

	cout << endl;

	mycls ma(6);
	mycls mb = ++ma;
	cout << mb._a << endl;
	cout << ma._a << endl;

	
	return 0;
}

