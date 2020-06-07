#include<iostream>
#include<random>
#include<ctime>
#include<cmath>
using namespace std;
int main()
{
	//01 浮点数的随机分布
	default_random_engine e1(time(0));
	uniform_real_distribution<double> u(0, 1);

	for (size_t i = 0; i < 10; i++)
	{
		cout << u(e1) << endl;
	}


	//02 正态分布的随机数

	default_random_engine e(time(0));
	normal_distribution<> n(4, 1.5); //均值4，标准差1.5
	vector<unsigned> vals(9);
	for (size_t i = 0; i != 200; i++)
	{
		unsigned v = lround(n(e));
		if (v < vals.size())
		{
			++vals[v];
		}
	}

	for (size_t j = 0; j != vals.size(); ++j)
	{
		cout << j << ": " << string(vals[j], '*') << endl;
	}

	return 0;
}


