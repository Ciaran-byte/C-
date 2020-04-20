#include<iostream>
#include<typeinfo>
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
void print(LibMat& lib)  //�������ݲ���û��ʹ�����û���ָ��ķ�ʽ����ʹ����book��Ҳ������book���麯��
{
	lib.print();
	cout << typeid(lib).name() << endl;
	cout << (typeid(lib) == typeid(book)) << endl;

}
int main()
{
		LibMat libmat;
		book bk("my book", "me");
		
		audiobook abk("my audiobook", "me", "he");
		

		//LibMat* lb = &libmat;  //��仰��������������ִ�У���Ϊխ���ͱ䲻�ɿ�����
		//LibMat* lb = &bk;  //��仰������������ִ��
		LibMat* lb = &abk; //��仰����̬����ת�����ԣ���̬����ת�������ԣ���̬����ת���ܰѿ����ͱ��խ����
		
		//ʹ�þ�̬����ת����Ϊ��ȷ����ȫ��Ҫ�ȱ�֤�ö�̬�Ƿ�������Ҫ���Ǹ�����
		if (typeid(*lb) == typeid(book))
		{
			book* b = static_cast<book*>(lb);
			cout << b->book::author() << endl;//����������ת��ֱ���ûᱨ���
		}

	//��̬����ת����ֻ����ת���Ż�ת
		if (book *b1 = dynamic_cast<book*>(lb))
		{
			cout << "b1" << endl;
			cout << b1->book::author() << endl;//����������ת��ֱ���ûᱨ���
		}




	return 0;
}

