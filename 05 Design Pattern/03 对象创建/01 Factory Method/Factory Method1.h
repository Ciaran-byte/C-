#pragma once
#pragma once
/**
* @file Observer1.h
*  @brief 该代码模拟了通过进度条表示文件分割器的进程
*
* */
#include<iostream>
using namespace std;


//该代码与观察者模式是同一组代码
//观察者模式解决了文件分割器中，文件分割为不同大小的时候，与其想依赖的多个类能够同时改变的问题
//但是还应该考虑到，分割器是否有变动的需求。比如对文本文件、视频文件、图片文件分割是否应该有不同的方法



//界面类
class MainForm :public Form
{
private:
	TextBox* txFilePath; //文件路径
	TextBox* txFileNumber; //希望分割的文件数量
public:
	void Button1_Click()
	{
		string filePath = txFilePath->getText();
		int number = atoi(txFileNumber->getText().c_str());

		BinarySplitter* splitter = new BinarySplitter(filePath, number); //代码中出现了细节依赖，不是一种好的设计
		splitter->split();
	}



};


//----------------------分割器------------------------
class ISplitter //抽象的基类
{
	string m_filePath;
	int m_fileNumber;
public:
	ISplitter(const string& filePath, int fileNumber) :
		m_filePath(filePath), m_fileNumber(fileNumber) {}
	virtual void split() = 0;
	virtual ~ISplitter() {}
};

class BinarySplitter :public ISplitter //文件分割器
{



public:

	BinarySplitter(const string& filePath, int fileNumber) :ISplitter(filePath, fileNumber) {}
	virtual void split() {}

};



class TxtSplitter :public ISplitter //文本分割器
{
	TxtSplitter(const string& filePath, int fileNumber) :ISplitter(filePath, fileNumber) {}
	virtual void split() {}
};

class PictureSplitter :public ISplitter //图片分割器
{
	PictureSplitter(const string& filePath, int fileNumber) :ISplitter(filePath, fileNumber) {}
	virtual void split() {}
};

class VedioSplitter :public ISplitter  //视频分割器
{
	VedioSplitter(const string& filePath, int fileNumber) :ISplitter(filePath, fileNumber) {}
	virtual void split() {}
};