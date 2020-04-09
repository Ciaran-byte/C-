#include<iostream>
#include<vector>
using namespace std;

int count_occurs(const vector<int>& vec, int val)
{
	int count = 0;
	vector<int>::const_iterator it = vec.begin();
	
	while ((it = find(it, vec.end(), val)) != vec.end())
	{
		count++;
		it++;
	}

	return count;
}


int main()
{

	vector<int> ivec = { 1,2,3,10,3,4,6,10,2,10,5,10 };

	int count = count_occurs(ivec, 10);
	cout << count << endl;


	

	return 0;
}

