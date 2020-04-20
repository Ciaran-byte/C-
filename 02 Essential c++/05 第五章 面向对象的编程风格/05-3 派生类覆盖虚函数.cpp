#include<iostream>
using namespace std;

class num_sequence
{
public:
	virtual const char* what_am_i()const
	{
		return "num_sequence";
	}
};

class Fibnoacci: public num_sequence
{
public:
	virtual const char* what_am_i() 
	{
		return "Fibnoacci";
	}
};

int main()
{
	num_sequence p;
	Fibnoacci q;
	num_sequence& pp = q;
	cout << pp.what_am_i() << endl;;

	return 0;
}

