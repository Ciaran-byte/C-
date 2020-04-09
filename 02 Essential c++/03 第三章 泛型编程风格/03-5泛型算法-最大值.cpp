#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
int main()
{
	list<int> ilist = { 1,2,3,4,5,6 };
	list<int>::iterator begin = ilist.begin();
	list<int>::iterator end = ilist.end();
	list<int>::iterator max = max_element(begin, end);
	cout << (*max) << endl;
	return 0;
}

