#pragma once
/**
* @file Decorator1.h
*  @brief �ô���ģ���������������
*  
* */
#include<iostream>
using namespace std;


//װ��ģʽ
//�����˵�������������������ļ����Ⱥܶ��࣬������Ҫ���м��ܡ�����Ȳ���
//�������ȱ�ݣ��̳���������ӣ������ظ����ظ�����κܶ�

//ҵ�����
class Stream
{
public:
	virtual char Read(int number) = 0;
	virtual void Seek(int position) = 0;
	virtual void Write(char data) = 0;

	virtual ~Stream(){}
};

//������--�ļ���
class FileStream :public Stream
{
public:
	virtual char Read(int number)
	{
		//���ļ���
	}

	virtual void Seek(int position)
	{
		//��λ�ļ���
	}
	virtual void Write(char data)
	{
		//д�ļ���
	}
};

//������--������
class NetworkStream :public Stream
{
public:
	virtual char Read(int number)
	{
		//���ļ���
	}

	virtual void Seek(int position)
	{
		//��λ�ļ���
	}
	virtual void Write(char data)
	{
		//д�ļ���
	}
};
//������--�����ļ�������
class CrytoFileStream :public FileStream
{
public:
	virtual char Read(int number)
	{
		//����ļ��ܲ���
		FileStream::Read(number);//���ļ�����
		//����ļ��ܲ���
	}

	virtual void Seek(int position)
	{
		//����ļ��ܲ���
		FileStream::Seek(position);
		//����ļ��ܲ���
	}

	virtual void Write(char data)
	{
		//����ļ��ܲ���
		FileStream::Write(data);
		//����ļ��ܲ���
	}
};

//������--����������������
class CrytoNetworkStream :public  NetworkStream
{
public:
	virtual char Read(int number)
	{
		//����ļ��ܲ���
		NetworkStream::Read(number);//���ļ�����
		//����ļ��ܲ���
	}

	virtual void Seek(int position)
	{
		//����ļ��ܲ���
		NetworkStream::Seek(position);
		//����ļ��ܲ���
	}

	virtual void Write(char data)
	{
		//����ļ��ܲ���
		NetworkStream::Write(data);
		//����ļ��ܲ���
	}
};


//������--���ļ����л���
class BufferFileStream :public FileStream
{
	//...
};

//������--�����������л���
class BufferNetworkStream :public NetworkStream
{
	//...
};


//���ܻ���--�ļ���

class CrytoBufferFileStream :public FileStream
{

};

//���ܻ���--������
class CrytoBufferNetworkStream :public NetworkStream
{

};

void Process()
{
	FileStream* s1;
	CrytoFileStream* s2;
	BufferFileStream* s3;
	CrytoBufferFileStream* s4;
}