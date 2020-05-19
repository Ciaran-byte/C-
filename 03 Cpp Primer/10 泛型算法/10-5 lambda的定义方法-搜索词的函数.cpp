#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//我们要实现一个函数，删除所有重复的词，并且让这些词重新排序，先按长度排，再按字典排，最后返回有多少个长度n以上的词
//并打印这些词

//01 删除重复词
void elimDups(vector<string>& words)
{
	sort(words.begin(), words.end());
	auto it = unique(words.begin(), words.end());
	words.erase(it, words.end());
}

//02 
void biggies(vector<string>& words, vector<string>::size_type sz)
{
	elimDups(words);
	//把词按长度排序，等长的按字典顺序排序
	stable_sort(words.begin(), words.end(), [](const string& str1, const string& str2) {return str1.size() < str2.size(); });

	//寻找长度大于sz的字符串的迭代器
	auto iter=find_if(words.begin(), words.end(), [sz](const string& str) -> bool 
		{return str.size() >= sz; });

	//记录有多少个长度大于sz的字符串
	auto number = words.end() - iter;

	//打印这些字符串
	for_each(iter, words.end(), [](const string& str) {cout << str<< endl; });
}

int main()
{
	vector<string> str = { "hello","hi","what are you doing","hello","hi","what","what else" };
	biggies(str, 5);

	//lambda的写法
	//  [捕获列表] (参数列表) -> 返回值类型 {表达式}
	//其中 (参数列表)和 ->返回值类型 两部分是可以不写的。不写返回值类型会根据表达式进行反推
	// lambda本质就是一个匿名的内联函数

	//关于捕获列表，里面写的是局部变量。全局变量和局部静态变量直接用就行，不需要写在捕获列表中
	


	return 0;
}

