#include<iostream>
#include<vector>
#include<time.h>
#include<fstream>
#include<algorithm>
using namespace std;

int main()
{
	//Ҫ���Ǵ��������ַ��������������������1
	//Ҫ�����������ֿ��ܲ���0-4�������ͳ���������Ҫ��������

	srand(time(NULL));
	const int sz = 4;
	int tries = rand() % 7;
	string str[sz] = { "hell0","ok","bye","ss" };

	if (tries < 0)tries = 0;
	else if (tries >= sz)tries = sz - 1;
	cout << str[tries] << endl;
	return 0;
}

