#include<iostream>
#include<memory>
using namespace std;
int main()
{
	//01 weak_ptr����
	//weak_ptrҲ��shared_ptrһ��������˹���̬�ڴ棬���ǣ�����ʹshared_ptr��cout���ӡ�
	//��countΪ0ʱ����ʹ����weak_ptrָ���ڴ棬�ڴ���Ȼ�ᱻ�ͷ�

	//02 weak_ptr�Ķ���
	//ʹ��shared_ptr������г�ʼ��

	shared_ptr<int> sp = make_shared<int>(1);
	weak_ptr<int>wp(sp);

	//03 weak_ptr��ʹ��
	//����weak_ptr���ڴ治һ���Ǵ��ڵģ���˲���ֱ�ӷ������ָ�룬Ҫͨ��shared_ptr������
	//lock�������countΪ0�����ؿ�����ָ�룻���count��Ϊ0������shared_ptr

	shared_ptr<int> sp2 = wp.lock();
	cout << *sp2 << endl;
	cout << sp2.use_count() << endl;

	//Ҳ����д��if�н���
	if (shared_ptr<int> sp3 = wp.lock())
	{
		cout << *sp3 << endl;
	}

	int* p = sp2.get();


	return 0;
}

