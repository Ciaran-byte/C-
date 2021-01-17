#pragma once

//��ö������ת��Ϊ����Ļ���


//��״̬�йص���Ϊ��ȫ����ɳ����
class NetworkState
{
public:
	NetworkState* pNext;//��һ��״̬
	virtual void Operation1() = 0;
	virtual void Operation2() = 0;
	virtual void Operation3() = 0;

	virtual ~NetworkState(){}
};

//����״̬
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


//�Բ�ͬ״̬�Ĵ�����
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