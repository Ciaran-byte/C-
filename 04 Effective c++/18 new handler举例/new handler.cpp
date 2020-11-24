#include<iostream>
using namespace std;

void outOfMem() //内存分配出问题的时候调用的函数
{
	std::cerr << "unable to satisfy request for memory" << endl;
	abort();
}

int main()
{

	set_new_handler(outOfMem); //当内存分配出问题的时候，set_new_handler会调用指向的函数
	int* pBigDataArray = new int[10000000L];
	delete pBigDataArray;
	return 0;
}

