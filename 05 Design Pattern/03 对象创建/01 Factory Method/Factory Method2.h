#pragma once
#pragma once
/**
* @file Observer1.h
*  @brief 该代码模拟了通过进度条表示文件分割器的进程
*
* */
#include<iostream>
using namespace std;


//根据依赖倒置原则，应该使用抽象的分割方法，而不应该使用具体的分割方法，应该把底层和高层的对象进行切分。






//界面类
class MainForm :public Form 
{
SplitterFactory* factory;
	
public:
	MainForm(SplitterFactory* factory):factory(factory){}
	void Button1_Click()
	{
		ISplitter* splitter = factory->createSplitter();//通过虚函数进行多态的new
		splitter->split();
	}



};


//----------------------分割器------------------------
class ISplitter //抽象的基类
{

public:
	
	virtual void split() = 0;
	virtual ~ISplitter(){}
};


//具体基类
class BinarySplitter :public ISplitter //文件分割器
{
public:

	virtual void split(){}

};



class TxtSplitter :public ISplitter //文本分割器
{
public:
	virtual void split() {}
};

class PictureSplitter :public ISplitter //图片分割器
{
public:
	virtual void split() {}
};

class VedioSplitter :public ISplitter  //视频分割器
{
public:
	virtual void split() {}
};

//---------------工厂--------------
//工厂基类
class SplitterFactory
{
public:
	virtual ISplitter* createSplitter() = 0;
	virtual ~SplitterFactory() {}
};

//具体的工厂
class BinarySpitterFactory:public SplitterFactory
{
public:
	virtual ISplitter* createSplitter() 
	{ 
		return new BinarySplitter();
	}
	
};

class TxtSpitterFactory :public SplitterFactory
{
public:
	virtual ISplitter* createSplitter()
	{
		return new TxtSplitter();
	}

};

class PictureSpitterFactory :public SplitterFactory
{
public:
	virtual ISplitter* createSplitter()
	{
		return new PictureSplitter();
	}

};

class VideoSpitterFactory :public SplitterFactory
{
public:
	virtual ISplitter* createSplitter()
	{
		return new VedioSplitter();
	}

};