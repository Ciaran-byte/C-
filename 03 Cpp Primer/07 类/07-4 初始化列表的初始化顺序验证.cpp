#include<iostream>
using namespace std;
class x
{
public:
	x(int val) :j(val), i(j)
	{

	}
	void print()
	{
		cout << 1 << endl;
		cout << i << endl;
		cout<<j << endl;
	}
private:
	int i; 
	int j;
};
int main()
{
	//��ʼ��˳�����ж����˳����У�Ҳ�����ȶ�i�����ʼֵ�����ǣ�j��ʱû�ж��壬����iʵ����û�ж���
	x m(5);
	m.print();
	return 0;
}

