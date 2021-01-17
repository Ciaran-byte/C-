#pragma once
/**
* @file Observer1.h
*  @brief �ô���ģ����ͨ����������ʾ�ļ��ָ����Ľ���
*
* */
#include<iostream>
using namespace std;


//��һ�ִ�������ķ���
//- ֱ���ڽ����ж���һ���������࣬ÿ�ηָ�һ��С�ļ����͸���һ������

//�ô������󷽷���ȱ��
//- Υ���������������ԭ�򡣸߲�ģ�鲻�������ײ�ģ�飬���߶�Ӧ�������ڳ���
//- ��Ϊ���ȱ�ʾ��һ���Ժ��ʹ�ý���������ʽ
class MainForm :public Form //������
{
private:
	TextBox* txFilePath; //�ļ�·��
	TextBox* txFileNumber; //ϣ���ָ���ļ�����

	ProgressBar* progressBar; //֪ͨ�ؼ�
public:
	void Button1_Click()
	{
		string filePath = txFilePath->getText();
		int number = atoi(txFileNumber->getText().c_str());

		FileSplitter splitter(filePath, number,progressBar); //ʹ�÷ָ�������ָ��·���ļ����зָ�

		splitter.split();
	}

};


class FileSplitter //�ļ��ָ���
{
	string m_filePath;
	int m_fileNumber;

	ProgressBar* m_progressBar; //֪ͨ�ؼ�
public:
	FileSplitter(const string& filePath,int fileNumber, ProgressBar* progressBar):
		m_filePath(filePath),m_fileNumber(fileNumber),m_progressBar(progressBar){}
	void split()
	{
		//01 ������ļ�

		//02 ������С�ļ�д��
		for(int i=0;i<m_fileNumber;i++)
		{
			if (m_progressBar != nullptr)
			{
				m_progressBar->setValue((i + 1) / m_fileNumber); //���½�����
			}
			
		}
	}
};