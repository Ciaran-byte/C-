#include<iostream>
#include<memory>
using namespace std;
int main()
{
	//01 ����ָ��Ķ������ʼ��
	shared_ptr<int> p1;   //Ĭ�ϳ�ʼ�����޶���
	//shared_ptr<int> p2();//ֵ��ʼ��
	shared_ptr<int> p3(make_shared<int>(1)); //ʹ��make_shared�������г�ʼ��
	shared_ptr<int> p4 = make_shared<int>(1); //�������������������Ĭ�ϳ�ʼ����������ʱ������ָ�����ֵ��p5
	shared_ptr<int> p5(new int(6));  //ʹ��new����Ϊ�������г�ʼ�����������ֵĹ��캯����explicit��
	cout << *p5 << endl;
	//02 ����ָ��ĸ�����ֵ
	shared_ptr<int> p6;
	p6 = p5; //��p5�����ڴ�
	p6 = make_shared<int>(7); //�������²����ڴ�
	p6.reset(new int(5));  //�������²����ڴ�

	
	
	//03 ����ָ���޸�ֵʱҪע��һ��
	//��������һ��ֵ��Ҫ���ж�һ���Ƿ���unique�ǣ�������ǣ�����һ���ٸ�
	if (!p6.unique())
	{
		p6.reset(new int(*p6));  //���·����ڴ��ַ���и�ֵ
	}
	else
	{
		(*p6)++;//�����ֻ����һ����ֱ���޸ľ���
	}

	//04 ��������ָ�붯̬�ڴ��ַ��ɾ��
	//����countֵΪ0��ʱ���Զ��ͷ�

	
	return 0;
}

