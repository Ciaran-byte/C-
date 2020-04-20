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
	void P()
	{
		print();
	}

	void Q()
	{
		LibMat::print();
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
		audiobook abk("my audiobook", "me", "he");
		cout << endl;
		print(abk);
		cout << endl;
		abk.P();
		cout << endl;
		abk.Q();
		cout << endl;

	}
	return 0;
}

//注解1：有时候，我们可能会在类中的其他函数中调用虚函数，但是我们不希望这个虚函数是运行时候才确定是哪个，
//因为我们只想调用自己这个类的函数，而不希望他动态绑定到其他地方。所以前面要使用class scope符号，来明确
//调用哪个函数，这相当于隐藏了虚函数的运行机制。比如函数P，就调用的是audiobook的print，而Q调用的是libmat的print
