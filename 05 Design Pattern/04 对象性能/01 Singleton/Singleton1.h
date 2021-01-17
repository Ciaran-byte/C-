#pragma once
//单例模式

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


//线程不安全版本
//单线程这么写就很好
Singleton* Singleton::getInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new Singleton();
	}

	return m_instance;
}


//线程安全版本，但是锁的代价过高
Singleton* Singleton::getInstance()
{
	Lock lock; //会在函数结束的时候，锁进行析构，释放锁
	if (m_instance == nullptr)
	{
		m_instance = new Singleton();
	}

	return m_instance;
}


//双检查锁，但是由于内存读写reorder不安全
//双检查锁不好
//解决方法，使用volatile关键字，不要在多线程中对对象创建进行reorder
Singleton* Singleton::getInstance()
{
	
	if (m_instance == nullptr)
	{
		Lock lock;  //只有实例为空，需要创建的时候才加锁
		if (m_instance == nullptr)//再加一次判断是为了，防止有两个进程进入第一个判断，然后一个进程结束了以后，另外一个进程还能继续创建对象
		{
			m_instance = new Singleton();
		}
		
	}

	return m_instance;
}


//c++ 跨平台解决方案
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