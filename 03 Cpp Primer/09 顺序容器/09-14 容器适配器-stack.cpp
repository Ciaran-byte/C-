#include<iostream>
#include<deque>
#include<vector>
#include<stack>
#include<list>
using namespace std;
int main()
{
	//01 ջ�Ķ���
	stack<int, deque<int>> a;
	stack<int, vector<int>> b;
	stack<int, list<int>>  c;
	stack<int> d; //ջĬ����deque���ģ����Կ�������Ĭ�϶���

	//02 ջ�Ļ���ʹ�÷���
	
	a.push(1);
	a.push(5);
	int x = a.top();
	//top �鿴���ݲ�ɾ��
	cout << x << endl;
	a.pop();
	cout << a.top() << endl;
	//popɾ�����ݲ��鿴

	cout << a.size() << endl;
	cout << a.empty() << endl;
	return 0;
}

