#include<iostream>
#include<map>
#include<algorithm>
#include<utility>
using namespace std;

void my_erase(multimap<string, string>& books,const string& author)
{
	auto p = books.equal_range(author);
	if (p.first == p.second)
	{
		cout << "没有这个人" << endl;
	}
	else
	{
		books.erase(p.first, p.second);
		cout << author << "的书全部删除完毕！" << endl;
	}
}

void my_print(const multimap<string, string>& books)
{
	for (auto i : books)
	{
		cout << i.first << " <<" << i.second << ">>" << endl;
	}
}
int main()
{
	multimap<string, string> author_books = { {"Mike","A1"},{"Mike","A2"},{"Mike","A3"},{"Mike","A4"},{"John","B1"} };
	my_erase(author_books, "张飞");
	my_erase(author_books, "Mike");
	my_print(author_books);
	return 0;
}

