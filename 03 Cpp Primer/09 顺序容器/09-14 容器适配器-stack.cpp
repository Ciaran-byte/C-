#include<iostream>
#include<deque>
#include<vector>
#include<stack>
#include<list>
using namespace std;
int main()
{
	//01 栈的定义
	stack<int, deque<int>> a;
	stack<int, vector<int>> b;
	stack<int, list<int>>  c;
	stack<int> d; //栈默认是deque做的，所以可以这样默认定义

	//02 栈的基本使用方法
	
	a.push(1);
	a.push(5);
	int x = a.top();
	//top 查看数据不删除
	cout << x << endl;
	a.pop();
	cout << a.top() << endl;
	//pop删除数据不查看

	cout << a.size() << endl;
	cout << a.empty() << endl;
	return 0;
}

