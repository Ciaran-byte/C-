#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

//01 �޿�������
void f(ifstream fs)
{
	cout << "hell0" << endl;
}

void ff(ifstream& fs)
{
	cout << "hell0" << endl;
}


//�ᱨ��
//ostream fff(ostream& os)
//{
//	return os;
//}


ostream& ffff(ostream& os)
{
	return os;
}


int main()
{
	//01 �޿�������
	//�޿�����ָ��IO��ֱ�Ӳ���ֱ�Ӹ��ƣ�������Ϊ����ֵ���ߺ��������б�

	//01-1��֧��ֱ�ӿ���
	ifstream s1, s2;
	//s1 = s2;  //���� ��֧�ֿ���

	//01-2 ��֧��ֱ����Ϊ�����б��ݣ����Ҫ���б���ʹ��ָ�������������
	//f(s1);
	ff(s1);

	//01-3 ��֧��ֱ����Ϊ����ֵ�����Ҫʹ�ÿ���ʹ����������
	ffff(cout)<<"123";

	//02 ���ü̳нṹ������ʹ�ö�̬�����ԣ�ʹ�û�����Ϊ�����б��ṩ��������չ�ԡ�
	return 0;
}

