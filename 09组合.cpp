//����������:�����������ϵ�ʾ������������Ϊ��ģ��������˻���Ǯ��ÿ��account������������������϶��ɵģ��ֱ������������˵���Ϣ��person��͹���Ǯ��balance��
//person�������һ���˵����ֺ����֤��
//balance��������˻�ʣ����
//account�������������ĺ����ͱ�����

#include<iostream>
#include<string>
using namespace std;



class person
{
private:
	string name;
	int ID;
public:
	person(string name, int ID) :name(name), ID(ID) {}  //ʹ�ó�ʼ���б�ķ���������ĳ�ʼ��������name��ID
	void print(void)
	{
		cout << "name=" << name << ",ID=" << ID << endl;
	}
};
class balance   //������������ʾ�˺�����balance�࣬�ܹ����ӽ�����ʾ��ǰ��Ҳ���ó�ʼ���б�ķ������г�ʼ���ġ�
{
private:
	int left;
	
public:
	balance(int left):left(left)
	{

	}
	void insert(int insertmoney)
	{
		this->left+= insertmoney;
	}
	void print()
	{
		cout << "left=" << left << endl;
	}
};
class account  //acount�����person���balance�����ϣ�����˶��ߵı����ͺ���
{
private:
	person p;
	balance my_balance;
public:
	account(string name, int ID, int left) :p(name, ID), my_balance(left) {}; //person���my_balance��ʼ���������Ӧ���������Լ��Ĺ��캯����ɣ��˴�Ҳ��һ�ֳ�ʼ���б��д��
	void print()
	{
		p.print();
		my_balance.print();

	}
	void insert(int insertmoney)
	{
		my_balance.insert(insertmoney);

	}
};
int main()
{

	account my_ac("realman", 123456, 133);
	my_ac.insert(100);
	my_ac.print();

	return 0;
}



//ע��1��������๹�ɵ�һ�ַ������൱������������������������Ķ��塣
//ע��2�������һ�����ã������Ǹ��������İ�����ϵ����Ϲ��ɵ��࣬�������������û������Ȩ��ֻ��һ���ⲿ���á���������������൱�ڰѸ��������еĶ�����ֱ�Ӹ��ƽ�������
//ע��3��������ⲿ���ã��̳����ڲ�������