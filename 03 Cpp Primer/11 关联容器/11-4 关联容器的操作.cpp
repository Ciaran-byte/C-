#include<iostream>
#include<map>
#include<utility>
using namespace std;
int main()
{
	map<string, int> mp;
	//01 插入操作
	mp.insert({ "nihao",1 });
	mp.insert(make_pair("hah", 2));
	auto p=mp.insert(pair<string, int>("ok", 3));

	//02 查看插入操作的返回值，返回值是pair类型，first保存的是插入元素的指针，second保存的是bool类型的元素，告知插入是否成功
	cout << (p.first)->first << endl;
	cout << (p.first)->second << endl;
	cout << p.second << endl;

	//如果元素已经存在，那么insert的second值就会为false

	//03 删除操作
	map<string, int> del = { {"Aa",1},{"Bb",2 },{"Cc",3} };
	del.erase(del.begin());  //通用删除函数
	del.erase(del.begin(), del.end()); //通用删除函数


	map<string, int> de2 = { {"Aa",1},{"Bb",2 },{"Cc",3} };
	cout << de2.erase("Aa") << endl;//返回值为删除了几个该关键词元素，map因为不允许重复，所以返回值只有0或者1

	multimap<string, int> de3 = { {"Aa",1}, {"Aa",2}, {"Aa",3} };
	cout << de3.erase("Aa") << endl;//multimap允许有 重复的关键词，所以删除返回值为3
	
									
	//04 map下标操作
	//缺点，如果容器内没有查找的值，会自动创建，如果不希望这样，就使用find来查找

	//只能对map和unordered_map进行下标操作，multi的因为关键词不唯一，没法做下标操作
	

	map<string, int> de4 = { {"Aa",1},{"Bb",2 },{"Cc",3} };

	//两种写法
	cout << de4["Aa"] << endl;
	cout << de4.at("Aa") << endl;


	//05 访问元素
	//05-1 find和count
	//对于非multi的容器，find和count其实效果一样
	//而multi的容器，通过conut操作能够做更多的事情‘

	multimap<string, int> de5= { {"Aa",1}, {"Aa",2}, {"Aa",3} };
	map<string, int> de6 = { {"Aa",1},{"Bb",2 },{"Cc",3} };
	cout<<de5.count("Aa")<< endl;
	cout << de6.count("Aa") << endl;
	cout << de6.find("Aa")->second << endl; //find函数返回迭代器，count函数返回int

	//两种等价的搜索操作
	if(de6.find("Aa")!=de6.end()){}
	if(de6.count("Aa")){}
	
	//05-2 下面的返回值都是迭代器
	//upper_bound(k) 返回第一个关键字大于k的元素a>b
	//equal_range(k) 返回第一个关键字等于k的元素
	//lower_bound(k) 返回第一个关键字不小于k的元素 a>=b

	//05 - 3 在multi的容器中查找元素

	return 0;
}






