#pragma once


class ISubject
{
public:
	virtual void process();
};

class SubjectProxy :public ISubject
{
public:
	virtual void process(){}
};



class RealSubject :public ISubject
{
public:
	virtual void process() {}
};


class ClientApp
{
	ISubject* subject;
public:
	ClientApp()
	{
		subject = new SubjectProxy();
	}
	void DoTask()
	{
		subject->process();
	}
};