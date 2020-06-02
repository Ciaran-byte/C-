#include<iostream>
#include<vector>
#include<memory>
using namespace std;

template<typename T>
class Blob
{
public:
	Blob(){}
	Blob(const initializer_list<T> il);
	
	size_t size()const { return data->size(); }
	bool empty()const { return data->empty(); }
	void push_back(const T& t) { data->push_back(t); }
	void push_back(T&& t) { data->push_back(t); }
	void pop_back()
	{
		check(0, "over!");
		data->pop_back();
	}

	T& back()
	{
		check(0, "null!");
		return (*data)[size() - 1];
	}
	T& operator[](size_t i)
	{
		check(i, "more��");
		return (*data)[i];
	}
	Blob& f()  //����ģ����Blob�����Բ�дʵ����Blob<T>
	{
		return *this;
	}
	Blob& f2()  //����ģ����Blob�����Բ�дʵ����Blob<T>
	{
		return *this;
	}
private:
	shared_ptr<vector<T>> data;
	void check(size_t i, const string& msg)const;
	
};

//�����������ģ�庯��
template<typename T>
void Blob<T>::check(size_t i, const string& msg)const
{
	if (size() <= i)
	{
		throw out_of_range(msg);
	}
}

template<typename T>
Blob<T>::Blob(const initializer_list<T> il):data(make_shared<vector<T>>(il.begin(), il.end())){}

template<typename T>
Blob<T>& Blob<T>::f2()  //д�������棬���صľͱ�����ģ���ʵ����������ģ��
{
	return* this;
}
int main()
{
	Blob<int> b({ 1,2,3,4,4 });
	cout << b.back() << endl;
	cout << b[0] << endl;
	cout << b[1] << endl;
	cout << b[2] << endl;
	cout << b[3] << endl;
	cout << b[4] << endl;

	
	return 0;
}

