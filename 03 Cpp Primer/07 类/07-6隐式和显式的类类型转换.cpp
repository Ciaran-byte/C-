#include<iostream>
#include<vector>
using namespace std;

//01 例程一
class animal
{
public:
	animal(string name):_name(name){}

	
	string _name;
};


void print(animal al)
{
	cout << al._name<<endl;
}


class cat
{
public:
	cat(animal& ani) :_name(ani._name) {}

	string _name;
};
void print2(cat ct)
{
	cout << ct._name << endl;
}

//02 例程2
class pig
{
public:
	explicit pig(const string & str):_name(str){}
	string _name;

};

void pig_print(const pig& p)
{
	cout << p._name << endl;
}
int main()
{
	//01 隐式类型转换
	//01-1 只有一个参数的构造函数容易发生隐式的类型转换
	//比如我们定义了一个animal类，构造函数只需要一个string变量就可。
	//我们定义了一个函数print,用于打印animal的名字
	//那么
	string s = "cat";
	print(s);
	//我们发现如果往函数里面送入一个字符串，函数也能够运行，这就是发生了隐式的类类型转换
	//因为字符串s可以通过构造函数生成一个animal类型，所以相当于用s创建了一个临时的animal对象，然后送入函数




	//01-2 这种隐式类型转换只能发生一步
	//01-1说明的那种隐式类类型转换只能发生一次，比如这次我们有一个cat类，cat类需要一个animal对象进行构造

	//(1)使用字符串送入print2函数
	string p = "cct";
	//print2(s);//不能使用

	//(2) 使用animal送入print2函数
	animal m(p);
	print2(m);//能够使用
	//	这里第一个就不能用，第二个就可以用，为什么呢？
	//因为假设第一个可以使用，必定是字符串送入函数，通过animal的构造函数产生了animal对象，再继续从animal
	//对象的构造函数产生了cat对象，而隐式类型转换只能发生一步，这个过程发生了两次类型转换，因此是不能用的


	//而第二个函数就能够使用，正式因为animal类到cat类只需要发生一次隐式转换




	//01-3 通过关键字explicit可以消除这一影响

	//		有时候这种隐式类型转换会引发问题，所以，我们只要把构造函数定义为explicit就不会引发这种类型转换问题了
	//比如我们定义了pig类，构造函数变成了explicit的
	string str1 = "12323";
	
	//pig_print(str1); //这个时候这句话就变成错误的了，因为不允许发生类型转换


	//01-4 explicit关键字对拷贝的影响


	pig pg(str1);
	//pig p2 = p; //不能使用
	pig p3(pg);
	//		我们可以看到，当构造函数变成explicit以后，等号赋值的方法创建对象不能使用了，正是因为
	//构造函数别禁用自动转换功能后，等号不能调用构造函数了，所以，只有通过初始化的手段进行创建对象了
	//而不能通过赋值的手段创建对象了。

	animal an1(str1);
	animal an2 = an1;

	//02 显式的类型转换
	//不允许隐式类型转换之后，显式的还是可以使用的
	//02-1 显式构造
	//强制类型转换
	string pigstr = "pig";
	pig_print((pig)(pigstr));

	//02-2 显式类型转换
	pig_print(static_cast<pig>(pigstr));

	return 0;
}

