#include<iostream>
#include<fstream>
#include<iterator>
#include<algorithm>
#include<vector>

using namespace std;
class StrLen
{
public:
	StrLen(size_t threshold):_threshold(threshold){}
	bool operator()(const string& str)
	{
		return str.size() == _threshold;
	}
private:
	size_t _threshold;
};
void readStr(istream& is, vector<string>& vec)
{
	string str;
	while (is >> str)
	{
		vec.push_back(str);
	}
}
int main()
{
	ifstream in_file("text.txt");
	vector<string> vec;
	readStr(in_file, vec);
	const size_t min = 1;
	const size_t max = 11;
	for (int i = min; i < max; i++)
	{
		StrLen slenIs(i);
		cout << "长度为" << i << "的单词有" << count_if(vec.begin(), vec.end(),slenIs ) << "个" << endl;
	}

	
	return 0;
}

