#include<iostream>
#include<memory>

using namespace std;
void test(shared_ptr<int> p)
{

}
int main()
{
	//01 ��������ָ������ַ���
	shared_ptr<int> p1(new int(42));//
	shared_ptr<int>q (make_shared<int>(5));
	
	//��������ָ��
	shared_ptr<int>p2 = p1;

	//02 ͨ��get��ȡ����ָ��ָ��Ķ���
	int* ptr = p1.get(); //ָ��̬�ڴ��ַ��ָ��
	cout << *ptr << endl;

	//03 get������Ҫע��ĵ�һ�㣬��Ҫʹ��delete�ͷ�getָ��ĵ�ַ����ʹ����ָ��ʧЧ
	//delete ptr;
	//cout << *p1 << endl;

	//04 get����ʹ��ע��ڶ��㣬����ʹ�����ָ�������ָ�븳ֵ����Ϊ�൱����������������ָ��ָ��һƬ�ڴ�ռ�
	//����û���ۼӹ�ϵ��������һ������ָ���뿪��������ڴ�ᱻ��գ�����һ��ָ��ָ��ͻ�ʧЧ

	{
		//shared_ptr<int> p3(ptr);  //ʹ��getָ�������ָ�븳���ֵ���뿪���������������ָ���ַ���ͷ�
	}
	//cout << *p1 << endl; //ԭ��������ָ��Ҳָ����Ƭ�ڴ棬������һ��������Ƭ�ڴ��ͷ�����

	shared_ptr<int> mm = make_shared<int>(5);
	mm.reset(new int(7));

	//05 ����get�������⣬ʹ��new�������ָͨ�벻Ҫ������ָ����ã�Ҳ���������04������
	int* x = new int(1024);
	{
		shared_ptr<int> pp(x);
	}

	//cout << *x << endl; //���ʱ���ڴ��ַҲ���ͷ��ˣ�������ʹ��x��

	//06 ʹ��new�����Ķ���������ָ��ĺ�������
	int* n1 = new int(5);

	//test(n1); //�﷨���󣬲��ܽ�int*����ָͨ��ת��Ϊ����ָ���������ֵ

	//test(new int());//�﷨����new int���������캯��

	test(shared_ptr<int>(n1)); //�﷨�ԣ������У������������ִ�������Ժ�n1ָ����ڴ汻�ͷ��ˣ��ڵ���n1��������ش���


	return 0;
}


