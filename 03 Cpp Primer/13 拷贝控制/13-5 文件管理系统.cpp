#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
class Folder;


class Message
{
	friend class Folder;
	friend void swap(Message& lhs, Message& rhs);
public:
	//1 ���캯��
	Message(const string& str):contents(str){} //���캯����ʹ��һ��string������������и�ֵ

	//2 ���ƺ���
	//2-1 ��������
	Message(const Message& m);
	//2-2 �������ƺ���
	Message& operator=(const Message& m);
	//2-3 ��������
	~Message();

	//3 ��������
	void save(Folder& f);//�����ǵ���Ϣ���浽һ���ļ���
	void remove(Folder& f);
	
private:
	string contents; //������Ϣ����
	set<Folder*> folders; //������Ϣ���浽���ĸ��ļ�����

	void add_to_folders(const Message& m);
	void remove_from_folders();
};


class Folder
{
	friend class Message;
	friend void swap(Message& lhs, Message& rhs);
public:
	Folder(){}
	void save(Message& m)
	{
		msg.insert(&m);
		m.folders.insert(this);
	}
	void remove(Message& m)
	{
		msg.erase(&m);
		m.folders.erase(this);
	}
	~Folder()
	{
		for (auto it : msg)
		{
			it->remove(*this);
		}
	}
private:
	void addMsg(Message& msg);  //���ļ����д�����Ϣ
	void removeMsg(Message& msg);

	set<Message*> msg;  //�鿴�ļ����ж�����Щ��Ϣ
	
};

//Folder�ĺ���
void Folder::addMsg(Message& m)
{
	msg.insert(&m);
	
}
void Folder::removeMsg(Message& m)
{
	msg.erase(&m);
}

//Message�ĺ���
void Message::add_to_folders(const Message& m)
{
	for (auto it :m.folders)
	{
		it->addMsg(*this);
	}
}
void Message::remove_from_folders()
{
	for (auto it : folders)
	{
		it->removeMsg(*this);
	}
}
void Message::save(Folder& f) //����һ���ļ����ͣ���Ϣ��¼���浽���ĸ��ļ��У��ļ���¼�������ĸ��ļ�
{
	folders.insert(&f);
	f.addMsg(*this);

}
void Message::remove(Folder& f)
{
	folders.erase(&f);
}
Message::Message(const Message& m):contents(m.contents),folders(m.folders)
{
	
	add_to_folders(m);
}
Message& Message::operator=(const Message& m)
{
	remove_from_folders();
	contents = m.contents;
	folders = m.folders;
	add_to_folders(m);
	return *this;

}
Message::~Message()
{
	remove_from_folders();
}
void swap(Message& lhs, Message& rhs)
{
	using std::swap;
	for (auto f : lhs.folders)
	{
		f->removeMsg(lhs);
	}
	for (auto f : rhs.folders)
	{
		f->removeMsg(rhs);
	}
	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);
	for (auto f : lhs.folders)
	{
		f->addMsg(lhs);
	}
	for (auto f : rhs.folders)
	{
		f->addMsg(rhs);
	}

}
int main()
{
	
	
		
	



	return 0;
}

