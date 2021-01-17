#pragma once

//将枚举类型转换为抽象的基类


//跟状态有关的行为，全部变成抽象的
class NetworkState
{
public:
	NetworkState* pNext;//下一个状态
	virtual void Operation1() = 0;
	virtual void Operation2() = 0;
	virtual void Operation3() = 0;

	virtual ~NetworkState(){}
};

//定义状态
class OpenState :public NetworkState
{
	static NetworkState* m_instance;
public:
	static NetworkState* getInstance()
	{
		if (m_instance != nullptr)
		{
			m_instance = new OpenState();
		}

		return m_instance;
	}
	virtual void Operation1() { /*....*/pNext = CloseState::getInstance(); }
	virtual void Operation2(){  /*....*/pNext = ConnectState::getInstance(); }
	virtual void Operation3(){ /*....*/ pNext = OpenState::getInstance(); }
};

class CloseState :public NetworkState
{
	static NetworkState* m_instance;
public:
	static NetworkState* getInstance()
	{
		if (m_instance != nullptr)
		{
			m_instance = new OpenState();
		}

		return m_instance;
	}
	virtual void Operation1() { /*....*/ pNext = CloseState::getInstance(); }
	virtual void Operation2() { /*....*/ pNext = ConnectState::getInstance(); }
	virtual void Operation3() { /*....*/ pNext = OpenState::getInstance(); }
};


class ConnectState :public NetworkState
{
	static NetworkState* m_instance;
public:
	static NetworkState* getInstance()
	{
		if (m_instance != nullptr)
		{
			m_instance = new OpenState();
		}

		return m_instance;
	}
	virtual void Operation1() { /*....*/ pNext = CloseState::getInstance(); }
	virtual void Operation2() {  /*....*/pNext = ConnectState::getInstance(); }
	virtual void Operation3() {  /*....*/pNext = OpenState::getInstance(); }
};


//对不同状态的处理器
class NetworkProcessor
{
	NetworkState* pState;
public:
	NetworkProcessor(NetworkState* pState):pState(pState){}

	void Operation1()
	{
		pState->Operation1();
		pState = pState->pNext;
		//-----
	}

	void Operation2()
	{
		pState->Operation2();
		pState = pState->pNext;
	}

	void Operation3()
	{
		pState->Operation3();
		pState = pState->pNext;
	}
};