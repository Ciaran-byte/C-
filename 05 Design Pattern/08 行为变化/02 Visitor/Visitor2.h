#pragma once
#include<iostream>

using namespace std;


//使用条件：子类的个数和结构必须是确定的
class Visitor;

class Element
{
public:
	virtual void accept(Visitor& visitor) = 0;
	virtual ~Element(){}
};

class ElementA :public Element
{
public:
	void accept(Visitor& visitor)override
	{
		visitor.visitElementA(*this);
	}
};


class ElementB :public Element
{
public:
	void accept(Visitor& visitor)override
	{
		visitor.visitElementB(*this);
	}
};

class Visitor
{
public:
	virtual void visitElementA(ElementA& element) = 0;
	virtual void visitElementB(ElementB& element) = 0;
	virtual ~Visitor(){}
};

//-------------------------上面是已经做好了的设计--------------------------------------------

//-------------------------下面是因为需求改变增加的--------------------------------------------
class Visitor1 :public Visitor
{
public:
	virtual void visitElementA(ElementA& element) {}
	virtual void visitElementB(ElementB& element) {}
	virtual ~Visitor1(){}
};

class Visitor2 :public Visitor
{
public:
	virtual void visitElementA(ElementA& element) {}
	virtual void visitElementB(ElementB& element) {}
	virtual ~Visitor2() {}
};

void process()
{
	Visitor2 visitor;
	ElementB element;
	element.accept(visitor);

}