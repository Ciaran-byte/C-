#include<iostream>
#include<vector>
#include<deque>
#include<list>
using namespace std;

vector<int>::iterator fun(vector<int>::iterator it, vector<int>::iterator end, int val)
{
	for (; it != end; it++)
	{
		if (*it == val)
			return it;
	}
	return end;
}
int main()
{
	vector<int> vec = { 1,2,3,4,5,6 };

	cout << fun(vec.begin(), vec.end(), 8) - vec.begin() << endl;
	cout << fun(vec.begin(), vec.end(), 3) - vec.begin() << endl;
return 0;
}


