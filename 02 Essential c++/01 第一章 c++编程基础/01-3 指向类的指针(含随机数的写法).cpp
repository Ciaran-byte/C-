#include<iostream>
#include<vector>
#include<string>
#include<time.h>
using namespace std;
int main()
{
	//˵������������һ�������ȡ��ͬvector��һ���ܺõ�����
	//01����һЩvector
	vector<int> Fibonacci = {1,1,2,3,5,8,13,21};
	vector<int> Lucas = { 1,3,4,7,11,18,29,47 };
	vector<int> Pell = { 1,2,5,12,29,70,169,408 };


	


	//02 ����Щ���ָ���ַ�����vector��
	vector<int>* p[3] = { &Fibonacci,&Lucas,&Pell };

	//03ʹ�������ȥѰ����Щvector
	srand(time(NULL));
	int index = rand() % 3;
	vector<int>* q = p[index];


	//04 ��ӡѡ����
	for (int i = 0; i < q->size(); i++)
	{
		cout << (*q)[i] << endl;
	}



	return 0;
}


