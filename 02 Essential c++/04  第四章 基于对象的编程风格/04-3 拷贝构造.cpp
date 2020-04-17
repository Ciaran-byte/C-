#include<iostream>
using namespace std;
//默认拷贝构造
class matrix1
{
public:
	matrix1(int row, int col):_row(row),_col(col)
	{
		_pMat = new double[_row * _col];
	}
	~matrix1()
	{
		delete[]_pMat;
	}
	void put(double* pMat)
	{
		for (int i = 0; i < _row * _col; i++)
		{
			*(_pMat + i) = *(pMat + i);
			
		}
	}
	void show()
	{
		for (int i = 0; i < _row * _col; i++)
		{
			cout << *(_pMat+i) << endl;
		}
	}
private:
	int _row;
	int _col;
	double* _pMat;

};

//自定义拷贝构造函数
class matrix2
{
public:
	matrix2(int row, int col) :_row(row), _col(col)
	{
		_pMat = new double[_row * _col];
	}
	matrix2(const matrix2& mat):_row(mat._row),_col(mat._col)
	{
		_pMat = new double[_row * _col];
		for (int i = 0; i < _row * _col; i++)
		{
			*(_pMat + i) = *(mat._pMat + i);
		}
	}
	~matrix2()
	{
		delete[]_pMat;
	}
	void put(double* pMat)
	{
		for (int i = 0; i < _row * _col; i++)
		{
			*(_pMat + i) = *(pMat + i);

		}
	}
	void show()
	{
		for (int i = 0; i < _row * _col; i++)
		{
			cout << *(_pMat + i) << endl;
		}
	}
private:
	int _row;
	int _col;
	double* _pMat;
};
int main()
	{
	//01 使用默认拷贝构造逐一复制
	matrix1 m(4, 4);
	double l[16] = { 1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4 };
	m.put(l);
	m.show();
	//matrix1 n(m); //会报错，因为这样创建的n，会指向m创建的数组地址，析构时，该地址会被delete两次，造成严重错误
	cout << endl;


	//02 使用自定义拷贝构造函数，不会报错，因为地址是重新创建的
	matrix2 x(4, 4);
	x.put(l);
	x.show();
	matrix2 y(x);
	y.show();
	return 0;

	}

