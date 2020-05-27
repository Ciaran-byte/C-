#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class HasPtr
{
public:
	friend void swap(HasPtr& h1, HasPtr& h2);
	HasPtr(const string& str = string()) :_str(new string(str)), _i(0) {}
	HasPtr(const HasPtr& rhs) //注意：拷贝构造和运算符重载都要定义为const的引用，不然没法用
	{

		_str = new string(*rhs._str);
		_i = rhs._i;
	}
	HasPtr& operator=(const HasPtr& rhs) //一定要释放内存然后重新产生内存。
	{
		if (_str != rhs._str)
		{
			delete _str;
		}
		_str = new string(*rhs._str);
		_i = rhs._i;


		return *this;

		/* //另外一种写法
		auto str = new string(*rhs._str);
		delete _str;
		_str = str;
		i = rhs._i;
		return *this;

		*/
	}

	//拷贝并交换技术，与一个临时变量交换数据，并返回临时变量的内容。
	/*HasPtr& operator=( HasPtr s)
	{
		using std::swap;
		swap(_str, s._str);
		swap(_i, s._i);
		return *this;
	}*/
	bool operator<(const HasPtr& rhs)
	{
		return _str->size() < rhs._str->size();
	}
	string data()
	{
		return *_str;
	}
	int count()
	{
		return _i;
	}
	~HasPtr()
	{
		delete _str;
	}
private:
	string* _str;
	int _i;
};

inline void swap(HasPtr& h1, HasPtr& h2)
{
	static int i = 0;
	cout << ++i << endl;
	swap(h1._str, h2._str);
	swap(h1._i, h2._i);
}
int main()
{
	HasPtr h1("hello");
	HasPtr h2("he");
	HasPtr h3("hell");
	HasPtr h4("helloa");
	HasPtr h5("hello");
	HasPtr h6("hello");
	HasPtr h7("he");
	HasPtr h8("hell");
	HasPtr h9("helloa");
	HasPtr h10("hello");
	HasPtr h11("hello");
	HasPtr h12("he");
	HasPtr h13("hell");
	HasPtr h14("helloa");
	HasPtr h15("hello");
	HasPtr h16("hello");
	HasPtr h17("he");
	HasPtr h18("hell");
	HasPtr h19("helloa");
	HasPtr h20("hello");

	vector<HasPtr> vec;
	vec.push_back(h1);
	vec.push_back(h2);
	vec.push_back(h3);
	vec.push_back(h4);
	vec.push_back(h5);
	vec.push_back(h6);
	vec.push_back(h7);
	vec.push_back(h8);
	vec.push_back(h9);
	vec.push_back(h10);
	vec.push_back(h11);
	vec.push_back(h12);
	vec.push_back(h13);
	vec.push_back(h14);
	vec.push_back(h15);
	vec.push_back(h16);
	vec.push_back(h17);
	vec.push_back(h18);
	vec.push_back(h19);
	vec.push_back(h20);
	vec.push_back(h1);
	vec.push_back(h2);
	vec.push_back(h3);
	vec.push_back(h4);
	vec.push_back(h5);
	vec.push_back(h6);
	vec.push_back(h7);
	vec.push_back(h8);
	vec.push_back(h9);
	vec.push_back(h10);
	vec.push_back(h11);
	vec.push_back(h12);
	vec.push_back(h13);
	sort(vec.begin(), vec.end());
	auto it = vec.begin();
	for (; it != vec.end(); ++it)

	{
		cout << it->data() << endl;
	}
	
	return 0;
}

