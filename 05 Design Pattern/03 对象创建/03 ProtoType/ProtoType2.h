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
//���ص��ǰѹ�����͹���ָ��ָ�����϶�Ϊһ��




//������
class MainForm :public Form
{
	ISplitter* prototype; //ԭ�Ͷ���

public:
	MainForm(ISplitter* prototype) :prototype(prototype) {}
	void Button1_Click()
	{
		//ԭ�Ͷ���ֻ�ܿ�¡������ֱ��ʹ��
		ISplitter* splitter = prototype->clone();
		splitter->split();
	}



};


//----------------------�ָ���------------------------
//ʹ��ǰ���ǣ��������캯������Ҫд��ȷ��
class ISplitter //����Ļ���
{

public:

	virtual void split() = 0;
	virtual ISplitter* clone() = 0; //ͨ����¡�Լ�����������
	virtual ~ISplitter() {}
};


//�������
class BinarySplitter :public ISplitter //�ļ��ָ���
{
public:

	virtual void split() {}
	virtual ISplitter* clone()
	{
		return new BinarySplitter(*this); //����Ĭ�ϵĿ������캯��
	}
};



class TxtSplitter :public ISplitter //�ı��ָ���
{
public:
	virtual void split() {}
	virtual ISplitter* clone()
	{
		return new TxtSplitter(*this);
	}
};

class PictureSplitter :public ISplitter //ͼƬ�ָ���
{
public:
	virtual void split() {}
	virtual ISplitter* clone()
	{
		return new PictureSplitter(*this);
	}
};

class VedioSplitter :public ISplitter  //��Ƶ�ָ���
{
public:
	virtual void split() {}
	virtual ISplitter* clone()
	{
		return new VedioSplitter(*this);
	}

};






