#pragma once
#include<iostream>
using namespace std;


//�����������״̬����
class Memento
{
	string state;
public:
	Memento(const string& s) :state(s){}
	string getState()const { return state; }
	void setState(const string& s) { state = s; }
};


//��Ҫ����״̬�Ķ���
class Originator
{
	string state;
public:
	Originator(){}
	Memento createMemento()
	{
		Memento m(state);
		return m;
	}
	void setMomento(const Memento& m)
	{
		state = m.getState();
	}
};


void process()
{
	//����ԭ����
	Originator originator;

	//�洢������¼.
	//���ƻ�originator״̬������£�����originator
	Memento men = originator.createMemento();

	//�ı�originator��״̬

	//�ӱ���¼�лָ�
	originator.setMomento(men);

}