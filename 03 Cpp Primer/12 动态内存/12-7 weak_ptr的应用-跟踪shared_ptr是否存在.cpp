#include<iostream>
#include<memory>
#include<vector>
using namespace std;
//我们定义两个类，一个类是StrBlob,保存的是智能指针类型的数据，用来实现数据共享；
//另外一个类是StrBlobPtr，是个weak_ptr的数据类型，用来指示StrBlob的数据是否可以访问，提高安全性


//相当于定义了一种新的数据类型和一个迭代器
class StrBlobPtr;
class StrBlob;
class StrBlob
{
public:
	friend class StrBlobPtr;
	//构造函数
	StrBlob(){}
	StrBlob(initializer_list<string> li) :data(make_shared<vector<string>>(li)){}

	//插入和删除
	void push_back(const string& str)
	{
		data->push_back(str);
	}
	void pop_back()
	{
		check(0, "数据为空，无法删除");
		data->pop_back();
	}

	//返回收尾的元素
	string& front()
	{
		check(0, "数据为空，无法调用首元素");
		return data->front();
	}
	const string& front ()const
	{
		check(0, "数据为空，无法调用首元素");
		return data->front();
	}
	string& back()
	{
		check(0, "数据为空，无法调用尾元素");
		return data->back();
	}
	const string& back()const
	{
		check(0, "数据为空，无法调用尾元素");
		return data->back();
	}

	StrBlobPtr begin();
	
	StrBlobPtr end();
	

private:
	void check(size_t sz, const string& msg) const
	{
		if (sz > data->size())
		{
			throw runtime_error(msg);
		}
	}
	shared_ptr<vector<string>> data;


};

class StrBlobPtr
{
public:
	friend class StrBlob;
	StrBlobPtr():_index(0){}
	StrBlobPtr(StrBlob& a, size_t index = 0) :_wptr(a.data), _index(index) { }
	string& dref()
	{
		shared_ptr<vector<string>> sp = check(_index);
		return (*sp)[_index];
	}
	const string& dref() const
	{
		shared_ptr<vector<string>> sp = check(_index);
		return (*sp)[_index];
	}

	StrBlobPtr& incr()
	{
		shared_ptr<vector<string>> sp = check(_index);
		_index++;
		return *this;
	}

	bool operator==(const StrBlobPtr& rhs)
	{
		return _index == rhs._index;

	}
	bool operator!=(const StrBlobPtr& rhs)
	{
		return _index != rhs._index;

	}
	StrBlobPtr& operator++()
	{
		_index++;
		return *this;
	}
	StrBlobPtr operator++(int)
	{
		_index++;
		return *this;
	}

private:
	shared_ptr<vector<string>> check(size_t i) const
	{
		shared_ptr<vector<string>> sp = _wptr.lock();
		if (!sp)
		{
			throw runtime_error("数据不存在！");
		}
		if (i >= sp->size())
		{
			throw out_of_range("超范围了");
		}
		return sp;
	}
	weak_ptr<vector<string>> _wptr;
	size_t _index;
};
StrBlobPtr StrBlob::begin()
{

	return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}
int main()
{
	StrBlob sb({ "hello","hi","ok" });
	StrBlobPtr ssb(sb);
	StrBlobPtr it = sb.begin();
	StrBlobPtr end = sb.end();
	for (; it != end; ++it)
	{
		cout << it.dref() << endl;
	}
	
	
	return 0;
}

