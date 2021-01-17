#pragma once
/**
* @file Observer1.h
*  @brief 该代码模拟了通过进度条表示文件分割器的进程
*
* */
#include<iostream>
using namespace std;


//第一种处理需求的方法
//- 直接在界面中定义一个进度条类，每次分割一次小文件，就更新一次数据

//该处理需求方法的缺陷
//- 违背了依赖倒置设计原则。高层模块不能依赖底层模块，二者都应该依赖于抽象
//- 因为进度表示不一定以后会使用进度条的形式
class MainForm :public Form //界面类
{
private:
	TextBox* txFilePath; //文件路径
	TextBox* txFileNumber; //希望分割的文件数量

	ProgressBar* progressBar; //通知控件
public:
	void Button1_Click()
	{
		string filePath = txFilePath->getText();
		int number = atoi(txFileNumber->getText().c_str());

		FileSplitter splitter(filePath, number,progressBar); //使用分割器，把指定路径文件进行分割

		splitter.split();
	}

};


class FileSplitter //文件分割器
{
	string m_filePath;
	int m_fileNumber;

	ProgressBar* m_progressBar; //通知控件
public:
	FileSplitter(const string& filePath,int fileNumber, ProgressBar* progressBar):
		m_filePath(filePath),m_fileNumber(fileNumber),m_progressBar(progressBar){}
	void split()
	{
		//01 读入大文件

		//02 分批向小文件写入
		for(int i=0;i<m_fileNumber;i++)
		{
			if (m_progressBar != nullptr)
			{
				m_progressBar->setValue((i + 1) / m_fileNumber); //更新进度条
			}
			
		}
	}
};