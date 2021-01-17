#pragma once
/**
* @file Decorator1.h
*  @brief 该代码模拟了设计流操作库
*  
* */
#include<iostream>
using namespace std;


//装饰模式
//类设计说明：定义了网络流、文件流等很多类，并且需要进行加密、缓冲等操作
//该类设计缺陷：继承类过于冗杂，功能重复，重复代码段很多

//业务操作
class Stream
{
public:
	virtual char Read(int number) = 0;
	virtual void Seek(int position) = 0;
	virtual void Write(char data) = 0;

	virtual ~Stream(){}
};

//主体类--文件流
class FileStream :public Stream
{
public:
	virtual char Read(int number)
	{
		//读文件流
	}

	virtual void Seek(int position)
	{
		//定位文件流
	}
	virtual void Write(char data)
	{
		//写文件流
	}
};

//主体类--网络流
class NetworkStream :public Stream
{
public:
	virtual char Read(int number)
	{
		//读文件流
	}

	virtual void Seek(int position)
	{
		//定位文件流
	}
	virtual void Write(char data)
	{
		//写文件流
	}
};
//加密类--加密文件流操作
class CrytoFileStream :public FileStream
{
public:
	virtual char Read(int number)
	{
		//额外的加密操作
		FileStream::Read(number);//读文件流程
		//额外的加密操作
	}

	virtual void Seek(int position)
	{
		//额外的加密操作
		FileStream::Seek(position);
		//额外的加密操作
	}

	virtual void Write(char data)
	{
		//额外的加密操作
		FileStream::Write(data);
		//额外的加密操作
	}
};

//加密类--加密网络流流操作
class CrytoNetworkStream :public  NetworkStream
{
public:
	virtual char Read(int number)
	{
		//额外的加密操作
		NetworkStream::Read(number);//读文件流程
		//额外的加密操作
	}

	virtual void Seek(int position)
	{
		//额外的加密操作
		NetworkStream::Seek(position);
		//额外的加密操作
	}

	virtual void Write(char data)
	{
		//额外的加密操作
		NetworkStream::Write(data);
		//额外的加密操作
	}
};


//缓冲类--对文件进行缓冲
class BufferFileStream :public FileStream
{
	//...
};

//缓冲类--对网络流进行缓冲
class BufferNetworkStream :public NetworkStream
{
	//...
};


//加密缓冲--文件流

class CrytoBufferFileStream :public FileStream
{

};

//加密缓冲--网络流
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