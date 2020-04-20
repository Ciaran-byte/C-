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

class book: public LibMat
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
	string& title(){ return _title; }
	string& author(){ return _author; }
protected:
	string _title;
	string _author;
};

class audiobook :public book
{
public:
	
	//���ע��2�������๹�캯��Ҫ�����ำֵ�����Ҫ�ø��ඨ��Ķ���Ļ�
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
void print(LibMat& lib)
{
	lib.print();
}
int main()
{
	{
		book bk("my book", "me");
		print(bk);
		
	}

	{
		audiobook abk("my audiobook", "me", "he");
		abk.author() = "he";
		abk.narrator() = "me";
		print(abk);

	}
	return 0;
}

//ע��1�����������ʾ�˼̳кͶ�̬��ʹ�÷���������Ϊlibmat��book��libmat�������࣬audiobook��book��������


//ע��2�������濴����ʹ�ü̳У�����Ҫ�����Ļ�����и�ֵ��ʹ�ó�ʼ���б���С�ͬʱ��������ж��󣬶����Ա�
//������ʹ�ã�ֻҪ����Ķ�����public����protected��

//ע��3�����ⲿ����print��ʵ������������麯����һ�ֶ�̬�󶨣�ֻҪ����ʱ��Ż�ȥ�ж��Լ�Ҫ�����ĸ�����

//ע��4������������麯����������������Ҳ���麯����������������һЩ����û�����Ӧ����������ȥ����