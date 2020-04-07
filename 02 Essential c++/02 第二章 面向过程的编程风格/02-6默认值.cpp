#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
void bubble_sort(vector<int>& v, ofstream& outfile);
void bubble_sort2(vector<int>& v, ofstream *outfile=0);
void swap(int& m, int& n);

int main()
{
	//如何解决测试函数往文件中写入测试数据的情况呢？

	//法一，把文件写在file scope中，让函数本身能看到这个变量。缺点：这个函数通用性太差
	//法二，把文件加一个传入参数。缺点是，不是所有情况都需要这个测试函数使用，变通性太差
	ofstream outfile("out.txt");

	vector<int> v = { 1,3,4,5,6,7,2 };
	bubble_sort(v, outfile);

	//法三，把文件加一个默认项，只有在需要的时候才传入文件。记得函数声明和函数定义只能有一个地方写默认值。
	//建议在函数声明里面写，因为头文件可见性比较高.
	//注意，引用不能默认为空，所以这里只能使用指针
	ofstream outfile2("out2.txt");
	//bubble_sort2(v, &outfile2);
	bubble_sort2(v);

	return 0;
}


void bubble_sort(vector<int>& v,ofstream &outfile)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[j] < v[i])
			{
				swap(v[j], v[i]);
			}
		}

	}
	for (int i = 0; i < v.size(); i++)
	{
		outfile << v[i] << endl;
	}
}
void bubble_sort2(vector<int>& v, ofstream *outfile)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[j] < v[i])
			{
				swap(v[j], v[i]);
			}
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		(*outfile) << v[i] << endl;
	}
}
void swap(int& m, int& n)
{
	int t;
	t = m;
	m = n;
	n = t;
}

