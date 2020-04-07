#include<iostream>
#include<vector>
using namespace std;

template<typename T>
T max(T a, T b)
{
	return (a > b ? a : b);
}



int main()
{
	cout << max<int>(5, 6) << endl;
	cout << max<double>(1.2, 1.8) << endl;
	


	return 0;
}


