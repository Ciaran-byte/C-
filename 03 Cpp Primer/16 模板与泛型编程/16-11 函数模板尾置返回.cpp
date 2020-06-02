#include<iostream>
#include<vector>
using namespace std;

//01 通过尾置返回给模板解析迭代器类型
template<typename It>
auto fcn(It beg, It end)->decltype(*beg) //必须尾置返回，因为不确定迭代器指代是什么类型，如果放到开头，那时候beg还没定义，无法解析变量
{
	///
	return *beg;
}



int main()
{
	vector<int>  vec = { 1,2,3,4 };
	
	cout << fcn(vec.begin(), vec.end()) << endl;

	return 0;
}


