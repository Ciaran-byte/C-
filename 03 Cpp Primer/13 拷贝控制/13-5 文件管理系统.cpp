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
	//1 构造函数
	Message(const string& str):contents(str){} //构造函数，使用一个string对象给这个类进行赋值

	//2 控制函数
	//2-1 拷贝构造
	Message(const Message& m);
	//2-2 拷贝复制函数
	Message& operator=(const Message& m);
	//2-3 析构函数
	~Message();

	//3 操作函数
	void save(Folder& f);//将我们的消息保存到一个文件中
	void remove(Folder& f);
	
private:
	string contents; //保存消息内容
	set<Folder*> folders; //保存消息储存到了哪个文件夹中

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
	void addMsg(Message& msg);  //向文件夹中存入消息
	void removeMsg(Message& msg);

	set<Message*> msg;  //查看文件夹中都有哪些消息
	
};

//Folder的函数
void Folder::addMsg(Message& m)
{
	msg.insert(&m);
	
}
void Folder::removeMsg(Message& m)
{
	msg.erase(&m);
}

//Message的函数
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
void Message::save(Folder& f) //输入一个文件类型，消息记录保存到了哪个文件中，文件记录插入了哪个文件
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

