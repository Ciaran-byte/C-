#pragma once
#pragma once
/**
* @file Observer1.h
*  @brief 该代码模拟了通过进度条表示文件分割器的进程
*
* */
#include<iostream>
using namespace std;


//第二种处理需求的方法
//- 通过定义接口来实现需求
//- 这种处理方法的优点是，将进度条抽象了出来，文件分割器类和界面实现了解耦合
//- 这种处理方法的缺点是，只能实现一个观察者（进度条），不能同时使用多个观察者通知状态改变（不能使用多个方法描述变化）


//接口
class IProgress
{
public:
	virtual void DoProgress(float value) = 0;
	virtual ~IProgress(){}
};


//界面类
class MainForm :public Form,public IProgress //使用了c++的多继承，c++多继承只适合于多继承接口，不应该用于其他用途。（一个是主继承类，其他都是接口）
{
private:
	TextBox* txFilePath; //文件路径
	TextBox* txFileNumber; //希望分割的文件数量

	ProgressBar* progressBar; //观察者
public:
	void Button1_Click()
	{
		string filePath = txFilePath->getText();
		int number = atoi(txFileNumber->getText().c_str());

		FileSplitter splitter(filePath, number, this); //使用分割器，把指定路径文件进行分割

		splitter.split();
	}

	virtual void DoProgress(float value)
	{
		progressBar->setValue(value);
	}

};


class FileSplitter //文件分割器
{
	string m_filePath;
	int m_fileNumber;

//ProgressBar* m_progressBar;  //通知控件
	IProgress* m_iprogress; //抽象的通知机制
public:
	FileSplitter(const string& filePath, int fileNumber, IProgress* iprogress) :
		m_filePath(filePath), m_fileNumber(fileNumber), m_iprogress(iprogress) {}
	void split()
	{
		//01 读入大文件

		//02 分批向小文件写入
		for (int i = 0; i < m_fileNumber; i++)
		{
			
				float progressValue = m_fileNumber;
				progressValue = (i + 1) / progressValue;
				onProgress(progressValue);
			

		}
	}
protected:
	void onProgress(float value)
	{
		if (m_iprogress != nullptr)
		{
			m_iprogress->DoProgress(value); //使用通知机制进行通知
		}
	}

};