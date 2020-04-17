#include<iostream>
#include "stack.h"
int main()
{

	stack a;
	string test;
	for (int i = 0; i < 5; i++)
	{
		cin >> test;
		a.push(test);
		cout << a.size() << endl;
	}
	cout << endl;
	string b;
	a.peek(b);
	cout << b<< endl;

	cout << endl;
	string c;
	a.pop(c);
	cout << c << endl;
	cout << a.size() << endl;

	cout << endl;
	cout << a.myfind("a") << endl;
	cout << a.mycount("a") << endl;
	return 0;
}

