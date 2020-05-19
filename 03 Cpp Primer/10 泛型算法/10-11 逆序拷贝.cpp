#include<iostream>
#include<fstream>
#include<vector>
#include<iterator>
#include<list>
#include<algorithm>

#include<functional>

using namespace std;

int main()
{
	ostream_iterator<int> out(cout, " ");
	vector<int> vec = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int>::reverse_iterator re(vec.begin() + 2);

	vector<int>::reverse_iterator rb(vec.begin() + 7);

	list<int> lst;

	copy(rb, re, back_inserter(lst));
	copy(lst.begin(), lst.end(), out);

	

	

	return 0;
}


