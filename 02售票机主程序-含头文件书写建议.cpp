
//�����ܣ�˵������Ļ���ʹ�÷�������������Ʊ�����������̣���ʼ��һ����Ʊ���Ķ���tm����ʾһЩ���ݣ�Ȼ���������ʾ��

#include<iostream>
#include "02TicketMachine.h"
using namespace std;
int main()
{
	TicketMachine tm(0);
	
	tm.showprompt();
	int a = 10;
	tm.insertmoney(a);
	tm.showbalance();

	return 0;
}
//ͷ�ļ�ʹ�ý���
//(1)ÿ���඼ʹ��һ��������ͷ�ļ����
//��2����������д��ͬ����cpp�ļ���
//(3)Ӧ��ʹ����������ķ�������ͷ�ļ����Է��ظ���������⡣