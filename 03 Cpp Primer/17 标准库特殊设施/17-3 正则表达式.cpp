#include<iostream>
#include<regex>
using namespace std;
int main()
{
	//01 正则表达式的基本用法
	string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*"; //[[:alpha:]]代表任意字母 *表示重复零次或者1次
	regex r(pattern);  //定义正则表达式类
	smatch results;  //用来存放搜索结果
	string test_str = "receipt freind theif receive";
	if (regex_search(test_str, results, r))  //对指定字符串使用正则表达式进行查找，结果在results中
	{
		cout << results.str() << endl;
	}

	//02 指定regex对象的选项
	cout << endl;
	try
	{

		cout << "02" << endl;

		regex r2("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase); //^表示匹配字符必须在最前面，$表示匹配字符必须在最后面
		//icase选项表示忽略大小写
		smatch results2;
		string filename;
		while (cin >> filename)
			if (regex_search(filename, results2, r2))
			{
				cout << results2.str() << endl;
			}

	}
	catch (regex_error e)
	{
		cout << e.what() << "\ncode:" << e.code() << endl;
	}

	//03 正则表达式与迭代器
	cout << endl;
	cout << "03" << endl;
	string pattern3("[^c]ei");
	pattern3 = "[[:alpha:]]" + pattern3 + "[[:alpha:]]";
	regex r3(pattern3, regex::icase);
	string test_str2 = "receipt freind theif receive";

	for (sregex_iterator it(test_str2.begin(), test_str2.end(), r3), end_it; it != end_it; it++)
	{
		cout << it->str() << endl;
	}
	


	return 0;
}

