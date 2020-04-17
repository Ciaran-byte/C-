#include<iostream>
#include<vector>
using namespace std;
//02 定义一个能够访问Triangular类的迭代器，因为这两个类的函数之间相互引用，所以把迭代器的定义放到了前面

class Triangular_iterator
{
public:
	//构造函数
	Triangular_iterator(int index) :_index(index) {}  //定义指向Triangular数列第几个数字的index

	//运算符重载
	bool operator==(const Triangular_iterator& rhs)const;  //判断两个迭代器的index是否一样
	bool operator!=(const Triangular_iterator& rhs)const;  //判断是否不一样
	 
	int operator*()const;  //用迭代器和索引，读取Triangular的数据

	Triangular_iterator& operator++();  //对迭代器进行偏移运算
	Triangular_iterator operator++(int);



private:
	int _index;
	void check_security();//检查迭代器访问对象是否安全
};

//01 定义一个存放数组的类，主要功能为储存triangular数列
class Triangular
{
public:
	Triangular(){}
	static bool gen_elements(int length); //用来扩充数列的函数
	static void display(int length); //用来根据需要打印数列的
	
	Triangular_iterator begin()const  //begin函数
	{
		return Triangular_iterator(0);
	}
	Triangular_iterator end()const  //end函数
	{

		return Triangular_iterator(_sequence.size());
	}
	friend class Triangular_iterator; //声明友元
private:
	
	static const int max_sequence = 1024; //数列最长可以是多少
	static vector<int> _sequence;  //存放数列数据的地方
	
	
};

//01-1 static成员变量的定义
vector<int> Triangular::_sequence; 

//01-2扩充数列的函数
bool Triangular::gen_elements(int length) 
{
	if (length<0 || length>max_sequence)
	{
		cerr << "创建数组的长度不正确！" << endl;
		return false;
	}
	int size = _sequence.size();
	if (size < length)
	{
		for (int i = size; i < length; i++)
		{
			_sequence.push_back((i + 1) * (i + 2) / 2);
		}
	}
	return true;
}

//01-3 打印数列
void Triangular::display(int length)
{
	if (gen_elements(length))
	{
		for (int i = 0; i < length; i++)
		{
			cout << _sequence[i] << endl;
		}
	}

}




//02-1 重载==运算符，迭代器相等为指向的位置相同
bool Triangular_iterator::operator==(const Triangular_iterator& rhs)const
{
	return _index == rhs._index;
}
//02-2 重载!=运算符，迭代器相等为指向的位置相同
bool Triangular_iterator::operator!=(const Triangular_iterator& rhs)const
{
	return !(*this==rhs);
}

//02-3 重载*运算符，保证指向的位置不为空
int Triangular_iterator::operator*()const
{
	if (Triangular::gen_elements(_index + 1))
	{
		return Triangular::_sequence[_index];
	}
	return 0;
}

//02-4重载运算符++
Triangular_iterator& Triangular_iterator::operator++()
{

	_index++;
	return *this;
}
Triangular_iterator Triangular_iterator::operator++(int)
{
	_index++;
	return *this;
}




int main()
{
	
	Triangular tr;
	tr.gen_elements(20);
	Triangular_iterator it = tr.begin();
	Triangular_iterator end = tr.end();
	for (; it != end; it++)
	{
		cout << *it << endl;
	}
	
	return 0;
}