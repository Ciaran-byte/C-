#pragma once
#pragma once
/**
* @file Observer1.h
*  @brief �ô���ģ����ͨ����������ʾ�ļ��ָ����Ľ���
*
* */
#include<iostream>
using namespace std;


//�ڶ��ִ�������ķ���
//- ͨ������ӿ���ʵ������
//- ���ִ��������ŵ��ǣ��������������˳������ļ��ָ�����ͽ���ʵ���˽����
//- ���ִ�������ȱ���ǣ�ֻ��ʵ��һ���۲��ߣ���������������ͬʱʹ�ö���۲���֪ͨ״̬�ı䣨����ʹ�ö�����������仯��


//�ӿ�
class IProgress
{
public:
	virtual void DoProgress(float value) = 0;
	virtual ~IProgress(){}
};


//������
class MainForm :public Form,public IProgress //ʹ����c++�Ķ�̳У�c++��̳�ֻ�ʺ��ڶ�̳нӿڣ���Ӧ������������;����һ�������̳��࣬�������ǽӿڣ�
{
private:
	TextBox* txFilePath; //�ļ�·��
	TextBox* txFileNumber; //ϣ���ָ���ļ�����

	ProgressBar* progressBar; //�۲���
public:
	void Button1_Click()
	{
		string filePath = txFilePath->getText();
		int number = atoi(txFileNumber->getText().c_str());

		FileSplitter splitter(filePath, number, this); //ʹ�÷ָ�������ָ��·���ļ����зָ�

		splitter.split();
	}

	virtual void DoProgress(float value)
	{
		progressBar->setValue(value);
	}

};


class FileSplitter //�ļ��ָ���
{
	string m_filePath;
	int m_fileNumber;

//ProgressBar* m_progressBar;  //֪ͨ�ؼ�
	IProgress* m_iprogress; //�����֪ͨ����
public:
	FileSplitter(const string& filePath, int fileNumber, IProgress* iprogress) :
		m_filePath(filePath), m_fileNumber(fileNumber), m_iprogress(iprogress) {}
	void split()
	{
		//01 ������ļ�

		//02 ������С�ļ�д��
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
			m_iprogress->DoProgress(value); //ʹ��֪ͨ���ƽ���֪ͨ
		}
	}

};