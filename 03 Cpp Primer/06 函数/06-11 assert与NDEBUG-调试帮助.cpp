#include<iostream>
#include<cassert>
//d#define NDEBUG
using namespace std;


//02 NDEBUG
void f()
{
#ifndef  NDEBUG
	cout << __func__ << endl;
#endif // ! NDEBUF

}

//03 Ԥ����ĵ��Գ���ľֲ���̬����
void ff(int i)
{
	if (i == 1)
	{
		cout << "ERROR:" << __FILE__ << " in function" << __func__ << "at line" << __LINE__
			<< "	compile on " << __DATE__ << " at " << __TIME__ << endl;
	}

}
int main()
{
	//01 assert
	//��1��assertλ��ͷ�ļ�cassert��
	//��2��assert��һ���꣬��Ԥ�������������Ǳ���������
	//��3��assert(expr) exprt����Ϊ��ʱ�������������ڼ�ⲻ���Է���������

	string s;
	cin >> s;
	assert(s!="");

	//02 NDEBUG
	//(1)NDEBUG��һ���꣬����������ʱ��assert��ʲôҲ�����������ײ⣬�����assertû�а�ëǮӰ��
	//(2)NDEBUG���������������룬���粻�������������ʱ�������Թ��ܣ��������������ʱ�򣬵������Ͳ�������
	
	
	f();//������������


	//03 Ԥ����ĵ��Գ���ľֲ�����
	ff(1);


	

	return 0;
}


