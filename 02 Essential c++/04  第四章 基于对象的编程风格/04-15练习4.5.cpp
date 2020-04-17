
#include<iostream>
using namespace std;

class Matrix
{
public:
	Matrix
	(
		int n1, int n2, int n3, int n4,
		int n5, int n6, int n7, int n8,
		int n9, int n10, int n11, int n12,
		int n13, int n14, int n15, int n16
	)
	{
		a[0] = n1;
		a[1] = n2;
		a[2] = n3;
		a[3] = n4;
		a[4] = n5;
		a[5] = n6;
		a[6] = n7;
		a[7] = n8;
		a[8] = n9;
		a[9] = n10;
		a[10] = n11;
		a[11] = n12;
		a[12] = n13;
		a[13] = n14;
		a[14] = n15;
		a[15] = n16;
		
	}
	Matrix(int* num)
	{
		for (int i = 0; i < 16; i++)
		{
			a[i] = *(num + i);
		}
	}
	
private:
	int a[16];
};
int main()
{
	

	return 0;
}


