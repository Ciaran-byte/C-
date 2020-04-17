#include<iostream>
using namespace std;
//Ĭ�Ͽ�������
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

//�Զ��忽�����캯��
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
	//01 ʹ��Ĭ�Ͽ���������һ����
	matrix1 m(4, 4);
	double l[16] = { 1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4 };
	m.put(l);
	m.show();
	//matrix1 n(m); //�ᱨ����Ϊ����������n����ָ��m�����������ַ������ʱ���õ�ַ�ᱻdelete���Σ�������ش���
	cout << endl;


	//02 ʹ���Զ��忽�����캯�������ᱨ����Ϊ��ַ�����´�����
	matrix2 x(4, 4);
	x.put(l);
	x.show();
	matrix2 y(x);
	y.show();
	return 0;

	}

