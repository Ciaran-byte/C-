#include<iostream>
#include<random>
#include<ctime>
using namespace std;
vector<unsigned> good_randvec()
{
	static default_random_engine e; //����ʹ�ó�������ʱ��ÿ�ε��ö�������һ����vector
	static uniform_int_distribution<unsigned> u(0, 9);
	vector<unsigned> vec;
	for (size_t i = 0; i < 100; i++)
	{
		vec.push_back((u(e)));
	}
	return vec;
}

int main()
{
	//����һ���������ԣ����԰�����ͷֲ���������Ϊstatic��
	using uvec = vector<unsigned>;
	uvec v1 = good_randvec();
	uvec v2 = good_randvec();
	for (size_t i = 0; i < 100; i++)
	{
		cout << v1[i] << endl;
		cout << v2[i] << endl;
		cout << endl;
	}


	//����ÿ��ϵͳ���ж��ԣ���������ϵͳʱ����Ϊ�����������
	default_random_engine e1(time(0));
	uniform_int_distribution<unsigned> u(0, 9);
	cout << endl;
	for (size_t i = 0; i < 100; i++)
	{
		cout << u(e1) << endl;
	}
	return 0;
}


