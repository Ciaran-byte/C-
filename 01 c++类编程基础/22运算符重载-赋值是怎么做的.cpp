#include<iostream>
#include<cstring>
#include<string>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;
class A
{
public:
	int i;
	A(int ii):i(ii){}
	const A& operator =(const A &that)  //����ʵ���Ͼ��ǳ���ָ��  const A& �ȼ��� const A const *
	{
		if (this != &that)//�ж�this��that�ǲ���ָ����ͬһƬ��ַ�����ִ��ͬһƬ��ַ��˵����һ����������������
		{
			this->i = that.i;
		}
		return *this; 
	}
};


class B
{
public:
	char* p;
	const B& operator =(const B& that)  //����ʵ���Ͼ��ǳ���ָ��  const A& �ȼ��� const A const *
	{
		
		delete p;
		p = new char[strlen(that.p) + 1];
		strcpy(p, that.p);
		return *this;
			
	}
};

int main()
{
	B b;
	char a[5]="1233";
	b.p = a;
	cout << b.p << endl;
	B c = b;
	cout << c.p << endl;
	//b = b; //��仰���л�����


	return 0;
}
// ע��1����ֵ��=һ��ֻ�������б�ʹ�ã���A��˵���˸�ֵ�����ص����壬���Ҹ�ֵ������������жϺ���Ҫ��
// ע��2����B�����˸�ֵ������û�м��жϳ����һ�����ӡ���Ϊ��B������ָ�������ָ�븳ֵ��ʱ����ɾ���ɵģ��ڸ����µģ�����B�У����b=b����ôɾ���ɵľ��ǰ�Ҫ��ֵ��
//�µ�Ҳɾ���ˣ���û��ֵ���Ը����b�ˣ������ڴ����������������У�˵���˸�ֵ�����ر�����ж��Լ�ָ���Ƿ������һ�ж�