#pragma once
//����ģʽ

#include<iostream>
using namespace std;
class Singleton
{
private:
	Singleton();
	Singleton(const Singleton& ogher);
public:
	static Singleton* getInstance();
	static Singleton* m_instance;



};

Singleton* Singleton::m_instance = nullptr;


//�̲߳���ȫ�汾
//���߳���ôд�ͺܺ�
Singleton* Singleton::getInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new Singleton();
	}

	return m_instance;
}


//�̰߳�ȫ�汾���������Ĵ��۹���
Singleton* Singleton::getInstance()
{
	Lock lock; //���ں���������ʱ���������������ͷ���
	if (m_instance == nullptr)
	{
		m_instance = new Singleton();
	}

	return m_instance;
}


//˫����������������ڴ��дreorder����ȫ
//˫���������
//���������ʹ��volatile�ؼ��֣���Ҫ�ڶ��߳��жԶ��󴴽�����reorder
Singleton* Singleton::getInstance()
{
	
	if (m_instance == nullptr)
	{
		Lock lock;  //ֻ��ʵ��Ϊ�գ���Ҫ������ʱ��ż���
		if (m_instance == nullptr)//�ټ�һ���ж���Ϊ�ˣ���ֹ���������̽����һ���жϣ�Ȼ��һ�����̽������Ժ�����һ�����̻��ܼ�����������
		{
			m_instance = new Singleton();
		}
		
	}

	return m_instance;
}


//c++ ��ƽ̨�������
atomic<Singleton*> Singleton::m_instance;
std::mutex Singleton::m_mutex;

Singleton* Singleton::getInstance()
{
	Singleton* tmp = m_instance.load(std::memory_order_relaxed);
	std::atomic_thread_fence(std::memory_order_acquire);
	if (tmp == nullptr)
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		tmp = m_instance.load(std::memory_order_relaxed);
		if (tmp == nullptr)
		{
			tmp = new Singleton();
			std::atomic_thread_fence(std::memory_order_relaxed);
			m_instance.store(tmp, std::memory_order_relaxed);
		}
		
	}

	return tmp;
}