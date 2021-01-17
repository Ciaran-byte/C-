#pragma once

//对于案例1，可能存在一些安全、分布式系统的问题，subject拿不到RealSubject对象
class ISubject
{
public:
	virtual void process();
};

class RealSubject :public ISubject
{
public:
	virtual void process(){}
};


class ClientApp
{
	ISubject* subject;
public:
	ClientApp()
	{
		subject = new RealSubject();
	}
	void DoTask()
	{
		subject->process();
	}
};