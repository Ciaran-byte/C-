#pragma once
#include <iostream>
using namespace std;

/**
* @file Bridge.h
* @brief 该类模拟了信息的发送 
* 
* 
**/

//类的功能描述，有PC和mobile两个平台实现信息的交换
//而且不同平台上需要实现不同的功能版本，比如PC的基础版本、通用版本、高级版本等等，而Mobile也有类似的需求

//存在的问题：类的继承过于冗杂。类的数目过于庞大,分支过多



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

	virtual ~Messager(){}

};

//平台实现--PC
class PCMessagerBase :public Messager
{
public:
	virtual void PlaySound(){}
	virtual void DrawShape(){}
	virtual void WriteText(){}
	virtual void Connect(){}

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


//业务抽象--PC平台
class PCMessagerList :public PCMessagerBase
{
public:
	virtual void Login(string username, string password)
	{
		PCMessagerBase::Connect();
	}
	virtual void SendMessage(string message)
	{
	PCMessagerBase::WriteText();
	}

	virtual void SendPicture(Image image)
	{
		PCMessagerBase::DrawShape();
	}
};

class PCMessagerPerfect :public PCMessagerBase
{
public:
	virtual void Login(string username, string password)
	{
		PCMessagerBase::PlaySound();
		PCMessagerBase::Connect();
	}
	virtual void SendMessage(string message)
	{
		PCMessagerBase::PlaySound();
		PCMessagerBase::WriteText();
	}

	virtual void SendPicture(Image image)
	{
		PCMessagerBase::PlaySound();
		PCMessagerBase::DrawShape();
	}
};


//业务抽象--Mobile平台
class MobileMessageList :public MobileMessagerBase
{
	virtual void Login(string username, string password)
	{
		MobileMessagerBase::Connect();
	}
	virtual void SendMessage(string message)
	{
		MobileMessagerBase::WriteText();
	}

	virtual void SendPicture(Image image)
	{
		MobileMessagerBase::DrawShape();
	}
};

class MobileMessagerPerfect :public MobileMessagerBase
{
public:
	virtual void Login(string username, string password)
	{
		MobileMessagerBase::PlaySound();
		MobileMessagerBase::Connect();
	}
	virtual void SendMessage(string message)
	{
		MobileMessagerBase::PlaySound();
		MobileMessagerBase::WriteText();
	}

	virtual void SendPicture(Image image)
	{
		MobileMessagerBase::PlaySound();
		MobileMessagerBase::DrawShape();
	}
};


