#pragma once
#include<iostream>
#include<map>
#include<stack>

using namespace std;

class Expression
{
public:
	virtual int interpreter(map<char, int>var) = 0;
	virtual ~Expression() {}
};


//变量表达式
class VarExpression :public Expression
{
	char key;
public:
	VarExpression(const char &key):key(key){}
	int interpreter(map<char, int> var)override
	{
		return var[key];
	}
};

//符号表达式
class SymbolExpression :public Expression
{
protected:
	Expression* left;
	Expression* right;
public:
	SymbolExpression(Expression* left, Expression* right)
	{
		this->left = left;
		this->right = right;
	}
};

//加法运算
class AddExpression :public SymbolExpression
{
	AddExpression(Expression* left, Expression* right)
		:SymbolExpression(left,right){}

	int interpreter(map<char, int> var)override
	{
		return left->interpreter(var) + right->interpreter(var);
	}
};