#include<iostream>
using namespace std;

//�����������ֵ����������������һ���ռ���ж���Ĵ���
//ǳ�����������ǵ�ַ�Ŀ������������֮�乲��һ��ײ����


//01 ���--������Ϊ��ֵ����
class HasPtr
{
public:
	HasPtr(const string &str = string()):_str(new string(str)),_i(0){}
	HasPtr(HasPtr& rhs)
	{
		
		_str = new string(*rhs._str);
		_i = rhs._i;
	}
	HasPtr& operator=(HasPtr& rhs) //һ��Ҫ�ͷ��ڴ�Ȼ�����²����ڴ档
	{
		if (_str != rhs._str)
		{
			delete _str;
		}
		_str = new string(*rhs._str);
		_i = rhs._i;

		
		return *this;

		/* //����һ��д��
		auto str = new string(*rhs._str);
		delete _str;
		_str = str;
		i = rhs._i;
		return *this;
		
		*/
	}
	~HasPtr()
	{
		delete _str;
	}
private:
	string* _str;
	int _i;
};

//02 ǳ����--������Ϊ��ָ�����
class HasPtr2
{
public:
	HasPtr2(const string& str = string()):_str(make_shared<string>(str)),_i(0){}
	HasPtr2(shared_ptr<string> str):_str(str),_i(0){}
	//û��Ҫ���忽������Ϳ�����ֵ�Լ�����������һһ������û������ġ�
private:
	shared_ptr<string> _str;
	int _i;
};

//03 ǳ����--�����Լ�������ָ�루���ü���)
//˼·��������Ҳ������̬�ڴ棬�����ڸ�������֮���¼�ж��ٸ�����ָ��ֵ�ڴ�
//���캯���������󣬲����½�������
//�������캯������������������������
//������ֵ��������rhs���������ݼ�lhs������
//�����������ڵ�������Ϊ0��ʱ���ͷ��ڴ����
class HasPtr3
{
public:
	HasPtr3(const string& str = string()) :_str(new string(str)),_count(new int(1)){}
	HasPtr3(HasPtr3& rhs):_str(_str = rhs._str),_count(rhs._count)
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
		if (-- (* _count) == 0)
		{
			delete _str;
			delete _count;
		}
	}
private:
	string* _str;
	int* _count;



};
int main()
{
	{
		HasPtr3 b("123");
		HasPtr3 a("234");
		b = a;
	}
	
	return 0;
}

