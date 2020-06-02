#include<iostream>
#include<vector>
#include<string>
using namespace std;
template<typename T> using vecV = vector<T>;
template<typename T> using twin = pair<T, int>;
int main()
{
	//01 使用tepedef只能对确定的模板实例进行别名 
		typedef vector<string> vecStr;
		
	vecStr v = { "234","34" };

	//02 使用using可以对含有模板的类进行别名
	vecV<string> a = { "12","sdf" };

	//03 对模板起别名的时候固定其中一个
	twin<int> t;

	return 0;
}

