#pragma once

//���ڰ���1�����ܴ���һЩ��ȫ���ֲ�ʽϵͳ�����⣬subject�ò���RealSubject����
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