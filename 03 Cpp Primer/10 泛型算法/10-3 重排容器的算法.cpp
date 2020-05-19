#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<numeric>
using namespace std;
int main()
{
	//01 通过sort和unique删除重复单词
	vector<string> str = {"the","quick","red","fox","jumps","over","the","slow","red","turtle" };
	sort(str.begin(), str.end());
	auto it=unique(str.begin(), str.end());
	str.erase(it, str.end());
	for (auto i : str)
	{
		cout << i << endl;
	}

	return 0;
}

