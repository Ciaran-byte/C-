#include<iostream>
#include<vector>
#include<time.h>
#include<fstream>
#include<algorithm>
using namespace std;

int main()
{
	//要考虑打错次数跟字符串里面数组索引相差了1
	//要考虑输入数字可能不是0-4，负数和超过的数字要单独处理。

	srand(time(NULL));
	const int sz = 4;
	int tries = rand() % 7;
	string str[sz] = { "hell0","ok","bye","ss" };

	if (tries < 0)tries = 0;
	else if (tries >= sz)tries = sz - 1;
	cout << str[tries] << endl;
	return 0;
}

