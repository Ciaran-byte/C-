#include<iostream>
#include<vector>

#include<algorithm>
using namespace std;
int main()
{

	//两个数列相加

	vector<int> ivec = { 1,2,3,10,3,4,6,10,2,10,5,10 };

	vector<int> test = { 1,2,3,4,5,6,7,8,9,8,7,6 };
	vector<int> rst(ivec.size());

	transform(ivec.begin(), ivec.end(), test.begin(), rst.begin(), plus<int>());
	vector<int>::iterator it = rst.begin();
	vector<int>::iterator end = rst.end();
	for (; it != end; it++)
	{
		cout << *(it) << endl;
	}

	return 0;
}

