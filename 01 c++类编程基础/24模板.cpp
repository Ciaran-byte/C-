#include<iostream>
using namespace std;

template <class T>
void my_swap(T& t, T& m)
{
	T a = t;
	t = m;
	m = a;
}


template<class T>
class A
{
public:
	A(T ii):i(ii){}
	T f(T a)
	{
		return a;
	}
	 
private:
	T i;
};

template<class T>
class B : public A<int>
{
public:
	T i;
	B():A(10){}
};
int main()
{

	//��1������ģ��
	int i = 1, j = 2;
	double m = 1, n = 2;
	my_swap(m, n);
	my_swap(i, j);
	cout << "i= " << i << "j= " << j<<endl;
	cout << "m= " << m << "n= " << n << endl;

	//��2����ģ��
	A<int> c(5);

    
	//(3)�̳�
	cout << endl;
	B<int> b;
	b.i = 10;
	cout << b.i<<endl;


	return 0;
}

//  ע��1:ģ����ʲô�ã�ģ��ʹ�õ��龳���ڣ������Ҫʹ�õĶ���ֻ࣬�б������Ͳ�ͬ�������ṹ������ͬ���Ϳ���ʹ��ģ������������飬��ô�����ŵ��ǹ�����
//�����Ҫ�޸���ṹ�Ļ����Ͱ�ģ���޸�һ�¾��С�
//  ע��2:ģ���Ϊ����ģ�����ģ�塣�����Ǻ���ģ�廹����ģ�壬��������ǰ������ template <class T> ����T�ǿ��Ա�ģ����������ǹؼ��֡�
//����ģ�嶨���ʱ�򣬰�T�滻�������ͼ��ɣ�ʹ��ʱֱ�ӵ��ü��ɡ�
//��ģ�嶨���ʱ�򣬰�T�滻Ϊ�������ͣ�ʹ�õ�ʱ��Ҫ�ں����һ�������ţ�˵��ȡ�����������͡�
//  ע��3��template<class T>��仰�����������Ƕ��壬ֻ�����е������ഴ��ʵ�����ߺ������õ�ʱ�򣬲Ż��滻��ʵ�ʵı������͡�
//   ע��4��template<class T, class P>�������д���ֱ���
//   ע��5�������Ҫ�̳�ģ���࣬�����ȸ��Ǹ���һ��׼ȷ�ı�����ģ����Լ̳�ģ���࣬Ҳ���Լ̳з�ģ����