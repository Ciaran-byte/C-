#include<iostream>
#include<vector>
#include<string>
#include<time.h>
using namespace std;
int main()
{
	//说明，本例程是一个随机读取不同vector的一个很好的例子
	//01定义一些vector
	vector<int> Fibonacci = {1,1,2,3,5,8,13,21};
	vector<int> Lucas = { 1,3,4,7,11,18,29,47 };
	vector<int> Pell = { 1,2,5,12,29,70,169,408 };


	


	//02 将这些类的指针地址组合在vector中
	vector<int>* p[3] = { &Fibonacci,&Lucas,&Pell };

	//03使用随机数去寻找这些vector
	srand(time(NULL));
	int index = rand() % 3;
	vector<int>* q = p[index];


	//04 打印选到的
	for (int i = 0; i < q->size(); i++)
	{
		cout << (*q)[i] << endl;
	}



	return 0;
}


