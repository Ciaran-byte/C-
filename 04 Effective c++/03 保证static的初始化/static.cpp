

//如果B类需要一个静态类A作为数据类型，直接调用的话，A可能出现没初始化的情况，会出大问题。而使用函数返回引用
//的方式进行调用，能够保证对象一定得到了初始化，并且只初始化一次。
class A
{
public:
	A(const int m):m(m){}
	int m;
};


class B
{
public:
	A& aa()
	{
		static A a(6);
		return a;
	}
};