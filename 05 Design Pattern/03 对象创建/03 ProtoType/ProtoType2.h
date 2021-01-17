#pragma once
#pragma once
/**
* @file ProtoTtype1.h
*  @brief 该代码模拟了通过进度条表示文件分割器的进程
*
* */
#include<iostream>
using namespace std;



//原型模式是工厂模式的一种变体
//其特点是把工厂类和工厂指针指向的类合二为一的




//界面类
class MainForm :public Form
{
	ISplitter* prototype; //原型对象

public:
	MainForm(ISplitter* prototype) :prototype(prototype) {}
	void Button1_Click()
	{
		//原型对象只能克隆，不能直接使用
		ISplitter* splitter = prototype->clone();
		splitter->split();
	}



};


//----------------------分割器------------------------
//使用前提是，拷贝构造函数必须要写正确。
class ISplitter //抽象的基类
{

public:

	virtual void split() = 0;
	virtual ISplitter* clone() = 0; //通过克隆自己来创建对象
	virtual ~ISplitter() {}
};


//具体基类
class BinarySplitter :public ISplitter //文件分割器
{
public:

	virtual void split() {}
	virtual ISplitter* clone()
	{
		return new BinarySplitter(*this); //调用默认的拷贝构造函数
	}
};



class TxtSplitter :public ISplitter //文本分割器
{
public:
	virtual void split() {}
	virtual ISplitter* clone()
	{
		return new TxtSplitter(*this);
	}
};

class PictureSplitter :public ISplitter //图片分割器
{
public:
	virtual void split() {}
	virtual ISplitter* clone()
	{
		return new PictureSplitter(*this);
	}
};

class VedioSplitter :public ISplitter  //视频分割器
{
public:
	virtual void split() {}
	virtual ISplitter* clone()
	{
		return new VedioSplitter(*this);
	}

};






