#include<iostream>
using namespace std;
int main()
{
	//01 ����
	//�޶��������ö��
	enum class color {red,yellow,blue};


	//���޶��������ö��
	enum ppers{red,yellow,blue};


	//02 ʹ��
	//���õ�ʱ��������������
	color eye = color::red;
	ppers pp = red;


	//03 ȡֵ
	int a = ppers::red; //���޶��������ö�ٿ����Զ�ת����int
	//int m = color::red; //�޶����������͵�ö�ٲ����Զ�ת��Ϊint

	



	return 0;
}


