#include<iostream>
#include<vector>
using namespace std;
//02 ����һ���ܹ�����Triangular��ĵ���������Ϊ��������ĺ���֮���໥���ã����԰ѵ������Ķ���ŵ���ǰ��

class Triangular_iterator
{
public:
	//���캯��
	Triangular_iterator(int index) :_index(index) {}  //����ָ��Triangular���еڼ������ֵ�index

	//���������
	bool operator==(const Triangular_iterator& rhs)const;  //�ж�������������index�Ƿ�һ��
	bool operator!=(const Triangular_iterator& rhs)const;  //�ж��Ƿ�һ��
	 
	int operator*()const;  //�õ���������������ȡTriangular������

	Triangular_iterator& operator++();  //�Ե���������ƫ������
	Triangular_iterator operator++(int);



private:
	int _index;
	void check_security();//�����������ʶ����Ƿ�ȫ
};

//01 ����һ�����������࣬��Ҫ����Ϊ����triangular����
class Triangular
{
public:
	Triangular(){}
	static bool gen_elements(int length); //�����������еĺ���
	static void display(int length); //����������Ҫ��ӡ���е�
	
	Triangular_iterator begin()const  //begin����
	{
		return Triangular_iterator(0);
	}
	Triangular_iterator end()const  //end����
	{

		return Triangular_iterator(_sequence.size());
	}
	friend class Triangular_iterator; //������Ԫ
private:
	
	static const int max_sequence = 1024; //����������Ƕ���
	static vector<int> _sequence;  //����������ݵĵط�
	
	
};

//01-1 static��Ա�����Ķ���
vector<int> Triangular::_sequence; 

//01-2�������еĺ���
bool Triangular::gen_elements(int length) 
{
	if (length<0 || length>max_sequence)
	{
		cerr << "��������ĳ��Ȳ���ȷ��" << endl;
		return false;
	}
	int size = _sequence.size();
	if (size < length)
	{
		for (int i = size; i < length; i++)
		{
			_sequence.push_back((i + 1) * (i + 2) / 2);
		}
	}
	return true;
}

//01-3 ��ӡ����
void Triangular::display(int length)
{
	if (gen_elements(length))
	{
		for (int i = 0; i < length; i++)
		{
			cout << _sequence[i] << endl;
		}
	}

}




//02-1 ����==����������������Ϊָ���λ����ͬ
bool Triangular_iterator::operator==(const Triangular_iterator& rhs)const
{
	return _index == rhs._index;
}
//02-2 ����!=����������������Ϊָ���λ����ͬ
bool Triangular_iterator::operator!=(const Triangular_iterator& rhs)const
{
	return !(*this==rhs);
}

//02-3 ����*���������ָ֤���λ�ò�Ϊ��
int Triangular_iterator::operator*()const
{
	if (Triangular::gen_elements(_index + 1))
	{
		return Triangular::_sequence[_index];
	}
	return 0;
}

//02-4���������++
Triangular_iterator& Triangular_iterator::operator++()
{

	_index++;
	return *this;
}
Triangular_iterator Triangular_iterator::operator++(int)
{
	_index++;
	return *this;
}




int main()
{
	
	Triangular tr;
	tr.gen_elements(20);
	Triangular_iterator it = tr.begin();
	Triangular_iterator end = tr.end();
	for (; it != end; it++)
	{
		cout << *it << endl;
	}
	
	return 0;
}