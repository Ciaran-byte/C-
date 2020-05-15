#include<iostream>
#include<queue>
#include<deque>
#include<list>

using namespace std;
int main()
{
	//01 queue的定义，不能使用vector，因为vector不支持push_front这种操作
	queue<int, deque<int>> a;
	queue<int, list<int>> b;
	queue<int> c;//默认是deque
	//02 queue的基本使用

	//a.empty();
	//a.size();
	//a.front(); //查看开头数据
	//a.back();//查看结尾数据
	//a.pop(); 
	//a.push(1);

	//03 使用例子
	b.push(10);
	b.push(15);
	b.push(20);

	
	cout << "一共有" << b.size() << endl;
	cout << "队首" << b.front() << endl;//只查看不删除
	cout << "队尾" << b.back() << endl;
	
	//删除pop是在队首删除
	b.pop();
	cout << b.front() << endl;

	while (b.size())
	{
		cout << "删除" << b.front() << endl;
		b.pop();
	}
	if (b.empty())
	{
		cout << "空了" << endl;
	}
	return 0;
}

