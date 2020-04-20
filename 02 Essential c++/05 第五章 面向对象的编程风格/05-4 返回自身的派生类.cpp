#include<iostream>
using namespace std;

class num_sequence
{
public:
	virtual num_sequence& f()
	{
		cout << "num_sequence" << endl;
		return *this;
	}

};

class Fibonacci :public num_sequence
{
public:
	virtual Fibonacci & f()
	{
		cout << "Fibonacci" << endl;
		return *this;
	}
};

int main()
{
	Fibonacci b;
	num_sequence p;

	num_sequence* pp = &b;
	pp->f();

	return 0;
}


