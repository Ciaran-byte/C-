#include<iostream>
#include<memory>
#include<vector>
using namespace std;
int main()
{
	////01 定义
	 
	//01-1 定义内存空间分配对象
	allocator<int> a; //用于分配int内存空间的对象

	//01-2 分配内存对象 
	int* p = a.allocate(10);

	//01-3 释放内存对象
	a.deallocate(p, 10);
	   
	//02 使用详细步骤
	
	//02-1 创建内存分配对象
	allocator<string> a2;
	//02-2 分配内存空间
	string* str = a2.allocate(10);
	//02-3 构造对象
	string* q = str;

	a2.construct(q++, "hello"); //保存str的首地址，并向首地址写入hello，内存往后移动一下
	a2.construct(q++, 5, 'c'); //第二个内存位置写上5个c，内存地址继续往后移动一位

	//02-4 使用完了对象之后要把对象给析构
	while (q != str)
	{
		a2.destroy(--q);//现在q指向有东西的内存的后一位
	}

	//02-5 重新拷贝或者释放内存地址
	a2.deallocate(str, 10);


	//03 拷贝和填充未初始化内存的算法
	///案例- 把vector的元素拷贝到动态数组中，然后剩下空间用定值填充
	vector<int> vec = { 1,2,3,4 };
	allocator<int> all;
	int* my_p = all.allocate(vec.size() * 2);
	auto my_q=uninitialized_copy(vec.begin(), vec.end(), my_p);//拷贝vec中的元素到动态数组中
	uninitialized_fill_n(my_q, vec.size(), 42);

	int* out = my_p;
	for (int i = 0; i < vec.size() * 2; i++)
	{
		cout << *(out + i) << endl;
		all.destroy(out + i);
	}
	all.deallocate(my_p, vec.size() * 2);

	return 0;
}

