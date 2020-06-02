#include<iostream>
#include<utility>
using namespace std;

//01 ��ϵ�һ����
void f(int v1, int& v2)
{
	cout << v1 << " " << ++v2 << endl;
}

template<typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2)
{
	f(t2, t1);

}

//02 ��ϵڶ�����
template<typename F, typename T1, typename T2>
void flip2(F f, T1&& t1, T2&& t2)
{
	f(t2, t1);
}

//03 ��ϵ�������
void f2(int&& t1, int& t2)
{
	cout << t1 << " " << ++t2 << endl;
}

//04 ��ϵ��Ĳ���
template<typename F,typename T1,typename T2>
void flip3(F f, T1&& t1, T2&& t2)
{
	f(forward<T2>(t2), forward<T1>(t1));
}
int main()
{
	//01 һ��ģ��ᶪʧ������������ֵ���Ի���const����
	cout << "��һ��" << endl;
	int i = 5;
	f(10, i);
	cout << i << endl;

	int j = 5;
	flip1(f, j, 10); //j�����Ǹ�int������flip1�Ժ�ʧȥ��ֵ���ԣ���˺��������f��jû��Ӱ�죬��ԭf����Ч��������ȫ��ͬ

	cout << j << endl;
	

	//02 ��ȫ��ֵ���Ժ�const���Եķ���
	cout << "�ڶ���" << endl;
	int m = 5;
	flip2(f, m, 10);
	cout << m << endl;
	//ʹ����ֵ����ģ�壬���ý���������۵����򣬱�����ԭʼ��������ֵ����

	//03  ��һ���Ż��������ڵ�ȱ��
	//ʹ��02�������⣬��10��Ȼ�Ǹ����������ǽ���flip2֮�󣬱�����Ϊ��ֵ���ã���ֵ�����Ǹ���ֵ��
	//���f������Ҫ����t1����int������int&&����Ȼ���ܸ�f����ƥ��
	cout << "������" << endl;
	int n = 5;
	f2(10, n);

	//flip2(f2, n, 10); //�޷����������ת��������Ϊ10�����Ժ����Ϊ��ֵ���ã���ֵ��������ֵ�����ܼ�������f2

	//04 ��һ���Ż�
	cout << "������" << endl;
	int p = 5;
	flip3(f2, p, 10);
		cout << p << endl;
		//forward�������Ǽ�����֤���ⲿ�������������ֵ���Ժͳ�������
		//02����ֻ�Ǳ����ⲿ��������ֵ���ԣ�forward�ڴ˴�������������ֵ����
		//forward���T���ͱ�����ת����T&&���ͱ�����Ҳ����˵��10����flip3��ͨ����ֵ����int&&���������ֵ����int
		//f2����Ҫ��һ����ֵ���ͣ�10�Ͷ�ʧ����ֵ���ԣ�ʹ��forward��int���int&&�����������ֵ����
	return 0;
}


