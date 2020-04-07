#include<iostream>
#include<limits>
using namespace std;
int main()
{
	int max_int = numeric_limits<int>::max();
	double min_db1 = numeric_limits<double>::min();
	cout << max_int << endl;
	cout << min_db1 << endl;

	return 0;
}

