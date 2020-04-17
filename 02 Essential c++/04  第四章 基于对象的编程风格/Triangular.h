
#include<iostream>
#include<vector>

using namespace std;

#ifndef _Triangular_H
#define _Triangular_H
class Triangular
{
public:

	static bool is_elem(int value);
	static void gen_elements(int value);

private:
	static const int _max_elems = 1024;
	static vector<int> _elems; //这个是声明


};

vector<int> Triangular::_elems; //这个才是定义，静态变量必须要定义才能使用

void Triangular::gen_elements(int value)
{
	
	int length = _elems.size();
	if (!length)
	{
		_elems.push_back(1);
		length = 1;
	}
	while (_elems[length - 1] < value && length < _max_elems)
	{
		length++;
		_elems.push_back(length * (length + 1) / 2);

	}
	if (length == _max_elems)
	{
		cerr << "你要找的数字超出数列太长了！" << endl;
		cerr << value << "已经超过了最大的长度" << _max_elems << endl;
	}

}
bool Triangular::is_elem(int value)
{
	int length = _elems.size();
	if (!length || value > _elems[length - 1])
	{
		gen_elements(value);
	}
	vector<int>::iterator beg = _elems.begin();
	vector<int>::iterator end = _elems.end();
	vector<int>::iterator rst = find(beg, end, value);
	if (rst != end)return true;
	return false;
}





#endif // 

