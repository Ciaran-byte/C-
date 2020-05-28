#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<ctime>


using namespace std;
using namespace placeholders;


int main()
{
	
	srand(time(0));
	vector<int> vec;
	for (int i = 0; i < 100; i++)
	{
		vec.push_back(rand() % 1500);

	}
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << endl;

	}
	cout << endl;

	size_t num=count_if(vec.begin(), vec.end(), bind(greater<int>(), _1, 1024));
	
	cout << num << endl;
	
	auto it=find_if(vec.begin(), vec.end(), bind(not_equal_to<int>(), _1, 666));
	cout << *it << endl;

	cout << endl;
	transform(vec.begin(), vec.end(), vec.begin(), bind(multiplies<int>(), _1, 2));
	
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << endl;

	}
	cout << endl;
	return 0;
}

