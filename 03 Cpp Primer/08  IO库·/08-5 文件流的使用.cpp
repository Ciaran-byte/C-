#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	//01 文件流的基本使用方法-将文件流与文件进行绑定
	cout << "01 文件流与文件进行绑定" << endl;
	//（1）文件流的基本使用方法就是将文件流和文件名进行绑定，然后进行流操作
	ifstream is("one.txt");
	string s;
	while (is >> s)
	{
		cout << s << endl;
	}
	is.close();
	
	//（2） 文件流使用时候，除了使用字面值作为文件名外，也可以使用string类型或者c类型字符串代替
	string test = "two.txt";
	ifstream is2(test);
	while (is2 >> s)
	{
		cout << s << endl;
	}
	is2.close();//记得关闭文件流

	//02  文件流使用方法-检测文件是否成功打开
	//有时候文件会出现不能正常打开的情况，这个时候就需要进行文件打开的检测，提高容错能力
	cout << endl;
	cout << "02 检测文件是否能够正常打开" << endl;
	ifstream is3("1.txt");
	if (!is3)
	{
		cerr << "文件不能正常打开！" << endl;
	}
	else
	{
		while (is3 >> s)
		{
			cout << s << endl;
		}
	}
	is3.close();
	cout << endl;
	cout << "正常打开时" << endl;
	ifstream is4("three.txt");
	if (!is4)
	{
		cerr << "文件不能正常打开！" << endl;
	}
	else
	{
		while (is4 >> s)
		{
			cout << s << endl;
		}
	}
	is4.close();
	//03 将文件流进行重新绑定
	//03-1 文件定义的时候其实可以不用直接进行文件绑定，可以用open命令后来绑定
	cout << endl;
	cout << "03 文件流对象的重新绑定" << endl;
	ifstream is5;
	is5.open("one.txt");
	if (!is5)
	{
		cerr << "文件不能正常打开！" << endl;
	}
	else
	{
		while (is5 >> s)
		{
			cout << s << endl;
		}
	}
	
	is5.close();
	



	//03-2 文件流与另外的文档进行绑定
	is5.clear(); //这里注意一下，最好clear一下，不然可能存在上一个文件流条件标志位还是eof的情况，可能不能正常切换文档
	is5.open("two.txt");
	if (!is5)
	{
		cerr << "文件不能正常打开！" << endl;
	}
	else
	{
		while (is5 >> s)
		{
			cout << s << endl;
		}
	}
	is5.close();
	return 0;
}

