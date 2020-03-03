//程序作用：说明new和delete的用法


 #include<iostream>
using namespace std;

class A
{
private:
	int size;
public:
	A();
	~A();
	void print_size(int a);
};

A::A()
{
	cout << "这是构造函数contributor" << endl;
}


A::~A()
{
	cout << "这是析构函数decontributor" << endl;
}

void A::print_size(int a)
{
	size = a;
	cout << "size = " << size << endl;
}

int main()
{
	A* a = new A[3];
	delete []a;  //加括号析构函数运行了3次，系统没有报错
	A* b = new A[3];
	delete b;//不加括号析构函数运行了1次，同时所有内存被收回，但是这样会造成内存管理冲突而报错。
	return 0;
}

//注释1 new和delete的使用
//  new和delete本质上是c++的两种运算符，相当于申请内存空间和释放内存空间。nnew后面一定要带数据类型的，因为他会根据数据类型来为我们申请内存空间大小
//比如:    
//new int a;
//new my_calss a;
//new int a[];
//   delete与new相反，是用来释放空间的，不过new定义的时候带[]，delete释放的时候也应该写上这个括号，因为括号告诉编译器，这个地方要释放很多个东西。
//比如 
// new myclass a[];
// delete []a;得到的结果是收回内存空间，析构函数调用了[]里面的数字
// delete a; 得到的结果是收回内存空间，但是析构函数只有第一个数据得到了调用，因为编译器认为，delete只有一个对象。
//
//注释2 delete的使用建议:delete函数有两种写法 delete a;和delete []a；
//（1）不要对不是new产生的空间使用delete
//（2）不要对同一个空间delete两次
//（3）new的时候带括号，delete的时候一定也要带括号