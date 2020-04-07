#include<iostream>
#include<vector>
using namespace std;

int max(int a, int b)
{
	return (a > b ? a : b);
}

double max(double a, double b)
{
	return (a > b ? a : b);
}

string max(string a, string b)
{
	return (a > b ? a : b);
}


int main()
{
	cout<<max(5, 6)<<endl;
	cout<<max(1.2, 2.4)<<endl;



	return 0;
}


