#include<iostream>
#include<memory>
using namespace std;

class FOO
{
public:
	int f1()&
	{
		cout << "��ֵ����ʹ��" << endl;
		return 1;
	}
	int  f1()&&
	{
		cout << "��ֵ����ʹ��" << endl;
		return 2;
	}
private:
};
int main()
{
	FOO i;
	i.f1();
	int a = FOO().f1();

	

	return 0;
}

