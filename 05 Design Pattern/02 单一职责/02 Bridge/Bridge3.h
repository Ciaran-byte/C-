#pragma once
#include <iostream>
using namespace std;

/**
* @file Bridge.h
* @brief 该类模拟了信息的发送
*
*
**/

//版本3将Messager需要不同平台单独实现的部分进行了拆分
//两个平台继承了共同的接口
//使用组合实现了不同的平台特异性实现方法


//我们可以看到，原来的类中的函数其实是往两个不同维度进行变化的，因此这些函数不适合放进同一个类里面


//基类--拆分的第一个类(业务抽象)
class Messager
{
protected:
	MessagerImp* messagerImp;
public:
	Messager(MessagerImp* messagerImp):messagerImp(messagerImp){}
	virtual void Login(string username, string password) = 0;
	virtual void SendMessage(string message) = 0;
	virtual void SendPicture(Image image) = 0;


	virtual ~Messager() {}

};

//基类---拆分的第二个类(平台实现)
class MessagerImp
{
public:


	virtual void PlaySound() = 0;
	virtual void DrawShape() = 0;
	virtual void WriteText() = 0;
	virtual void Connect() = 0;

	virtual ~MessagerImp() {}

};


//平台实现--PC
class PCMessagerImp :public MessagerImp
{
public:
	virtual void PlaySound() {}
	virtual void DrawShape() {}
	virtual void WriteText() {}
	virtual void Connect() {}

};

//平台实现--Mobile
class MobileMessagerImp :public MessagerImp
{
public:
	virtual void PlaySound() {}
	virtual void DrawShape() {}
	virtual void WriteText() {}
	virtual void Connect() {}
};


//业务抽象
//业务抽象--Lite
class MessagerLite :public Messager
{
	
public:
	MessagerLite(MessagerImp* messagerImp):Messager(messagerImp){}
	virtual void Login(string username, string password)
	{
		messagerImp->Connect();
	}
	virtual void SendMessage(string message)
	{
		messagerImp->WriteText();
	}

	virtual void SendPicture(Image image)
	{
		messagerImp->DrawShape();
	}
};

//业务抽象 Perfect
class MessagerPerfect:public Messager
{

public:
	MessagerPerfect(MessagerImp* messagerImp) :Messager(messagerImp) {}

	virtual void Login(string username, string password)
	{
		messagerImp->PlaySound();
		messagerImp->Connect();
	}
	virtual void SendMessage(string message)
	{
		messagerImp->PlaySound();
		messagerImp->WriteText();
	}

	virtual void SendPicture(Image image)
	{
		messagerImp->PlaySound();
		messagerImp->DrawShape();
	}
};


//使用
//类的数目： 1+m+n
void Process()
{
	//运行时装配
	MessagerImp* mIMP = new PCMessagerImp();
	
	Messager* m = new MessagerLite(mIMP);
	
}



