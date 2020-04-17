#include<iostream>
using namespace std;



//01�����������һ�¶Գ�Ա����ʹ��const��������ʲô
class myclass
{
public:
	myclass(int a):_a(a){}
	void display(int a) const //��ʾ
	{
		//_a++; ��仰�ᱨ����Ϊdisplay�����޸����Լ���ĳ�Ա����
		cout << _a << endl;
	}
private:
	int _a;
};

//02 ������������һ�£������ֱ���ں������޸ĳ�Ա����������һ����Ա������ָ��ĺ����ܷ�const
//������һ������A��������һ����Ա����_val
class TestA
{
public:
	TestA(int val):_val(val){}
	int _val;
};
//������һ������B��������һ��A���͵ĳ�Ա����
class TestB
{
public:
	TestB(TestA valA):_valA(valA){}

	//��������������ʹ��const�ؼ��ʻᱨ����Ϊ����ֵ�Ǹ����ã���Ȼ��������ֱ���޸ĳ�Ա���������ǿ���ͨ��
	//�����ݳ�ȥ�Ķ����޸ĳ�Ա������Ҳ�ǷǷ���
	/*TestA& val() const
	{
		return _valA;
	}*/

	TestA& val() 
	{
		return _valA;
	}

	void display()
	{
		cout << _valA._val << endl;
	}
private:
	TestA _valA;
};

//03 ���Ա����const�����Ե�����һ����������
class TestC
{
public:
	TestC(TestA valA) :_valA(valA) {}

	//��������д������val�������Ե�������ʹ��
	const TestA& val() const
	{
		return _valA;
	}

	TestA& val()
	{
		return _valA;
	}

	void display()
	{
		cout << _valA._val << endl;
	}
private:
	TestA _valA;
};

int main()
{

	//01 ��ʼ��
	//�½�һ��TestA���͵ı���ta
	TestA ta(5);

	//��ta����ʼ��TestB���͵ı���tb
	TestB tb(ta);
	//�鿴�޸�ǰ�Ľ���
	tb.display();

	//02 �޸�
	//TestA���͵����ð�tb�ĳ�Ա����
	TestA &changeTa = tb.val();

	//ʹ��changeTa�޸�tb�ĳ�Ա����
	changeTa._val = 10;

	//�鿴�޸ĺ�Ľ���
	tb.display();
	
	//03 const������Ϊ��������
	TestC tc(ta);
	tc.display();
	
	//����
	TestA& ta2=tc.val();
	const TestA& ta3 = tc.val();
	return 0;
}


