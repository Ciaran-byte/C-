#pragma once
#ifndef _CONST_TEST_H_
#define _CONST_TEST_H_
#include<iostream>
#include<vector>
using namespace std;
//功能:用于测试const的成员函数与非const成员函数
//知识点: 
//1.当我们有些函数调用类内成员的时候，应该分为const版本和非const版本实现。对对象进行操作的时候,const 对象会调用
//const版本的函数，非const对象会调用非const版本的对象。把返回值写为const和非const两个版本，返回值为const的加
//入函数const限定符，就实现了重载
//2.为了提高const版本和非const版本的效率，可以让const直接调用非const对象进行实现。const版本调用非const版本中，
//涉及到了转型，就是把非const对象转const输入const函数，再把const函数返回的const对象去掉const特性。
//对于大部分案例，这种转型是不好的，但是这里这种转型是安全的。
//注意，非const不能调用const，因为逻辑上不合理，const可能修改对象，但是非const不能。
//3. 如果const函数内希望修改类中某些数据类型，可以把这些数据类型定义为mutable
//4. 虽然const的函数不能修改对象的成员，但是如果我们给函数返回了一个成员变量的指针，依旧能够修改成员
//变量。符合了const函数的逻辑，但是不能算是bitwise constness.

// TextBlock用于讲解知识点1
class TextBlock
{
public:
	TextBlock(const string& s = "1234");
	~TextBlock(){}
	const char& operator[](size_t position)const;
	char& operator[](size_t position);
private:
	string text;
};


#endif

void pnt1(TextBlock& tb);
void pnt2(const TextBlock& tb);

// TextBlock2用于讲解知识点2
class TextBlock2
{
public:
	TextBlock2(const string& s = "1234");
	~TextBlock2() {}
	const char& operator[](size_t position)const;
	char& operator[](size_t position);
private:
	string text;
};

void Bpnt1(TextBlock2& tb);

void Bpnt2(const TextBlock2& tb);
