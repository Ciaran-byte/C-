//�������ã�˵��new��delete���÷�


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
	A* a = new A[3];
	delete []a;  //��������������������3�Σ�ϵͳû�б���
	A* b = new A[3];
	delete b;//����������������������1�Σ�ͬʱ�����ڴ汻�ջأ���������������ڴ�����ͻ������
	return 0;
}

//ע��1 new��delete��ʹ��
//  new��delete��������c++��������������൱�������ڴ�ռ���ͷ��ڴ�ռ䡣nnew����һ��Ҫ���������͵ģ���Ϊ�����������������Ϊ���������ڴ�ռ��С
//����:    
//new int a;
//new my_calss a;
//new int a[];
//   delete��new�෴���������ͷſռ�ģ�����new�����ʱ���[]��delete�ͷŵ�ʱ��ҲӦ��д��������ţ���Ϊ���Ÿ��߱�����������ط�Ҫ�ͷźܶ��������
//���� 
// new myclass a[];
// delete []a;�õ��Ľ�����ջ��ڴ�ռ䣬��������������[]���������
// delete a; �õ��Ľ�����ջ��ڴ�ռ䣬������������ֻ�е�һ�����ݵõ��˵��ã���Ϊ��������Ϊ��deleteֻ��һ������
//
//ע��2 delete��ʹ�ý���:delete����������д�� delete a;��delete []a��
//��1����Ҫ�Բ���new�����Ŀռ�ʹ��delete
//��2����Ҫ��ͬһ���ռ�delete����
//��3��new��ʱ������ţ�delete��ʱ��һ��ҲҪ������