#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	//文件模式是指读写文件的方式，在文件流与文件绑定的时候进行定义,文件模式一般都有默认值

	//01 ifstream
	//ifstream默认以in的形式进行读取，不会删除原有内容，把文件指针定位在文件开头

	ifstream infile("file1.txt", ifstream::in);
	string s;
	infile >> s;
	cout << s << endl;
	infile.close();
	//02 ofstream 
	//02-1
	//ofstream 默认以out方式打开文件,而out模式又默认与trunc模式绑定，所以如果被写入的文件以前有内容，会被清空
	ofstream of1("file2.txt");
	ofstream of2("file2.txt",ofstream::out);
	ofstream of3("file2.txt", ofstream::out|ofstream::trunc);
	//上面三种写法是等价的

	of1 << "hello！ nice to meet you！" << endl;
	of1.close();

	//02-2 
	//如果希望在原文件后面进行插入，需要绑定app模式
	ofstream of4("file3.txt", ofstream::out | ofstream::app);
	of4 << "hello！ nice to meet you！" << endl;
	of4.close();

	//03 fstream
	//03-1默认情况
	//fstream是能够同时对文件进行读写操作的类型，默认值是in模式绑定out模式，并且打开不会清空内容，而且文件指针定位在开头
	fstream ff1("file4.txt");
	fstream ff2("file4.txt", fstream::in | fstream::out);//两者等价

	string ss = "hello";
	ff1 << ss;
	//可以看到file4并没有被清空，但是字符插入在最前面,并且会取代原来的文件内容

	//03-2 
	//如果希望能够往后面写入，需要绑定ate模式，指的是，打开文件就把文件指针放到最后面
	fstream ff3("file4.txt", fstream::in | fstream::out | fstream::ate);
	ff3 << ss;
	return 0;
}

