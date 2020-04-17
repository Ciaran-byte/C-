#include<iostream>
using namespace std;

class matrix
{

public:
	matrix(int row, int col):_row(row),_col(col)
	{
		cout << "this is a matrix" << endl;
		_pMat = new double[row * col];
	}

	~matrix()
	{
		cout << "bye" << endl;
		delete[] _pMat;
	}
	
private:
	int _row;
	int _col;
	double* _pMat;
};



int main()
{
	matrix mat(4, 4);
	

	return 0;
}


