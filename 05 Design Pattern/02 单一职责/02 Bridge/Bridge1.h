#pragma once
#include <iostream>
using namespace std;

/**
* @file Bridge.h
* @brief ����ģ������Ϣ�ķ��� 
* 
* 
**/

//��Ĺ�����������PC��mobile����ƽ̨ʵ����Ϣ�Ľ���
//���Ҳ�ͬƽ̨����Ҫʵ�ֲ�ͬ�Ĺ��ܰ汾������PC�Ļ����汾��ͨ�ð汾���߼��汾�ȵȣ���MobileҲ�����Ƶ�����

//���ڵ����⣺��ļ̳й������ӡ������Ŀ�����Ӵ�,��֧����



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

//ƽ̨ʵ��--PC
class PCMessagerBase :public Messager
{
public:
	virtual void PlaySound(){}
	virtual void DrawShape(){}
	virtual void WriteText(){}
	virtual void Connect(){}

};

//ƽ̨ʵ��--Mobile
class MobileMessagerBase :public Messager
{
public:
	virtual void PlaySound() {}
	virtual void DrawShape() {}
	virtual void WriteText() {}
	virtual void Connect() {}
};


//ҵ�����--PCƽ̨
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


//ҵ�����--Mobileƽ̨
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


