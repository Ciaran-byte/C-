#include<iostream>
using namespace std;



class LibMat
{
public:
	LibMat()
	{
		cout << "������libmat�Ĺ��캯����" << endl;
	}

	virtual void print()
	{
		cout << "����libmat" << endl;
	}
	virtual ~LibMat()
	{
		cout << "������libmat������������" << endl;
		cout << endl;
	}

private:
};

class book : public LibMat
{
public:
	book(string title, string author) :_title(title), _author(author)
	{
		cout << "������book�Ĺ��캯����" << endl;
	}
	virtual void print()
	{
		cout << "����book" << endl;
		cout << "�ҵ�title��" << _title << endl;
		cout << "�ҵ�author��" << _author << endl;
	}
	virtual ~book()
	{
		cout << "������book������������" << endl;
		cout << endl;
	}
	string& title() { return _title; }
	string& author() { return _author; }
protected:
	string _title;
	string _author;
};

class audiobook :public book
{
public:

	
	audiobook(string title, string author, string narrator) :book(title, author), _narrator(narrator)
	{
		cout << "������audiobook�Ĺ��캯����" << endl;
	}

	virtual void print()
	{
		cout << "����audiobook" << endl;
		cout << "�ҵ�title��" << _title << endl;
		cout << "�ҵ�author��" << _author << endl;
		cout << "�ҵ�narrator��" << _narrator << endl;
	}

	virtual ~audiobook()
	{
		cout << "������audiobook������������" << endl;
		cout << endl;
	}

	string& narrator() { return _narrator; }
protected:
	string _narrator;

};
void print(LibMat lib)  //�������ݲ���û��ʹ�����û���ָ��ķ�ʽ����ʹ����book��Ҳ������book���麯��
{
	lib.print();
}
int main()
{
	{
		book bk("my book", "me");
		print(bk);

	}

	
	return 0;
}

