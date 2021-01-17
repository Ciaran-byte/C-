#pragma once
/**
* @file Decorator2.h
*  @brief 该代码模拟了设计流操作库
*
* */

//版本3在版本2的基础上，把共性的Stream提取出来作为中间类
//因为网络流和文件流是基于Stream构建的，但是这两个流并不需要Stream*对象，所以把Strema*放在Stream基类中构建不合理

//与版本1相比，2和3实质是把继承转变成了组合

//业务操作
class Stream
{
public:
	virtual char Read(int number) = 0;
	virtual void Seek(int position) = 0;
	virtual void Write(char data) = 0;

	virtual ~Stream() {}
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
		//读网络流
	}

	virtual void Seek(int position)
	{
		//定位网络流
	}
	virtual void Write(char data)
	{
		//写网络流
	}
};

//扩展操作

//中间类
class DecoratorStream :public Stream
{
protected:
	Stream* stream;
	DecoratorStream(Stream* stream) :stream(stream) {}
};

//加密类:加密类可以进行合并，只要把内部的类型运行时重定义即可
//子类中又继承Stream，又有Stream对象是为了(1)保留虚函数结构的完整性（2）能够使用多态特性
class CrytoStream :public DecoratorStream
{
	
public:

	CrytoStream(Stream* stream) :DecoratorStream(stream) {}

	virtual char Read(int number)
	{
		//额外的加密操作
		stream->Read(number);//读文件流程
		//额外的加密操作
	}

	virtual void Seek(int position)
	{
		//额外的加密操作
		stream->Seek(position);
		//额外的加密操作
	}

	virtual void Write(char data)
	{
		//额外的加密操作
		stream->Write(data);
		//额外的加密操作
	}
};




//缓冲类--对流进行缓冲
class BufferStream :public DecoratorStream
{

public:
	BufferStream(Stream* stream) :DecoratorStream(stream) {}

	virtual char Read(int number)
	{
		//额外的缓冲操作
		stream->Read(number);//读流
		//额外的缓冲操作
	}

	virtual void Seek(int position)
	{
		//额外的缓冲操作
		stream->Seek(position);
		//额外的缓冲操作
	}

	virtual void Write(char data)
	{
		//额外的缓冲操作
		stream->Write(data);
		//额外的缓冲操作
	}
};






void Process()
{
	//运行时装配
	FileStream* s1 = new FileStream(); //文件流
	CrytoStream* s2 = new CrytoStream(s1); //加密文件流
	BufferStream* s3 = new BufferStream(s1); //缓冲文件流

	BufferStream* s4 = new BufferStream(s2); //加密缓冲文件流
}
