#include<iostream>
#include<memory>
#include<vector>
using namespace std;
//���Ƕ��������࣬һ������StrBlob,�����������ָ�����͵����ݣ�����ʵ�����ݹ���
//����һ������StrBlobPtr���Ǹ�weak_ptr���������ͣ�����ָʾStrBlob�������Ƿ���Է��ʣ���߰�ȫ��


//�൱�ڶ�����һ���µ��������ͺ�һ��������
class StrBlobPtr;
class StrBlob;
class StrBlob
{
public:
	friend class StrBlobPtr;
	//���캯��
	StrBlob(){}
	StrBlob(initializer_list<string> li) :data(make_shared<vector<string>>(li)){}

	//�����ɾ��
	void push_back(const string& str)
	{
		data->push_back(str);
	}
	void pop_back()
	{
		check(0, "����Ϊ�գ��޷�ɾ��");
		data->pop_back();
	}

	//������β��Ԫ��
	string& front()
	{
		check(0, "����Ϊ�գ��޷�������Ԫ��");
		return data->front();
	}
	const string& front ()const
	{
		check(0, "����Ϊ�գ��޷�������Ԫ��");
		return data->front();
	}
	string& back()
	{
		check(0, "����Ϊ�գ��޷�����βԪ��");
		return data->back();
	}
	const string& back()const
	{
		check(0, "����Ϊ�գ��޷�����βԪ��");
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
			throw runtime_error("���ݲ����ڣ�");
		}
		if (i >= sp->size())
		{
			throw out_of_range("����Χ��");
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

