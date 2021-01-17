
#pragma once
/**
* @file Observer1.h
*  @brief �ô���ģ����ͨ����������ʾ�ļ��ָ����Ľ���
*
* */
#include<iostream>
using namespace std;


//�����ִ�������ķ���
//- ͨ������ӿ���ʵ�����󣬲���vector�������ӿ�
//- ���ִ��������ŵ��ǣ��������������˳������ļ��ָ�����ͽ���ʵ���˽���ϣ�����ʵ���˶���۲��ߴ�������
//- ������ִ�������ķ��������������Ĺ۲���ģʽ
//- �۲���ģʽ�Ķ����ǣ���Ŀ�����(�ļ��ָ���)״̬�ı��ʱ���ļ��ָ���̣���
//�ö������������ж��󼴹۲��߶��󣨽������������ӡ...�ȣ�����Ӧ�õõ�֪ͨ���Զ�����


//�ӿ�
class IProgress
{
public:
	virtual void DoProgress(float value) = 0;
	virtual ~IProgress() {}
};

//�ӿڵ�����
class ConsoleNoticer:public IProgress
{
public:
	virtual void DoProgress(float value)
	{
		cout << "..." << endl;
	}
};

//������,�̳��˽ӿ�IProgress
class MainForm :public Form, public IProgress //ʹ����c++�Ķ�̳У�c++��̳�ֻ�ʺ��ڶ�̳нӿڣ���Ӧ������������;����һ�������̳��࣬�������ǽӿڣ�
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

		FileSplitter splitter(filePath, number); //ʹ�÷ָ�������ָ��·���ļ����зָ�


		//�������۲�����ɶ��ļ��ָ���̵ļ�ܡ�����֪ͨ
		ConsoleNoticer cn;
		splitter.add_IProgress(this);//�����һ���۲���
		splitter.add_IProgress(&cn); //����ڶ����۲���

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
	vector<IProgress*> m_iprogressVector; //�����֪ͨ����,֧�ֶ���۲���
public:
	FileSplitter(const string& filePath, int fileNumber) :
		m_filePath(filePath), m_fileNumber(fileNumber){}


	//��Ӵ�����
	void add_IProgress(IProgress* iprogress)
	{
		m_iprogressVector.push_back(iprogress);
	}

	//�Ƴ�������
	void remove_IProgress(IProgress* iprogress)
	{
		m_iprogressVector.remove(iprogress);
	}


	void split()
	{
		//01 ������ļ�

		//02 ������С�ļ�д��
		for (int i = 0; i < m_fileNumber; i++)
		{

			float progressValue = m_fileNumber;
			progressValue = (i + 1) / progressValue;
			onProgress(progressValue); //����֪ͨ�����ǲ�֪��˭�ǹ۲��ߣ�Ҳ����֪��˭���ܵ���֪ͨ


		}
	}
protected:
	void onProgress(float value)
	{
		auto it = m_iprogressVector.begin();
		for (; it != m_iprogressVector.end(); it++)
		{
			(*it)->DoProgress(value); //ʹ��֪ͨ���ƽ���֪ͨ
		}
			
		
	}

};