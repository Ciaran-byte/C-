#pragma once
#ifndef _CONST_TEST_H_
#define _CONST_TEST_H_
#include<iostream>
#include<vector>
using namespace std;
//����:���ڲ���const�ĳ�Ա�������const��Ա����
//֪ʶ��: 
//1.��������Щ�����������ڳ�Ա��ʱ��Ӧ�÷�Ϊconst�汾�ͷ�const�汾ʵ�֡��Զ�����в�����ʱ��,const ��������
//const�汾�ĺ�������const�������÷�const�汾�Ķ��󡣰ѷ���ֵдΪconst�ͷ�const�����汾������ֵΪconst�ļ�
//�뺯��const�޶�������ʵ��������
//2.Ϊ�����const�汾�ͷ�const�汾��Ч�ʣ�������constֱ�ӵ��÷�const�������ʵ�֡�const�汾���÷�const�汾�У�
//�漰����ת�ͣ����ǰѷ�const����תconst����const�������ٰ�const�������ص�const����ȥ��const���ԡ�
//���ڴ󲿷ְ���������ת���ǲ��õģ�������������ת���ǰ�ȫ�ġ�
//ע�⣬��const���ܵ���const����Ϊ�߼��ϲ�����const�����޸Ķ��󣬵��Ƿ�const���ܡ�
//3. ���const������ϣ���޸�����ĳЩ�������ͣ����԰���Щ�������Ͷ���Ϊmutable
//4. ��Ȼconst�ĺ��������޸Ķ���ĳ�Ա������������Ǹ�����������һ����Ա������ָ�룬�����ܹ��޸ĳ�Ա
//������������const�������߼������ǲ�������bitwise constness.

// TextBlock���ڽ���֪ʶ��1
class TextBlock
{
public:
	TextBlock(const string& s = "1234");
	~TextBlock(){}
	const char& operator[](size_t position)const;
	char& operator[](size_t position);
private:
	string text;
};


#endif

void pnt1(TextBlock& tb);
void pnt2(const TextBlock& tb);

// TextBlock2���ڽ���֪ʶ��2
class TextBlock2
{
public:
	TextBlock2(const string& s = "1234");
	~TextBlock2() {}
	const char& operator[](size_t position)const;
	char& operator[](size_t position);
private:
	string text;
};

void Bpnt1(TextBlock2& tb);

void Bpnt2(const TextBlock2& tb);
