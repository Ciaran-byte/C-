#include<iostream>
#include<deque>
#include<list>
#include<vector>
using namespace std;

int main()
{
	vector<int> v1 = { 1,2,3,4,5 };

	//01 使用迭代器访问

	cout << *v1.begin() << endl;
	cout << *(--v1.end()) << endl;
	//02 使用back或者front访问
	cout << v1.back()<<endl;
	cout << v1.front()<<endl;

	//03 使用下标访问
	cout << v1[0] << endl;
	cout << v1[v1.size() - 1] << endl;

	//04 使用at访问
	cout << v1.at(0) << endl;
	cout << v1.at(v1.size() - 1) << endl;
	return 0;
}

