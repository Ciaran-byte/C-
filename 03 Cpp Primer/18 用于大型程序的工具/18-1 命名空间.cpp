#include<iostream>
using namespace std;
namespace my
{
	class myclass
	{
	public:
	private:
	};
}

namespace you
{
	class myclass
	{
	public:
	private:
		int i;
	};
}
namespace my
{
	void f()
	{
		cout << "f" << endl;
	}
}
int main()
{
	//01 ÿһ�������ռ䶼��һ��������ͬ���������������λ�ڲ�ͬ�����ռ���
	my::myclass mcls;
	you::myclass ycls;
	//02 �����ռ���Բ�����
	my::f();


	return 0;
}





