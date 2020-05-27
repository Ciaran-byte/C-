#include<iostream>
#include<memory>
#include<utility>
#include<algorithm>
using namespace std;
class StrVec
{
public:
	//�������ƺ���
	StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){}
	StrVec(initializer_list<string>);
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	~StrVec();

	//���ܺ���
	void push_back(const string&);
	string* begin()const { return elements; }
	string* end()const { return first_free; }
	size_t size() const
	{
		return first_free - elements;
	}
	size_t capacity() const
	{
		return cap - elements;
	}

	void reserve(size_t newcapacity);
	void resize(size_t newsize,const string& str=" ");
	
private:
	//���ߺ���
	string* elements;
	string* first_free;
	string* cap;

	static allocator<string> alloc; //���䶯̬�ڴ��

	void check_n_alloc(); //����Ƿ���Ҫ���ݵ�
	void free();//�ͷŶ�̬�ڴ�
	void reallocate(); //���ݵ�
	void reallocate(size_t n);
	pair<string*, string*> alloc_n_copy(const string*, const string*); //����ʵ�����ݿ�����
	
};
//���ܺ���
void StrVec::push_back(const string& str)
{
	check_n_alloc();
	alloc.construct(first_free++, str);
}
void StrVec::reserve(size_t newcapacity)
{
	if (capacity() < newcapacity)
	{
		
		reallocate(newcapacity);
	}
}
void StrVec::resize(size_t newsize,const string& str)
{
	if (newsize > size())
	{
		while (size() < newsize)
			push_back(str);
	}
	else
	{
		while (size() > newsize)
		{
			alloc.destroy(--first_free);
		}
	}
}
//���ߺ���
void StrVec::check_n_alloc()
{
	if (size() == capacity())
	{
		reallocate();
	}
}
//void StrVec::free()
//{
//	if (elements)
//	{
//		for (auto p =first_free;p!=elements;)
//		{
//			alloc.destroy(--p);
//		}
//		alloc.deallocate(elements, cap - elements);
//	}
//	
//	
//}
void StrVec::free()
{
	for_each(elements, first_free, [](string& c) {alloc.destroy(&c); });
}
pair<string*, string*> StrVec::alloc_n_copy(const string* str1, const string* str2)
{
	auto beg = alloc.allocate(str2 - str1);
	return { beg,uninitialized_copy(str1,str2,beg) };
}
void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);

	auto dest = newdata;
	auto ele = elements;
	for (size_t i = 0; i != size(); i++)
	{
		alloc.construct(dest++, std::move(*ele++));

	}
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;

}
void StrVec::reallocate(size_t newcapacity)
{
	

		auto newdata = alloc.allocate(newcapacity);

		auto dest = newdata;
		auto ele = elements;
		for (size_t i = 0; i != size(); i++)
		{
			alloc.construct(dest++, move(*ele++));

		}
		free();
		elements = newdata;
		first_free = dest;
		cap = elements + newcapacity;
	
}
//�������ƺ���
StrVec::StrVec(initializer_list<string> ls)
{
	auto beg = ls.begin();
	auto end = ls.end();
	auto newdata = alloc_n_copy(beg, end);
	elements = newdata.first;
	cap = first_free = newdata.second;
}
StrVec::~StrVec()
{
	free();
}
StrVec::StrVec(const StrVec& vec)
{
	auto cpy = alloc_n_copy(vec.begin(), vec.end());
	elements = cpy.first;
	first_free = cap =cpy.second;

}
StrVec& StrVec::operator=(const StrVec& vec)
{
	auto cpy = alloc_n_copy(vec.elements, vec.first_free);
	free();
	elements = cpy.first;
	first_free = cap = cpy.second;
	return *this;
}
allocator<string> StrVec::alloc;

int main()
{
	StrVec str;
	str.push_back("hello");
	str.push_back("hello");
	str.push_back("hello");
	str.reserve(100);
	str.resize(40, "he");
	StrVec str2{ "hi","ok" };
	cout << str2.size() << endl;
	cout << str.size() << endl;
	cout << str.capacity() << endl;
	return 0;
}


