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
void print(LibMat& lib)  //函数传递参数没有使用引用或者指针的方式，即使传入book，也不调用book的虚函数
{
	lib.print();
	cout << typeid(lib).name() << endl;
	cout << (typeid(lib) == typeid(book)) << endl;

}
int main()
{
		LibMat libmat;
		book bk("my book", "me");
		
		audiobook abk("my audiobook", "me", "he");
		

		//LibMat* lb = &libmat;  //这句话两个函数都不会执行，因为窄类型变不成宽类型
		//LibMat* lb = &bk;  //这句话两个函数都会执行
		LibMat* lb = &abk; //这句话，动态类型转换可以，静态类型转换不可以，动态类型转换能把宽类型变成窄类型
		
		//使用静态类型转换，为了确保安全，要先保证该多态是否是我们要的那个样子
		if (typeid(*lb) == typeid(book))
		{
			book* b = static_cast<book*>(lb);
			cout << b->book::author() << endl;//不进行类型转换直接用会报错的
		}

	//动态类型转换，只有能转，才会转
		if (book *b1 = dynamic_cast<book*>(lb))
		{
			cout << "b1" << endl;
			cout << b1->book::author() << endl;//不进行类型转换直接用会报错的
		}




	return 0;
}

