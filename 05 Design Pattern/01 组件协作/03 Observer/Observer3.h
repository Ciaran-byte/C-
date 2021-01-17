
#pragma once
/**
* @file Observer1.h
*  @brief 该代码模拟了通过进度条表示文件分割器的进程
*
* */
#include<iostream>
using namespace std;


//第三种处理需求的方法
//- 通过定义接口来实现需求，并用vector储存多个接口
//- 这种处理方法的优点是，将进度条抽象了出来，文件分割器类和界面实现了解耦合，并且实现了多个观察者处理问题
//- 这第三种处理需求的方法，才是真正的观察者模式
//- 观察者模式的动机是：当目标对象(文件分割器)状态改变的时候（文件分割进程），
//该对象依赖的所有对象即观察者对象（界面进度条，打印...等），都应该得到通知并自动更新


//接口
class IProgress
{
public:
	virtual void DoProgress(float value) = 0;
	virtual ~IProgress() {}
};

//接口的子类
class ConsoleNoticer:public IProgress
{
public:
	virtual void DoProgress(float value)
	{
		cout << "..." << endl;
	}
};

//界面类,继承了接口IProgress
class MainForm :public Form, public IProgress //使用了c++的多继承，c++多继承只适合于多继承接口，不应该用于其他用途。（一个是主继承类，其他都是接口）
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

		FileSplitter splitter(filePath, number); //使用分割器，把指定路径文件进行分割


		//加入多个观察者完成对文件分割进程的监管。订阅通知
		ConsoleNoticer cn;
		splitter.add_IProgress(this);//加入第一个观察者
		splitter.add_IProgress(&cn); //加入第二个观察者

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
	vector<IProgress*> m_iprogressVector; //抽象的通知机制,支持多个观察者
public:
	FileSplitter(const string& filePath, int fileNumber) :
		m_filePath(filePath), m_fileNumber(fileNumber){}


	//添加处理器
	void add_IProgress(IProgress* iprogress)
	{
		m_iprogressVector.push_back(iprogress);
	}

	//移除处理器
	void remove_IProgress(IProgress* iprogress)
	{
		m_iprogressVector.remove(iprogress);
	}


	void split()
	{
		//01 读入大文件

		//02 分批向小文件写入
		for (int i = 0; i < m_fileNumber; i++)
		{

			float progressValue = m_fileNumber;
			progressValue = (i + 1) / progressValue;
			onProgress(progressValue); //发送通知，但是不知道谁是观察者，也不必知道谁接受到了通知


		}
	}
protected:
	void onProgress(float value)
	{
		auto it = m_iprogressVector.begin();
		for (; it != m_iprogressVector.end(); it++)
		{
			(*it)->DoProgress(value); //使用通知机制进行通知
		}
			
		
	}

};