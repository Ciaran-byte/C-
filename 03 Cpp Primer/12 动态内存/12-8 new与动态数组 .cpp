#include<iostream>
#include<memory>
using namespace std;
int main()
{
	//01 ��̬����Ķ������ʼ��
	int* p1 = new int[5]();
	int* p2 = new int[5];
	int* p3 = new int[5]{ 1,2,3,4 }; //û���ĵط������ֵ��ʼ�������0
	

	int* p4 = new int[0];  //�Ϸ��ģ����ǲ��ܽ��н�����

	//02 ��̬����ķ���
	for (int* q = p3; q != p3 + 5; q++)
	{
		cout << *q << endl;
	}
	
	//03 ��̬������ͷ�
	delete []p1;
	delete []p2;
	delete[]p3;
	delete[]p4;

	//04 ʹ������ָ�����̬����
	//unique_ptr�ܹ�ֱ�ӹ���̬���飬֧���±����
	cout << endl;
	unique_ptr<int[]> up(new int[10]);
	for (int i = 0; i < 10; i++)
	{
		up[i] = i;
		cout << up[i] << endl;
	}

	//ʹ��shared_ptr���붨���Լ���ɾ���������Ҳ�֧���±����
	cout << endl;
	shared_ptr<int> sp(new int[10], [](int* p) {delete[]p; });

	for (int i = 0; i < 10; i++)
	{
		*(sp.get() + i) = i;
		cout << *(sp.get() + i) << endl;
	}
	sp.reset();
	return 0;
}

