#include<iostream>
#include<new>
#include<vector>
#include<memory>
using namespace std;

shared_ptr<vector<int>> f1()
{
	
	return make_shared<vector<int>>();
}

void f2(shared_ptr<vector<int>> p)
{
	int i;
	while (cin >> i, !cin.eof())
	{
		p->push_back(i);
	}
	
}
void f3(shared_ptr<vector<int>> p)
{
	for (auto i : *p)
	{
		cout << i << endl;
	}
	
}
int main()
{
	shared_ptr<vector<int>> p = f1();
	f2(p);
	f3(p);
	
	

	return 0;
}

