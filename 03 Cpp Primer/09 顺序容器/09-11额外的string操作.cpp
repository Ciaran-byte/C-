#include<iostream>
#include<string>
using namespace std;
int main()
{
	//01 string的构造
	//01-1 从char *构造
	const char* cp= "123456";
	//（1）直接拷贝，前提是cp必须以空字符结尾
	string s(cp);
	const char cp2[2]= { '0','1'};
	string t(cp2); //结尾没有空字符，计算机不知道该复制到哪里，就解析出来了烫烫烫
	//cout << t << endl;
	
	//(2) 指定位置拷贝,拷贝前三个

	string s2(cp, 3);
	cout <<"s2 "<< s2 << endl;

	//(3) 指定范围拷贝
	string s3(cp, 2, 6);
	cout << "s3 " << s3 << endl;
	//01-2 从string进行构造
	string S = "124444222";
	string s4 = S.substr(0, 5);
	cout << "s4 " << s4 << endl;

	//02 改变string的其他办法
	//assign,insert,erase

	//03 append和replace
	//03-1 append是将字符串插入到另外一个字符串的最后
	string s5 = "cpp";
	string s6 = " primer";
	s5.append(s6);
	cout <<"s5 "<<s5 << endl;

	//等价于
	string s7 = "cpp";
	s7.insert(s7.size(), s6);
	cout << "s7 " << s7 << endl;

	//03-2 replace

	string s8 = "123456789";
	s8.replace(2, 4, "hell");
	cout << "s8 " << s8 << endl;
	//从索引2开始，往后四个字符删除，换成hell，不过插入的字符串长度不一定刚好等于删除的长度
	
	//等价与
	s8.erase(2, 4);
	s8.insert(2, "3456");
	cout << "s8 " << s8 << endl;

	//04 字符串的搜索
	//find函数返回的是string的下标 size_type类型的
	//搜索失败会返回 string::npos

	//04-1 搜索完全匹配
	string s9 = "annabele";
	auto pos = s9.find("anna");
	cout <<"pos "<<pos << endl;
	pos = s9.find("bele");
	cout << "pos " << pos << endl;


	//04-2 搜索numbers中是否有跟name一样的字符-->在给定字符串中搜索任一匹配的值
	string numbers("01234567890"), name("r2d2");
	auto pspsps = name.find_first_of(numbers);
	cout << pspsps << endl;

	//04-2 搜索第一个不在列表中的值
	auto nt = name.find_first_not_of(numbers);
	cout << nt << endl;

	//05 字符串数值转换函数


	string db = "3.134";
	double db_d = stod(db);
	cout << db_d << endl;

	int a = 50;
	string s = to_string(a);

	return 0;
}