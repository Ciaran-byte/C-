#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
int main()
{
	//01 count
	vector<int> vec = { 1,2,42,5,8,9,5,15,5 };
	vector<int>::iterator it = vec.begin();
	auto a = count(vec.begin(), vec.end(), 5);
	cout << a << endl;
	int i=1;
	vector<int> dst;

	//02 find
	while ((it = find(it, vec.end(), 5)) != vec.end())
	{

		cout <<"第"<< i<<"次" << endl;
		cout << *it << endl;
		dst.push_back((*it));
		it++;
		i++;
		
		
	}
	cout << dst.size() << endl;
	
	//03 accumulate
	int sum = accumulate(vec.begin(), vec.end(), 0);
	cout << sum << endl;
	
	vector<string> str = { "12","24","36","789" };
	string ss;
	string s = accumulate(str.begin(), str.end(), ss);
	cout << s << endl;

	//04 equal
	vector<int>v1 = { 1,2,3,4 };
	vector<int> v2 = { 1,2,3,4,7 };//第二个容器至少要和第一个一样长

	bool ba = equal(v1.begin(), v1.end(), v2.begin());
	cout <<ba << endl;

	return 0;
}

