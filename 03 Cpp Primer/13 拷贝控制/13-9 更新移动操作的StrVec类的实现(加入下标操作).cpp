#include<iostream>
#include<memory>
#include<string>
#include<algorithm>
using namespace std;
class StrVec
{
public:
	//01 ���ƺ���
	//01-1 ���캯��
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) { cout << "Ĭ�Ϲ���" << endl; }
	StrVec(initializer_list<string> ls);
	//01-2 �������캯��
	StrVec(const StrVec& str);
	//01-3 ������ֵ����
	StrVec& operator=(const StrVec& str);
	//01-4 ��������
	~StrVec();
	//01-6 �ƶ��������캯��
	StrVec(StrVec&& vec)noexcept;
	//01-7 �ƶ���ֵ�����
	StrVec& operator=(StrVec&& vec)noexcept;

	//02 ��Ա����
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
	//���ݳ�Ա
	string* elements;
	string* first_free;
	string* cap;

	//���ߺ���
	void check_n_elem();
	void reallocate();
	void reallocate(size_t n);//�����ƶ�������ʵ��
	pair<string*, string*> copy_n(const string*, const string*);
	void free(); //����for_each+lambdaʵ��
};

allocator<string> StrVec::alloc;
//���ƺ���
StrVec::StrVec(const StrVec& str)
{
	cout << "��������" << endl;
	auto data = copy_n(str.begin(), str.end());

	elements = data.first;
	first_free = cap = data.second;


}
StrVec& StrVec::operator=(const StrVec& str)
{
	cout << "������ֵ" << endl;
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
	cout << "�б��ʼ��" << endl;
	auto newdata = copy_n(ls.begin(), ls.end());
	elements = newdata.first;
	cap = first_free = newdata.second;
}
StrVec::StrVec(StrVec&& vec)noexcept:elements(vec.elements),first_free(vec.first_free),cap(vec.cap)
{
	cout << "�ƶ�����" << endl;
	vec.elements = vec.first_free = vec.cap = nullptr;
}
StrVec& StrVec::operator=(StrVec&& vec)noexcept
{
	cout << "�ƶ���ֵ" << endl;
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
//��Ա����
void StrVec::push_back(const string& str)
{
	cout << "��ֵ���ð汾" << endl;
	check_n_elem();
	alloc.construct(first_free++, str);

}
void StrVec::push_back(string&& str)
{
	cout << "��ֵ���ð汾" << endl;
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

//���ߺ���
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
	//ʹ���ƶ�������
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

