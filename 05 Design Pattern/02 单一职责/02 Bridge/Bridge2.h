#pragma once
#include <iostream>
using namespace std;

/**
* @file Bridge.h
* @brief ����ģ������Ϣ�ķ���
*
*
**/

//�汾2ʹ��������Decorator��ģʽ
//���ڵ������ǣ�����ֻoverride�˲��ֵ��麯�������кܶ��麯��û�б�override
//��˻����ǲ��ܱ�ֱ��ʹ�õ�

//����������������ƽ̨�Ͳ�ͬ��ҵ��ģʽ�������֣���ͬ���麯���ֲ�����ʵ��



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

//ƽ̨ʵ��--PC
class PCMessagerBase :public Messager
{
public:
	virtual void PlaySound() {}
	virtual void DrawShape() {}
	virtual void WriteText() {}
	virtual void Connect() {}

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


//ҵ�����
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




