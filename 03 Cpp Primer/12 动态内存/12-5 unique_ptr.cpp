#include<iostream>
#include<memory>
using namespace std;
unique_ptr<int> fun()
{
	return unique_ptr<int>(new int(5));
}
unique_ptr<int> fun2()
{
	unique_ptr<int>ret(new int(5));
	return ret;
}
int main()
{
	//01 unique_ptr�Ļ���ʹ��
	//���巽��,ֻ��ͨ��new�����Ҳ��ܿ���
	unique_ptr<int> p(new int(5));

	//02 ����ָ����ƽ�
	//����ͨ��ʹ��release��reset�����ƽ�ָ�����Ȩ��ע�⣬release�������˽�������ڴ棬����ͳ����ڴ�й¶
	unique_ptr<int> p2(p.release());
	//ָ�����Ȩ��p����p2��p�����

	unique_ptr<int> p3(new int(6));
	p3.reset(p2.release());
	//����Ȩ��p2����p3��p2���

	//���û������ָ���������ڴ棬����ͨ����ָͨ����ܣ�������delete
	auto p4 = p3.release();
	delete p4;

	//03 unique_ptr���ں�������
	//unique_ptr��Ȼ����ֱ�ӿ������������ǿ���ͨ������һ���������ͷŵĶ���ʵ�ֿ��������������
	//�纯��fun��fun2��Ҫô������ʱ����Ҫô���ؾֲ�����

	//04 ����ɾ����
	


	return 0;
}