#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int main()
{

	vector<string> vec = { "hello","hi","are you ok" };
	vector<int> vec2 = { 1,2,3 };
	vector<pair<string, int>> vec3;
	auto it1 = vec.begin();
	auto it2 = vec2.begin();

	auto end1 = vec.end();
	auto end2 = vec2.end();
	
	while (it1 != end1 && it2 != end2)
	{
		vec3.push_back(make_pair(*it1++, *it2++));
		
	}
	for (pair<string,int> i : vec3)
	{
		cout << i.first << " " << i.second;
		cout << endl;
	}

	return 0;
}

