#include<iostream>
#include<map>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>
using namespace std;

map<string, string> buildmap(ifstream& in_file) //创建字符串转换列表
{
	
	string key;
	string value;
	map<string, string> trans_build;
	while (in_file >> key, getline(in_file, value))
	{
		if (value.size() != 0)
		{
			trans_build[key] = value.substr(1); //去掉空格
		}
		else
		{
			throw runtime_error("no rule for" + key);
		}
	}
	return trans_build;
}

const string& transform(const map<string, string>& trans_map, const string& s) //实施字符串转换的函数
{
	auto it = trans_map.find(s);
	if (it != trans_map.end())
	{
		return it->second;
	}
	else
	{
		return s;
	}
}

void transform_words(ifstream& rules, ifstream& text)
{
	string sentence;
	string words;
	auto trans_map = buildmap(rules);
	while (getline(text, sentence))
	{
		istringstream ss(sentence);
		while (ss >> words)
		{
			cout << transform(trans_map, words) << ends;
		}
		cout << endl;
	}
}
int main()
{
	ifstream rules("rules.txt");
	ifstream text("text.txt");
	if (!rules || !text)
	{
		return -1;
	}
	transform_words(rules, text);

	unordered_map<int, int> a = { {1,1},{2,2},{3,3} };
	cout << a.bucket_count() << endl;
	return 0;
}

