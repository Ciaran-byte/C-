#include<iostream>
#include<vector>
#include<list>
using namespace std;

template <typename T,typename P>
T myfind(T a1, T a2, const P& a3)
{
	for (; a1 != a2; a1++)
	{
		if (*a1 == a3)
		{
			return a1;
		}
	}
	return a1;
}

int main()
{
	vector<int> vec = { 1,2,3,4,5 };
	list<string>lst = { "hello","hi","ok" };
	auto it = myfind<vector<int>::iterator, int>(vec.begin(), vec.end(), 3);
	cout << *it << endl;
	
	return 0;
}


