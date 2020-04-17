#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

#ifndef stack_H
#define stack_H

class stack
{
public:
	bool empty()
	{
		return _stack.empty();
	}
	bool full()
	{
		return (_stack.size() == _stack.max_size());
	}
	bool push(const string& elem)
	{
		if (full())return false;
		
			_stack.push_back(elem);
			return true;
		
	}
	bool pop(string &elem)
	{
		if (empty())return false;
		
			elem = _stack.back();
			_stack.pop_back();
			return true;

		
	}
	bool peek(string& elem)
	{
		if (empty())return false;
		
			

		elem = _stack.back();
		return true;
	}

	size_t size()
	{
		return _stack.size();
	}
	bool myfind(string val)
	{
		if (find(_stack.begin(), _stack.end(), val) != _stack.end())return true;
		return false;
	}
	__int64 mycount(string val)
	{
		return count(_stack.begin(), _stack.end(), val);
	}
private:
	vector<string> _stack;
};


#endif