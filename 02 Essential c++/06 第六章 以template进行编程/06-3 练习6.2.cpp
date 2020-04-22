
#include<iostream>
using namespace std;

template<typename valType>
class Matrix
{
public:
	Matrix(int col, int row, const valType* num) :_row(row), _col(col)
	{
		int size = _row * _col;
		_num = new valType[size];
		for (int i = 0; i < size; i++)
		{
			_num[i] = num[i];
		}

	}
	Matrix(const Matrix& mat)
	{
		_col = mat._col;
		_row = mat._row;
		int size = _col * _row;
		_num = new valType[size];
		for (int i = 0; i < size; i++)
		{
			_num[i] = mat._num[i];
		}
	}
	~Matrix()
	{
		delete[] _num;
	}

	valType& operator()(int row, int col)
	{
		return _num[(row - 1) * _row + (col - 1)];
	}
	
	void operator=(const Matrix& mat)
	{
		if (this != &mat)
		{
			_col = mat._col;
			_row = mat._row;
			int size = _col * _row;

			delete _num;
			_num = new valType[size];
			for (int i = 0; i < size; i++)
			{
				_num[i] = mat._num[i];
			}
		}
	}

private:
	valType* _num;
	int _row;
	int _col;
};

int main()
{
	//普通构造
	int num[4] = { 0,1,2,3 };
	Matrix<int> a(2, 2, num);
	cout << a(2, 2) << endl;

	//拷贝构造
	Matrix<int> a2(a);
	cout << a2(2, 2) << endl;
	
	//赋值
	int num2[9] = { 0,1,2,3,4,5,6,7,8 };
	Matrix<int> a3(3, 3, num2);
	a = a3;
	cout << a(3, 3) << endl;
	return 0;
}