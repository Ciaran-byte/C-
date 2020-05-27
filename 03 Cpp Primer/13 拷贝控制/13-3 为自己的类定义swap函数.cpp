#include<iostream>
#include<memory>
using namespace std;
class HasPtr3
{
public:
	friend void swap(HasPtr3& h1, HasPtr3& h2);
	HasPtr3(const string& str = string()) :_str(new string(str)), _count(new int(1)) {}
	HasPtr3(HasPtr3& rhs) :_str(_str = rhs._str), _count(rhs._count)
	{
		(*_count)++;
	}
	HasPtr3& operator=(HasPtr3& rhs)
	{
		*(rhs._count)++;
		if (-- * _count == 0)
		{
			delete _str;
			delete _count;
		}
		_str = rhs._str;
		_count = rhs._count;
		return *this;
	}
	~HasPtr3()
	{
		if (--(*_count) == 0)
		{
			delete _str;
			delete _count;
		}
	}
	const string data() const
	{
		return *_str;
	}
	const int count()const
	{
		return *_count;
	}
private:
	string* _str;
	int* _count;



};

//定义swap函数，更希望直接交换指针即可，引用了标准库中的swap函数
 inline void swap(HasPtr3& h1, HasPtr3& h2)
{
	
	 using std::swap; //这句话很重要，调用标准库中的swap来实现我们的swap
	 swap(h1._count, h2._count);
	 swap(h1._str, h2._str);
}


int main()
{
	HasPtr3 a("hellp");
	HasPtr3 b("Hellp");
	HasPtr3 c = b;
	cout << "A  " << a.data() << endl;
	cout << "A  " << a.count() << endl;
	cout << "B  " << b.data() << endl;
	cout << "B  " << b.count() << endl;
	cout << "C  " << c.data() << endl;
	cout << "C  " << c.count() << endl;
	swap(a, b);
	cout <<"A  "<<a.data() << endl;
	cout <<"A  "<< a.count() << endl;
	cout <<"B  "<<b.data() << endl;
	cout <<"B  "<<b.count() << endl;
	cout <<"C  "<< c.data() << endl;
	cout <<"C  "<< c.count() << endl;

	return 0;
}

