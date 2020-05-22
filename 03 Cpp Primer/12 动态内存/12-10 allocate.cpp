#include<iostream>
#include<memory>
#include<vector>
using namespace std;
int main()
{
	////01 ����
	 
	//01-1 �����ڴ�ռ�������
	allocator<int> a; //���ڷ���int�ڴ�ռ�Ķ���

	//01-2 �����ڴ���� 
	int* p = a.allocate(10);

	//01-3 �ͷ��ڴ����
	a.deallocate(p, 10);
	   
	//02 ʹ����ϸ����
	
	//02-1 �����ڴ�������
	allocator<string> a2;
	//02-2 �����ڴ�ռ�
	string* str = a2.allocate(10);
	//02-3 �������
	string* q = str;

	a2.construct(q++, "hello"); //����str���׵�ַ�������׵�ַд��hello���ڴ������ƶ�һ��
	a2.construct(q++, 5, 'c'); //�ڶ����ڴ�λ��д��5��c���ڴ��ַ���������ƶ�һλ

	//02-4 ʹ�����˶���֮��Ҫ�Ѷ��������
	while (q != str)
	{
		a2.destroy(--q);//����qָ���ж������ڴ�ĺ�һλ
	}

	//02-5 ���¿��������ͷ��ڴ��ַ
	a2.deallocate(str, 10);


	//03 ���������δ��ʼ���ڴ���㷨
	///����- ��vector��Ԫ�ؿ�������̬�����У�Ȼ��ʣ�¿ռ��ö�ֵ���
	vector<int> vec = { 1,2,3,4 };
	allocator<int> all;
	int* my_p = all.allocate(vec.size() * 2);
	auto my_q=uninitialized_copy(vec.begin(), vec.end(), my_p);//����vec�е�Ԫ�ص���̬������
	uninitialized_fill_n(my_q, vec.size(), 42);

	int* out = my_p;
	for (int i = 0; i < vec.size() * 2; i++)
	{
		cout << *(out + i) << endl;
		all.destroy(out + i);
	}
	all.deallocate(my_p, vec.size() * 2);

	return 0;
}

