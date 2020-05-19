#include<iostream>
#include<map>
#include<algorithm>
#include<utility>
using namespace std;
//我们要实现打印一个作者的全部著作

int main()
{
	multimap<string, string> author_books = { {"Mike","A1"},{"Mike","A2"},{"Mike","A3"},{"Mike","A4"} };
	//01 方法一，通过find函数加count函数
	//在multi的容器中，同关键字的元素的储存是相邻的，所以记录同名的个数，把相邻的这些元素都打印出来即可
	size_t num = author_books.count("Mike");
	auto it = author_books.find("Mike");
	while (num)
	{
		
		cout << it->second << ends;
		++it;
		--num;
		
	}
	cout << endl;

	//02 使用lower_bound和upper_bound
	auto it1 = author_books.lower_bound("KK");
	auto it2 = author_books.upper_bound("KK");
	cout << it1->second << endl;
	cout << it2->second << endl;
	//如果容器中没有这个元素，两者会指向同一个位置

	//继续打印作者的全部的书
	//因为lowerbound指向不小于元素的第一个，也就是这组同样关键字元素的第一个
	//upperbound指向大于元素的第一个，也就是这组元素的最后一个的下一个位置
	//所以可以用来作为迭代范围
	multimap<string, string>::iterator beg = author_books.lower_bound("Mike");
	multimap<string, string>::iterator ed = author_books.upper_bound("Mike");

	for (; beg!=ed; ++beg)
	{
		cout << beg->second << ends;
	}
	cout << endl;

	//03 使用equal_range函数
	//返回值是个pair,放了两个迭代器，如果有这个元素，第一个返回这组元素的第一个，第二个值返回这组元素的最后一个的下一个
	//跟upper_bound和lower_bound一样原理，但是实现起来更加简单
	for (auto pos = author_books.equal_range("Mike"); pos.first != pos.second; pos.first++)
	{
		cout << pos.first->second << ends;
	}
	cout << endl;


	return 0;
}


