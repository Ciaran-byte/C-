#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;
class Person
{
public:
	string name;
	vector<string> numbers;
};
int main()
{
	
	vector<Person> vec;
	//string流有两个作用，能够实现拆分字符串和组合字符串的作用

	//01 拆分字符串
	//比如从文件中进行读取一条记录，就可以从istringstream进行字符串的逐词读取，实现字符串的拆分
	//phone 文件中有一些人的电话号码

	ifstream infile("phone.txt");
	string s;
	while (getline(infile, s)) //先读一行，一行包括人民和电电话号码
	{
		
		istringstream iss(s);
		Person p;
		string numbers;
		iss >> p.name; //第一个字符串是人名
		while (iss >> numbers, !iss.eof())//后面的字符串都是电话号码
		{
			p.numbers.push_back(numbers);
		}
		iss.clear();
		vec.push_back(p);
		
	}
	auto iter = vec.begin();
	while (iter != vec.end())
	{
		cout << iter->name << endl;
		iter++;
	}
	infile.close();
	infile.open("phone.txt");

	//直接输出单个单词
	cout << endl;
	cout << "直接输出单个单词" << endl;
	while (getline(infile, s))
	{
		istringstream iss;
		iss.str(s);//用于向istringstream中写入字符串，或者从ostringstream中输出字符串
		string mystring;
		while (iss >> mystring)
		{
			cout << mystring << ends;
		}
		iss.clear();
		cout << endl;
	}

	//02 使用ostringstream合并字符串

	ostringstream os;
	int a = 5;
	os << "2334" << a;
	cout << os.str();
	return 0;
}

