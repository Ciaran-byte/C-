#include<iostream>
#include<vector>
#include<utility>
using namespace std;



int main()
{
	vector<string> a = { "1","2","3","4","5" };
	vector<string> b;
	copy(make_move_iterator(a.begin()), make_move_iterator(a.end()), back_inserter(b));
	for (auto it = b.begin(); it != b.end(); it++)
	{
		cout << *it << endl;
	}
	cout << endl;
	for (auto it = a.begin(); it != a.end(); it++)
	{
		cout << *it << endl;
	}
	

	return 0;
}

