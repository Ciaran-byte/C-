#pragma once
class ITarget //目标接口(新接口)
{
public:
	virtual void process() = 0;
};


class IAdaptee//遗留接口（老接口）
{
public:
	virtual void foo(int data) = 0;
	virtual int bar() = 0;
};


//Adapter的目的是把老接口转换为新接口

class Adapter :public ITarget
{

protected:
	IAdaptee* pAdaptee;
public:
	Adapter(IAdaptee* pAdaptee):pAdaptee(pAdaptee){}

	virtual void process()
	{
		int data = pAdaptee->bar();
		pAdaptee->foo(data);
	}
};



//遗留类型
class OldClass:public IAdaptee
{
public:
	IAdaptee* pAdaptee;
	virtual void foo(int data) {}
	virtual int bar(){}
};

void process()
{
	//旧的类
	IAdaptee* pAdaptee = new OldClass();

	//接口转换
	ITarget* pTarget = new Adapter(pAdaptee);

	//使用新的接口
	pTarget->process();
}