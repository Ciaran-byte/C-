#include<iostream>
using namespace std;

void outOfMem() //�ڴ����������ʱ����õĺ���
{
	std::cerr << "unable to satisfy request for memory" << endl;
	abort();
}

int main()
{

	set_new_handler(outOfMem); //���ڴ����������ʱ��set_new_handler�����ָ��ĺ���
	int* pBigDataArray = new int[10000000L];
	delete pBigDataArray;
	return 0;
}

