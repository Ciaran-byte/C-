#include<iostream>
using namespace std;
//        表示命令行参数个数   表示命令行参数的值，字符串类型
int main(int argc,char **argv)
{
	//注意，argv【0】不是命令行参数，是这个程序的名字。这个程序运行的时候应该在命令行里面运行
	int start, end, step;

	//判断输入命令行的参数数量是否满足要求，这个4是包含argv【0】的参数个数
	if (argc != 4)
	{
		cout << "输入参数数量不对啊！" << endl;
		return -1;
	}
	start = atoi(argv[1]);//字符串转整型
	end = atoi(argv[2]);
	step = atoi(argv[3]);
	for (int k = start; k < end; k += step)
	{
		cout << k << endl;
	}

	//cout << argc << endl;
	return 0;
}

