#pragma once
class Element
{
public:
	virtual void Func1() = 0;

	//比如要增加Func2
	virtual void Func2() = 0;
	virtual ~Element() {}
};

class ElementA :public Element
{
public:
	void Func1()override{}
	void Func2()override {}
};

class ElementB :public Element
{
public:
	void Func1()override {}
	void Func2()override {}
};
