#include<iostream>
using namespace std;

typedef unsigned Bit;
class File
{
public:
	Bit mode : 2;  //uint有32位，拿出2位来做东西
	Bit modified : 1;

	//其他省略
private:


};

int main()
{

	File f;
	f.mode = 4; //只有2位，最多为3，输入4就溢出了
	f.modified = 1;
	cout << f.mode << endl;
	cout << f.modified << endl;
	return 0;
}

