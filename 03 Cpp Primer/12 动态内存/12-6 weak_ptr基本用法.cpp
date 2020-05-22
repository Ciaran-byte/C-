#include<iostream>
#include<memory>
using namespace std;
int main()
{
	//01 weak_ptr描述
	//weak_ptr也跟shared_ptr一样，与别人共享动态内存，但是，不会使shared_ptr的cout增加。
	//当count为0时，即使还有weak_ptr指向内存，内存仍然会被释放

	//02 weak_ptr的定义
	//使用shared_ptr对其进行初始化

	shared_ptr<int> sp = make_shared<int>(1);
	weak_ptr<int>wp(sp);

	//03 weak_ptr的使用
	//由于weak_ptr的内存不一定是存在的，因此不能直接访问这个指针，要通过shared_ptr来访问
	//lock函数如果count为0，返回空智能指针；如果count不为0，返回shared_ptr

	shared_ptr<int> sp2 = wp.lock();
	cout << *sp2 << endl;
	cout << sp2.use_count() << endl;

	//也可以写在if中进行
	if (shared_ptr<int> sp3 = wp.lock())
	{
		cout << *sp3 << endl;
	}

	int* p = sp2.get();


	return 0;
}

