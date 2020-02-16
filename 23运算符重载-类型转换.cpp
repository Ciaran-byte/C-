
//使用的类定义
class one//测试代码1
{
	
};

class two//测试代码1：说明通过析构函数的方法做类型转换
{
public:
	two(one o)
	{

	}
};

class three//测试代码2：说明加了explicit之后，不能通过析构函数做类型转换了
{
public:
	explicit three(one e)
	{

	}
};
class four //测试代码3：说明通过operator运算符重载的方法做类型转换
{
public:
	operator one()const {}
};

class five //测试代码4：说明析构函数和operator的方法同时存在，反而不能做类型转换了，因为没有优先级的差别
{
public:
	operator six()const {} //five类可以变成six类通过强制类型转换
};
class six  //测试代码4：说明析构函数和operator的方法同时存在，反而不能做类型转换了，因为没有优先级的差别
{
	six(five fff){}//通过析构函数，five类可以转换成six类
};

//使用的函数定义


void f(two t)//测试代码1：说明通过析构函数的方法做类型转换
{

}



void ff(three th)//测试代码2：说明加了explicit之后，不能通过析构函数做类型转换了
{

}

void fff(one o)//测试代码3：说明通过operator运算符重载的方法做类型转换
{

}
void f_6(six s)
{}
int main()
{

	//测试代码1：配合注解3，说明通过析构函数的方法做类型转换
	{
	one o;
	f(o); //不会报错，因为two里面有一个构造函数，能够把one变成two

	//测试代码2：配合注解3，说明加了explicit之后，不能通过析构函数做类型转换了
	//ff(o); //会出错，因为three不能直接把one类型变成three类型，explicit关键词不允许

	//测试代码3:配合注解4，说明通过operator运算符重载的方法做类型转换
	four f;
	fff( f);//不会出错

    //测试代码4：配合注解5，说明析构函数和operator的方法同时存在，反而不能做类型转换了，因为没有优先级的差别
	five fffff;
	//f_6(fffff);//无法运行

}



//注解1： 类中做类型转换有两种方法，一种是通过析构函数，另外一种是通过运算符重载
//注解2： 但是最好不要使用这些方法做类型转换，因为会引起程序混乱，如果真的要做类型转换，要写成显示的函数
//注解3： 通过析构函数做类型转换之前已经接触过了，这里测试代码1可以看出是可以的。如果类的构造函数增加关键词explicit就不能进行自动的类型转换了
//注解4： 通过运算符重载的方法做类型转换，就像four类中定义的那样，可以把four类变成one 写法如 X::operator T（）const{}  把X变成T的类型转换函数
//const是说，对象不能修改自身
//注解5： 运算符重载和析构函数的方法做隐式的类型转换没有优先级，如果同时存在，系统会因为不知道该调用那个而无法运行