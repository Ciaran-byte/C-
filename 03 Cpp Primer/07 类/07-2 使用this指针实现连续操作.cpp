#include<iostream>
using namespace std;
class screen
{
	typedef size_t pos;
public:
	screen() = default; //因为都有默认值，可以使用一个默认构造函数
	screen(pos x,pos y,char c=' '):_x(x),_y(y),_contents(x*y,c){}
	
	inline char get()
	{
		return _contents[_cursor];
	}
	inline char get(pos x, pos y)
	{
		return _contents[(x-1)*_y+y-1];
	}
	inline screen& move(pos x, pos y)
	{
		_cursor = (x - 1) * _y + y - 1;
		return *this;
	}
	inline screen& set(pos x, pos y, char c)
	{
		_contents[(x - 1) * _y + y - 1] = c;
		return *this;
	}
	inline screen& set(char c)
	{
		_contents[_cursor] = c;
		return *this;
	}


	const screen& print(ostream& os)const
	{
		myprint(os);
		return *this;
	}
	screen& print(ostream& os)
	{
		myprint(os);
		return *this;
	}
private:
	pos _x=0;
	pos _y=0;
	pos _cursor = 0;
	string _contents;
	void myprint(ostream& os)const
	{
		os << _contents<<endl;
	}
};

int main()
{
	//01 使用this实现指针连续操作
	//有时候我们可能希望类可以实现连续调用函数，这个时候，使用返回类本身的引用就大显身手
	//比如本例中，定了了move和set两个函数，可以实现把标志符移到某个位置，然后把这个字符进行替换
	screen sc(5, 6, '1');
	sc.move(1, 1).set('3');


	//02 const对象的返回
	//有时候我们在这种连续调用中，可能会出现某一个函数返回是const对象，比如print函数，一般是那种不需要操作
	//类内对象的函数，很可能设计为const的

	//这个时候可以对const的print函数进行重载，定义一个非const引用返回值的。

	//但是记住，这种重载必须要在后面加const标记，否则无法构成重载条件

	sc.print(cout).move(5, 6).set('3').print(cout);
	//03 小建议
	//建议还是要使用myprint这种小函数的
	//因为能够减少变量的重复使用；有时候如果输出复杂了，只需要改一处即可;并且还可能输出调试信息

	return 0;
}


