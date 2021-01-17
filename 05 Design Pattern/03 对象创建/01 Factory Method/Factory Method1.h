#pragma once
#pragma once
/**
* @file Observer1.h
*  @brief �ô���ģ����ͨ����������ʾ�ļ��ָ����Ľ���
*
* */
#include<iostream>
using namespace std;


//�ô�����۲���ģʽ��ͬһ�����
//�۲���ģʽ������ļ��ָ����У��ļ��ָ�Ϊ��ͬ��С��ʱ�������������Ķ�����ܹ�ͬʱ�ı������
//���ǻ�Ӧ�ÿ��ǵ����ָ����Ƿ��б䶯�����󡣱�����ı��ļ�����Ƶ�ļ���ͼƬ�ļ��ָ��Ƿ�Ӧ���в�ͬ�ķ���



//������
class MainForm :public Form
{
private:
	TextBox* txFilePath; //�ļ�·��
	TextBox* txFileNumber; //ϣ���ָ���ļ�����
public:
	void Button1_Click()
	{
		string filePath = txFilePath->getText();
		int number = atoi(txFileNumber->getText().c_str());

		BinarySplitter* splitter = new BinarySplitter(filePath, number); //�����г�����ϸ������������һ�ֺõ����
		splitter->split();
	}



};


//----------------------�ָ���------------------------
class ISplitter //����Ļ���
{
	string m_filePath;
	int m_fileNumber;
public:
	ISplitter(const string& filePath, int fileNumber) :
		m_filePath(filePath), m_fileNumber(fileNumber) {}
	virtual void split() = 0;
	virtual ~ISplitter() {}
};

class BinarySplitter :public ISplitter //�ļ��ָ���
{



public:

	BinarySplitter(const string& filePath, int fileNumber) :ISplitter(filePath, fileNumber) {}
	virtual void split() {}

};



class TxtSplitter :public ISplitter //�ı��ָ���
{
	TxtSplitter(const string& filePath, int fileNumber) :ISplitter(filePath, fileNumber) {}
	virtual void split() {}
};

class PictureSplitter :public ISplitter //ͼƬ�ָ���
{
	PictureSplitter(const string& filePath, int fileNumber) :ISplitter(filePath, fileNumber) {}
	virtual void split() {}
};

class VedioSplitter :public ISplitter  //��Ƶ�ָ���
{
	VedioSplitter(const string& filePath, int fileNumber) :ISplitter(filePath, fileNumber) {}
	virtual void split() {}
};