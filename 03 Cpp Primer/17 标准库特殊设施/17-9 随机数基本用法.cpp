#include<iostream>
#include<random>
using namespace std;
int main()
{
	default_random_engine e;
	for (size_t i = 0; i < 10; ++i)

	{
		cout << e() << endl;
	}
	
	uniform_int_distribution<unsigned> u(0, 9);
	cout << endl;
	for (size_t i = 0; i < 10; i++)
	{
		cout << u(e) << endl;
	}

	return 0;
}


