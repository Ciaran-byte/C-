#include<iostream>
#include<vector>
using namespace std;

//01 ����ֵΪvoid������return���
void swap(int& a, int& b)
{
	if (a == b)
		return;
	int swap;
	swap = a;
	a = b;
	b = swap;
}
//02 �����ں����б�ͷ���ֵʱ��ľ���
int add_one1(int a)
{
	a++;
	return a;
}
int add_one2(int &a)
{
	a++;
	return a;
}

int& add_one3(int& a)
{
	a++;
	return a;
}

//03 ǧ���ܷ��ؾֲ����������
int& test()
{
	int a=10;
	return a;
}

//04 ����ֵΪ��ֵ
char& get_val(string& str, size_t index)
{
	return str[index - 1];
}
//05 ����ֵ�ǳ�ʼ���б�
vector<string> ff(int a, int b)
{
	if (a == b)
		return { "1","2","3" };
	else
		return { "1","2" };

}
int main()
{
	//01 ����ֵΪvoid������return ���
	//���ڷ���ֵΪvoid�ĺ�����˵����βĬ��������һ��return;�����Ҫ��ǰ���ؾͰ���仰д����
	//���罻������
	int a = 10, b = 5;
	cout << "����ǰ" << "a= " << a << ",b= " << b << endl;
	swap(a, b);
	cout << "������" << "a= " << a << ",b= " << b << endl;

	//02 �����ں����б�ͷ���ֵʱ��ľ���
	//������һ��add_one�ĺ������ڸ�����+1���ᶨ��������

	//02-1 �����б�ͷ���ֵ��������������
	cout << endl;
	int A1 = 0;
	int B1= 1;
	add_one1(A1);
	cout << "�����A! "<<A1 << endl; //������������a��û�ı䣬˵�������ڲ�������������ֵ�ĸ���

	//02-2 �����б����������ͣ�����ֵ������������
	cout << endl;
	int A2 = 0;
	int B2 = 1;
	B2=add_one2(A2);
	cout << "�����A! " << A2 << endl;
	cout << "�����B! " << B2 << endl;
	B2++;
	cout << "�����A! " << A2 << endl;
	cout << "�����B! " << B2 << endl;
	//�ӽ��������������A2������+1����B2++���A2û��Ӱ�죬˵������ֵ��������ֵ�ĸ��ƣ�����������
	//�Ѷ��������ȥ��

	//02-3 �����б�ͷ���ֵ������������
	cout << endl;
	int A3 = 0;
	int& B3 = add_one3(A3);
	cout << "�����A! " << A3 << endl;
	cout << "�����B! " << B3 << endl;
	B3++;
	cout << "�����A! " << A3 << endl;
	cout << "�����B! " << B3 << endl;
	//�ӽ��������������A3������+1����B3++��A3Ҳ++��˵������ֵ�Ͳ����б���������Ĵ��ݣ�������ֵ���ݡ�

	//03 ǧ���ܷ��ؾֲ����������
	//int& Test = test();
	//���ص������Ǹ��ֲ����󣬻�����

	//cout << Test << endl;
	//���Ƶģ����ؾֲ���ָ��Ҳ�ǿ϶������Ե�


	//04 ������ֵ,һ����ͨ������ֵΪ���õĺ���ʵ�ֵ�
	string str = "helo";
	get_val(str, 2) = 'i'; //��Ϊ����ֵ�����ã����Ժ�����������ֵ
	cout << str << endl;

	//05 ����ֵ�ǳ�ʼ���б�
	vector<string> s = ff(1, 2);

	return 0;
}

