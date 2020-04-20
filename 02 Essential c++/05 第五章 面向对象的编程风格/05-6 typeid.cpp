#include<iostream>
#include<typeinfo>
using namespace std;



class LibMat
{
public:
	LibMat()
	{
		cout << "这里是libmat的构造函数！" << endl;
	}

	virtual void print()
	{
		cout << "我是libmat" << endl;
	}
	virtual ~LibMat()
	{
		cout << "这里是libmat的析构函数！" << endl;
		cout << endl;
	}

private:
};

class book : public LibMat
{
public:
	book(string title, string author) :_title(title), _author(author)
	{
		cout << "这里是book的构造函数！" << endl;
	}
	virtual void print()
	{
		cout << "我是book" << endl;
		cout << "我的title是" << _title << endl;
		cout << "我的author是" << _author << endl;
	}
	virtual ~book()
	{
		cout << "这里是book的析构函数！" << endl;
		cout << endl;
	}
	string& title() { return _title; }
	string& author() { return _author; }
protected:
	string _title;
	string _author;
};

class audiobook :public book
{
public:

	//配合注解2，派生类构造函数要给父类赋值，如果要用父类定义的对象的话
	audiobook(string title, string author, string narrator) :book(title, author), _narrator(narrator)
	{
		cout << "这里是audiobook的构造函数！" << endl;
	}

	virtual void print()
	{
		cout << "我是audiobook" << endl;
		cout << "我的title是" << _title << endl;
		cout << "我的author是" << _author << endl;
		cout << "我的narrator是" << _narrator << endl;
	}

	virtual ~audiobook()
	{
		cout << "这里是audiobook的析构函数！" << endl;
		cout << endl;
	}

	string& narrator() { return _narrator; }

protected:
	string _narrator;

};
void print(LibMat &lib)  //函数传递参数没有使用引用或者指针的方式，即使传入book，也不调用book的虚函数
{
	lib.print();
	cout << typeid(lib).name() << endl;
	cout << (typeid(lib) == typeid(book) )<< endl;
	
}
int main()
{
	{
		book bk("my book", "me");
		print(bk);

	}

	
	
	return 0;
}

