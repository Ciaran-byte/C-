#pragma once
#include<iostream>
using namespace std;


//用来保存对象状态的类
class Memento
{
	string state;
public:
	Memento(const string& s) :state(s){}
	string getState()const { return state; }
	void setState(const string& s) { state = s; }
};


//需要保持状态的对象
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
	//创建原发器
	Originator originator;

	//存储到备忘录.
	//不破坏originator状态的情况下，捕获originator
	Memento men = originator.createMemento();

	//改变originator的状态

	//从备忘录中恢复
	originator.setMomento(men);

}