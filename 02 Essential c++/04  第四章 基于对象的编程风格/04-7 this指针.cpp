#include<iostream>
using namespace std;

class Triangular
{

public:
	Triangular(int length = 1, int beg_pos = 1) :_length(length), _beg_pos(beg_pos),_next(beg_pos-1)
	{

	}
	Triangular copy(const Triangular &rhs)
	{
		if (this != &rhs)
		{
			_length = rhs._length;
			_beg_pos = rhs._beg_pos;
			_next = rhs._next;
		}
		
		return *this;
	}
private:
	int _length;
	int _beg_pos;
	int _next;
	
};

int main()
{
	Triangular tr1(5, 5);
	Triangular tr2(6);
	tr1.copy(tr2);
	
	
	return 0;
}


