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
	void P()
	{
		print();
	}

	void Q()
	{
		LibMat::print();
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
		
	}

	string& narrator() { return _narrator; }
protected:
	string _narrator;

};
void print(LibMat& lib)
{
	lib.print();
}
int main()
{
	

	{
		audiobook abk("my audiobook", "me", "he");
		cout << endl;
		print(abk);
		cout << endl;
		abk.P();
		cout << endl;
		abk.Q();
		cout << endl;

	}
	return 0;
}

//ע��1����ʱ�����ǿ��ܻ������е����������е����麯�����������ǲ�ϣ������麯��������ʱ���ȷ�����ĸ���
//��Ϊ����ֻ������Լ������ĺ���������ϣ������̬�󶨵������ط�������ǰ��Ҫʹ��class scope���ţ�����ȷ
//�����ĸ����������൱���������麯�������л��ơ����纯��P���͵��õ���audiobook��print����Q���õ���libmat��print
