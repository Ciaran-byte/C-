#include<iostream>
#include<memory>
#include<string>
#include<algorithm>
using namespace std;
class StrVec
{
public:
	//01 控制函数
	//01-1 构造函数
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) { cout << "默认构造" << endl; }
	StrVec(initializer_list<string> ls);
	//01-2 拷贝构造函数
	StrVec(const StrVec& str);
	//01-3 拷贝赋值函数
	StrVec& operator=(const StrVec& str);
	//01-4 析构函数
	~StrVec();
	//01-6 移动拷贝构造函数
	StrVec(StrVec&& vec)noexcept;
	//01-7 移动赋值运算符
	StrVec& operator=(StrVec&& vec)noexcept;

	//02 成员函数
	string* begin()const { return elements; }
	string* end()const { return first_free; }
	size_t size()const { return first_free - elements; }
	size_t capacity()const { return cap - elements; }
	void push_back(const string&);
	void push_back(string&&);
	void reverse(size_t n);
	void resize(size_t n, const string& s = "");

private:
	static allocator<string> alloc;
	//数据成员
	string* elements;
	string* first_free;
	string* cap;

	//工具函数
	void check_n_elem();
	void reallocate();
	void reallocate(size_t n);//换用移动迭代器实现
	pair<string*, string*> copy_n(const string*, const string*);
	void free(); //换用for_each+lambda实现
};

allocator<string> StrVec::alloc;
//控制函数
StrVec::StrVec(const StrVec& str)
{
	cout << "拷贝构造" << endl;
	auto data = copy_n(str.begin(), str.end());

	elements = data.first;
	first_free = cap = data.second;


}
StrVec& StrVec::operator=(const StrVec& str)
{
	cout << "拷贝赋值" << endl;
	auto data = copy_n(str.begin(), str.end());
	free();
	elements = data.first;
	cap = first_free = data.second;

	return *this;
}

StrVec::~StrVec()
{
	free();
}
StrVec::StrVec(initializer_list<string> ls)
{
	cout << "列表初始化" << endl;
	auto newdata = copy_n(ls.begin(), ls.end());
	elements = newdata.first;
	cap = first_free = newdata.second;
}
StrVec::StrVec(StrVec&& vec)noexcept:elements(vec.elements),first_free(vec.first_free),cap(vec.cap)
{
	cout << "移动构造" << endl;
	vec.elements = vec.first_free = vec.cap = nullptr;
}
StrVec& StrVec::operator=(StrVec&& vec)noexcept
{
	cout << "移动赋值" << endl;
	if (this != &vec)
	{
		free();
		this->elements = vec.elements;
		this->first_free = vec.first_free;
		this->cap = vec.cap;
		vec.elements = vec.first_free = vec.cap = nullptr;
	}
	return *this;
}
//成员函数
void StrVec::push_back(const string& str)
{
	cout << "左值引用版本" << endl;
	check_n_elem();
	alloc.construct(first_free++, str);

}
void StrVec::push_back(string&& str)
{
	cout << "右值引用版本" << endl;
	check_n_elem();
	alloc.construct(first_free++, str);
}
void StrVec::reverse(size_t n)
{
	reallocate(n);
}
void StrVec::resize(size_t n, const string& s)
{
	if (n > size())
	{
		while(n>size())
			push_back(s);
		
	}
	else
	{
		while (n < size())
		{
			alloc.destroy(--first_free);
		}
	}
}

//工具函数
void StrVec::check_n_elem()
{
	if (size() == capacity())
		reallocate();
}
pair<string*, string*> StrVec::copy_n(const string* a, const string* b)
{
	auto data = alloc.allocate(b - a);
	return { data,uninitialized_copy(a,b,data) };

}

void StrVec::free()
{
	
	for_each(begin(), end(), [](string& s) {alloc.destroy(&s);  });

}
void StrVec::reallocate()
{
	size_t newSize = size() ? size() * 2 : 1;
	reallocate(newSize);

}
void StrVec::reallocate(size_t newSize)
{
	//使用移动迭代器
	auto first = alloc.allocate(newSize);
	auto last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), first);
	free();
	elements = first;
	first_free = last;
	cap = first + newSize;

}

int main()
{
	//StrVec a = {"123"};
	string c = "124";
	StrVec b = { c };
	//cout << *b.begin() << endl;
	b.push_back("23");
	b.push_back(c);


	return 0;
}

