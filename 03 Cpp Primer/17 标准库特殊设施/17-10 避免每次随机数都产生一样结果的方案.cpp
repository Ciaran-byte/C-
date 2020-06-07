#include<iostream>
#include<random>
#include<ctime>
using namespace std;
vector<unsigned> good_randvec()
{
	static default_random_engine e; //可以使得程序运行时，每次调用都产生不一样的vector
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
	//对于一个函数而言，可以把引擎和分布函数定义为static的
	using uvec = vector<unsigned>;
	uvec v1 = good_randvec();
	uvec v2 = good_randvec();
	for (size_t i = 0; i < 100; i++)
	{
		cout << v1[i] << endl;
		cout << v2[i] << endl;
		cout << endl;
	}


	//对于每次系统运行而言，可以利用系统时间作为随机数的种子
	default_random_engine e1(time(0));
	uniform_int_distribution<unsigned> u(0, 9);
	cout << endl;
	for (size_t i = 0; i < 100; i++)
	{
		cout << u(e1) << endl;
	}
	return 0;
}


