#include<iostream>
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

class book: public LibMat
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
	string& title(){ return _title; }
	string& author(){ return _author; }
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
void print(LibMat& lib)
{
	lib.print();
}
int main()
{
	{
		book bk("my book", "me");
		print(bk);
		
	}

	{
		audiobook abk("my audiobook", "me", "he");
		abk.author() = "he";
		abk.narrator() = "me";
		print(abk);

	}
	return 0;
}

//注解1：这个程序演示了继承和多态的使用方法。基类为libmat，book是libmat的派生类，audiobook是book的派生类


//注解2：从里面看出，使用继承，必须要给他的基类进行赋值，使用初始化列表就行。同时父类的所有对象，都可以被
//派生类使用，只要父类的对象是public或者protected的

//注解3：从外部函数print的实现情况来看，虚函数是一种动态绑定，只要运行时候才会去判断自己要调用哪个函数

//注解4：如果类中有虚函数，析构函数必须也是虚函数，否则派生类多的一些对象没有相对应的析构函数去析构