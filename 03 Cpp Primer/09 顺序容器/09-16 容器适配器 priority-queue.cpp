#include<iostream>
#include<queue>
#include<deque>
#include<list>
#include<list>
using namespace std;
int main()
{
	//01 说明和定义方法
	//优先级队列
	//不是先进先出，谁优先谁在前
	//比较常用的比如最大值优先队列

	//需要能够满足随机访问，所以不能使用list
	//默认是使用vector创建的
	priority_queue<int> a;

	priority_queue<int, deque<int>> b;

	//02 基本使用
	a.push(10);
	a.push(20);
	a.push(-1);

	cout << "一共有" << a.size() << endl;
	cout << a.top() << endl; //最前面的是最大的，返回最高优先级元素
	
	while (!a.empty())
	{
		
		//每次删除的都是最大的
		cout <<"删除"<< a.top() << endl;
		a.pop();
	}

	return 0;
}