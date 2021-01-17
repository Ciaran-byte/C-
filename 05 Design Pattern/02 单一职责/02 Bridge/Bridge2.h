#pragma once
#include <iostream>
using namespace std;

/**
* @file Bridge.h
* @brief 该类模拟了信息的发送
*
*
**/

//版本2使用了类似Decorator的模式
//存在的问题是，基类只override了部分的虚函数，还有很多虚函数没有被override
//因此基类是不能被直接使用的

//解决方法是针对两个平台和不同的业务模式进行类拆分，不同的虚函数分布进行实现



class Messager
{
public:
	virtual void Login(string username, string password) = 0;
	virtual void SendMessage(string message) = 0;
	virtual void SendPicture(Image image) = 0;

	virtual void PlaySound() = 0;
	virtual void DrawShape() = 0;
	virtual void WriteText() = 0;
	virtual void Connect() = 0;

	virtual ~Messager() {}

};

//平台实现--PC
class PCMessagerBase :public Messager
{
public:
	virtual void PlaySound() {}
	virtual void DrawShape() {}
	virtual void WriteText() {}
	virtual void Connect() {}

};

//平台实现--Mobile
class MobileMessagerBase :public Messager
{
public:
	virtual void PlaySound() {}
	virtual void DrawShape() {}
	virtual void WriteText() {}
	virtual void Connect() {}
};


//业务抽象
class MessagerLite
{
	Messager* messager;
public:
	virtual void Login(string username, string password)
	{
		messager->Connect();
	}
	virtual void SendMessage(string message)
	{
		messager->WriteText();
	}

	virtual void SendPicture(Image image)
	{
		messager->DrawShape();
	}
};

class MessagerPerfect 
{
	Messager* messager;
public:
	virtual void Login(string username, string password)
	{
		messager->PlaySound();
		messager->Connect();
	}
	virtual void SendMessage(string message)
	{
		messager->PlaySound();
		messager->WriteText();
	}

	virtual void SendPicture(Image image)
	{
		messager->PlaySound();
		messager->DrawShape();
	}
};




