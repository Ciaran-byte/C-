#pragma once
class ITarget //Ŀ��ӿ�(�½ӿ�)
{
public:
	virtual void process() = 0;
};


class IAdaptee//�����ӿڣ��Ͻӿڣ�
{
public:
	virtual void foo(int data) = 0;
	virtual int bar() = 0;
};


//Adapter��Ŀ���ǰ��Ͻӿ�ת��Ϊ�½ӿ�

class Adapter :public ITarget
{

protected:
	IAdaptee* pAdaptee;
public:
	Adapter(IAdaptee* pAdaptee):pAdaptee(pAdaptee){}

	virtual void process()
	{
		int data = pAdaptee->bar();
		pAdaptee->foo(data);
	}
};



//��������
class OldClass:public IAdaptee
{
public:
	IAdaptee* pAdaptee;
	virtual void foo(int data) {}
	virtual int bar(){}
};

void process()
{
	//�ɵ���
	IAdaptee* pAdaptee = new OldClass();

	//�ӿ�ת��
	ITarget* pTarget = new Adapter(pAdaptee);

	//ʹ���µĽӿ�
	pTarget->process();
}