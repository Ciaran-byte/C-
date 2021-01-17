#pragma once
#pragma once
/**
* @file ProtoTtype1.h
*  @brief �ô���ģ����ͨ����������ʾ�ļ��ָ����Ľ���
*
* */
#include<iostream>
using namespace std;



//ԭ��ģʽ�ǹ���ģʽ��һ�ֱ���





//������
class MainForm :public Form
{
	SplitterFactory* factory;

public:
	MainForm(SplitterFactory* factory) :factory(factory) {}
	void Button1_Click()
	{
		ISplitter* splitter = factory->createSplitter();//ͨ���麯�����ж�̬��new
		splitter->split();
	}



};


//----------------------�ָ���------------------------
class ISplitter //����Ļ���
{

public:

	virtual void split() = 0;
	virtual ~ISplitter() {}
};


//�������
class BinarySplitter :public ISplitter //�ļ��ָ���
{
public:

	virtual void split() {}

};



class TxtSplitter :public ISplitter //�ı��ָ���
{
public:
	virtual void split() {}
};

class PictureSplitter :public ISplitter //ͼƬ�ָ���
{
public:
	virtual void split() {}
};

class VedioSplitter :public ISplitter  //��Ƶ�ָ���
{
public:
	virtual void split() {}
};

//---------------����--------------
//��������
class SplitterFactory
{
public:
	virtual ISplitter* createSplitter() = 0;
	virtual ~SplitterFactory() {}
};

//����Ĺ���
class BinarySpitterFactory :public SplitterFactory
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