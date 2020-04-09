#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

vector<int> filter(const vector<int>& vec, int val, less<int>& lt)
{
	vector<int> nvec;
	vector<int>::const_iterator iter = vec.begin();

	while ((iter = find_if(iter, vec.end(), bind2nd(lt, val)) )!= vec.end())
	{
		nvec.push_back(*iter);
		iter++;
	}

	return nvec;

}

int main()
{
	
	vector<int> vec = { 1,2,3,4,5,6,7,8,9,10 };
	less<int> a;
	
	vector<int>test=filter(vec, 5,a );

	vector<int>::iterator it = test.begin();
	vector<int>::iterator end = test.end();
	for (; it != end; it++)
	{
		cout << (*it) << endl;
	}

	return 0;
}

