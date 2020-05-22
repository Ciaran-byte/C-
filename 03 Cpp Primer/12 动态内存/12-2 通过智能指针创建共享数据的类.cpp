#include<iostream>
#include<memory>
#include<vector>
using namespace std;

class StrBlob
{
public:
	StrBlob():data(shared_ptr<vector<string>>()){}
	StrBlob(initializer_list<string> li):data(make_shared<vector<string>>(li)){}
	size_t size()const { return data->size(); }
	bool empty()const { return data->empty(); }


	void push_back(const string& str)
	{
		data->push_back(str);
	}

	void pop_back()
	{
		check(0, "pop_back on empty strblob");
		data->pop_back();
	}
	string& front()
	{
		check(0, "front on empty strblob");
		return data->front();
	}

	string& back()
	{
		check(0, "back on empty strblob");
		return data->front();
	}
	const string& front()const
	{
		check(0, "front on empty strblob");
		return data->front();
	}

	const string& back()const
	{
		check(0, "back on empty strblob");
		return data->front();
	}

private:
	shared_ptr<vector<string>> data;
	void check(size_t i, const string& msg) const
	{
		if (i > data->size())
		{
			throw runtime_error(msg);
		}
	}
};

int main()
{
	StrBlob b1;
	{
		StrBlob b2({ "hello","hi","good bye" });
		b1 = b2;
		b2.push_back("bye");
		cout << b2.size()<<endl;
	}
	cout << b1.size()<<endl;
	StrBlob b3 = b1;
	cout << b3.front() << endl;
	cout << b3.back() << endl;

	return 0;
}

