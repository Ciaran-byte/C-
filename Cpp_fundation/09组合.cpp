//程序功能描述:这个程序是组合的示例，具体内容为，模拟的银行账户存钱，每个account类里面是由两个类组合而成的，分别是用来定义人的信息的person类和管理钱的balance类
//person类包含有一个人的名字和身份证号
//balance类包含了账户剩余金额
//account类组合了两个类的函数和变量。

#include<iostream>
#include<string>
using namespace std;



class person
{
private:
	string name;
	int ID;
public:
	person(string name, int ID) :name(name), ID(ID) {}  //使用初始化列表的方法进行类的初始化，包含name和ID
	void print(void)
	{
		cout << "name=" << name << ",ID=" << ID << endl;
	}
};
class balance   //定义了用来表示账号余额的balance类，能够增加金额和显示当前余额。也是用初始化列表的方法进行初始化的。
{
private:
	int left;
	
public:
	balance(int left):left(left)
	{

	}
	void insert(int insertmoney)
	{
		this->left+= insertmoney;
	}
	void print()
	{
		cout << "left=" << left << endl;
	}
};
class account  //acount类就是person类和balance类的组合，结合了二者的变量和函数
{
private:
	person p;
	balance my_balance;
public:
	account(string name, int ID, int left) :p(name, ID), my_balance(left) {}; //person类和my_balance初始化这件事情应该由他们自己的构造函数完成，此处也是一种初始化列表的写法
	void print()
	{
		p.print();
		my_balance.print();

	}
	void insert(int insertmoney)
	{
		my_balance.insert(insertmoney);

	}
};
int main()
{

	account my_ac("realman", 123456, 133);
	my_ac.insert(100);
	my_ac.print();

	return 0;
}



//注解1：组合是类构成的一种方法，相当于在类里面引用了其他的类的定义。
//注解2：组合是一种引用，并不是父类和子类的包含关系，组合构成的类，对里面包含的类没有所有权，只是一种外部引用。而父类和子类是相当于把父类里面有的东西，直接复制进了子类
//注解3：组合是外部引用，继承是内部包含。