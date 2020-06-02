#include<iostream>
using namespace std;
template<typename T>
class SP
{
public:
	SP():p(nullptr),count(nullptr){}
	explicit SP(const T& t):p(new T(t)),count(new size_t(1)){}
	SP(const SP& sp) :p(sp.p), count(sp.count)
	{
		++*count;
	}
	SP& operator=(SP& sp)
	{
		*(sp.count)++;
		
		if (--*count == 0)
		{
			delete p;
			delete count;
		}
		p = sp.p;
		count = sp.count;
		return *this;
	}
	~SP()
	{
		if (--(*count) == 0)
		{
			delete count;
			delete p;
		}
	}
	
	T& operator*()
	{
		return *p;
	}
	T& operator*()const
	{
		return *p;
	}

private:
	T* p;
	size_t* count;
};

template<typename T>
class UP
{
public:
	UP():p(nullptr){}
	UP(const UP& up) = delete;
	UP& operator=(const UP& up) = delete;
	~UP()
	{
		if (p)
			delete p;
	}
	void reset(T* t = nullptr)
	{
		if (p)
			delete p;
		p = t;
	}

	T* release()
	{
		T* q = p;
		p = nullptr;
		return q;
	}
private:
	T* p;
	
};
int main()
{
	//shared_ptr
	SP<int> a(5);
	cout << *a << endl;


	//unique_ptr
	UP<int> p;
	p.reset(new int(5));
	UP<int> q;
	q.reset(p.release());


	return 0;
}

