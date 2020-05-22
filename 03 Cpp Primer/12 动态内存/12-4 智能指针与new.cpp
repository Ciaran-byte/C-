#include<iostream>
#include<memory>

using namespace std;
void test(shared_ptr<int> p)
{

}
int main()
{
	//01 创建智能指针的两种方法
	shared_ptr<int> p1(new int(42));//
	shared_ptr<int>q (make_shared<int>(5));
	
	//拷贝智能指针
	shared_ptr<int>p2 = p1;

	//02 通过get获取智能指针指向的对象
	int* ptr = p1.get(); //指向动态内存地址的指针
	cout << *ptr << endl;

	//03 get函数需要注意的第一点，不要使用delete释放get指向的地址，会使智能指针失效
	//delete ptr;
	//cout << *p1 << endl;

	//04 get函数使用注意第二点，不能使用这个指针给智能指针赋值，因为相当于两个独立的智能指针指向一片内存空间
	//二者没有累加关系，当其中一个智能指针离开作用域后，内存会被清空，另外一个指针指针就会失效

	{
		//shared_ptr<int> p3(ptr);  //使用get指针给智能指针赋予初值，离开作用域后，智能智能指向地址被释放
	}
	//cout << *p1 << endl; //原来的智能指针也指向这片内存，但是上一条语句把这片内存释放完了

	shared_ptr<int> mm = make_shared<int>(5);
	mm.reset(new int(7));

	//05 除了get函数以外，使用new定义的普通指针不要与智能指针混用，也会出现类似04的现象
	int* x = new int(1024);
	{
		shared_ptr<int> pp(x);
	}

	//cout << *x << endl; //这个时候内存地址也被释放了，不能再使用x了

	//06 使用new创建的对象与智能指针的函数传递
	int* n1 = new int(5);

	//test(n1); //语法错误，不能将int*的普通指针转换为智能指针给函数赋值

	//test(new int());//语法错误，new int不能做构造函数

	test(shared_ptr<int>(n1)); //语法对，能运行，但是这个函数执行完了以后，n1指向的内存被释放了，在调用n1会产生严重错误


	return 0;
}


