
//�����ܣ��������ڳ�ʼ����ʱ�򱻹������뿪�������ʱ���ͷ�
#include<iostream>
using namespace std;

class A
{
private:
	int size;
public:
	A();
	~A();
	void print_size(int a);
};

A::A()
{
	cout << "���ǹ��캯��contributor" << endl;
}


A::~A()
{
	cout << "������������decontributor" << endl;
}

void A::print_size(int a)
{
	size = a;
	cout << "size = " << size << endl;
}



int main()
{
	cout << "��������֮ǰ" << endl;
	{
     //���ű�ʾ��������򣬳�������֮�����û����
		A a;
		a.print_size(10);


	}
	cout << "��������֮��" << endl;
	return 0;
}






// ���캯���ڶ��󱻴�����ʱ����ã�û�з������ͣ����ǿ��Ծ��в�������������ǰ���и����˺�~,�ڶ����ͷŵ�ʱ����ã�û�з������ͣ�ͬʱҲ�������д��������
//���г���֮�󣬿��Է��֣����˴�������A��ʵ��a�뿪�������򣬴�������������