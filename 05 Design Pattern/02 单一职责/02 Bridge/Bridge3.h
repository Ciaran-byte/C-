#pragma once
#include <iostream>
using namespace std;

/**
* @file Bridge.h
* @brief ����ģ������Ϣ�ķ���
*
*
**/

//�汾3��Messager��Ҫ��ͬƽ̨����ʵ�ֵĲ��ֽ����˲��
//����ƽ̨�̳��˹�ͬ�Ľӿ�
//ʹ�����ʵ���˲�ͬ��ƽ̨������ʵ�ַ���


//���ǿ��Կ�����ԭ�������еĺ�����ʵ����������ͬά�Ƚ��б仯�ģ������Щ�������ʺϷŽ�ͬһ��������


//����--��ֵĵ�һ����(ҵ�����)
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

//����---��ֵĵڶ�����(ƽ̨ʵ��)
class MessagerImp
{
public:


	virtual void PlaySound() = 0;
	virtual void DrawShape() = 0;
	virtual void WriteText() = 0;
	virtual void Connect() = 0;

	virtual ~MessagerImp() {}

};


//ƽ̨ʵ��--PC
class PCMessagerImp :public MessagerImp
{
public:
	virtual void PlaySound() {}
	virtual void DrawShape() {}
	virtual void WriteText() {}
	virtual void Connect() {}

};

//ƽ̨ʵ��--Mobile
class MobileMessagerImp :public MessagerImp
{
public:
	virtual void PlaySound() {}
	virtual void DrawShape() {}
	virtual void WriteText() {}
	virtual void Connect() {}
};


//ҵ�����
//ҵ�����--Lite
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

//ҵ����� Perfect
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


//ʹ��
//�����Ŀ�� 1+m+n
void Process()
{
	//����ʱװ��
	MessagerImp* mIMP = new PCMessagerImp();
	
	Messager* m = new MessagerLite(mIMP);
	
}



