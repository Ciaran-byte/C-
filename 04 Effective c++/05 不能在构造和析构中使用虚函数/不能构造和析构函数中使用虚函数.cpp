#include<iostream>
using namespace std;

//���ܹ�������������е����麯��
//01 ���캯���У������ഴ��֮ǰ����������Ƚ��д����������ڻ���Ĺ��캯���������麯����Ŀǰ�����������û�ж��壬
//�麯��ָ������ȷ��û�а취����������˻����ʧ��
//02 ���鹹�����У������ͷ�֮ǰ������������ͷţ��麯��Ҳ�����ָ������ȷ��������޷������롣
//����
class Transaction
{
public:
	Transaction();
	virtual void Log() = 0;

};

Transaction::Transaction()
{
	Log();
}


//������
class BuyTransaction:public Transaction
{
public:
	
	virtual void Log(){}

};


int main()
{
	BuyTransaction b; //��Ϊ����Ĺ��캯�����麯����ָ������ȷ���޷�����
	return 0;
}