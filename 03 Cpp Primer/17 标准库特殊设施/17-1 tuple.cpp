#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>
using namespace std;
typedef tuple<vector<int>::size_type,
	vector<int>::const_iterator,
	vector<int>::const_iterator> matches;

bool cmp(int a, int b)
{
	return a < b;
}
vector<matches> findBook(const vector<vector<int>>& files,  int book)
{
	vector<matches> ret;
	
	auto it = files.begin();
	

	for (; it != files.end(); ++it)
	{
		/*vector<int> svec(it->begin(), it->end());
		sort(svec.begin(), svec.end());*/
		auto found = equal_range(it->begin(), it->end(), book);
		if (found.first != found.second)
		{
			ret.push_back(make_tuple(it - files.begin(), found.first, found.second));
		}
	}
	return ret;
}

void report(istream& is, ostream& os, const vector<vector<int>>& files)
{
	int s;
	while (is >> s)
	{
		auto ret = findBook(files, s);
		if (ret.empty()) {
			cout << "空" << endl;
			continue;
		}
		for (const auto& i : ret)
		{
			os << "store " << get<0>(i)<<ends;
			auto it = get<1>(i);
			auto end = get<2>(i);
			for (; it != end; ++it)
			{
				cout << *it << ends;
			}
			cout << endl;
		}
	}
}
int main()
{
	//01 tuple基本使用
	//01-1 tuple定义和赋值
	tuple<int, double, int, string> t{1,1.0,3,"444"};
	t = make_tuple(1, 0.5, 1, "2333");

	//01-2 访问
	auto a = get<0>(t);
	cout << a << endl;

	//01-3 不确定tuple内容的情况下进行访问
	//tuple中变量数
	size_t sz = tuple_size<decltype(t)>::value;
	cout << sz << endl;

	//变量类型
	tuple_element<1, decltype(t)>::type cnt = get<1>(t);


	//01-4 tuple应用

	//使用tuple类型返回多值
	vector<vector<int>> vvstr = { {15,13,12,14},{13,11,14,15 },{12,15,17,18 } };
	

	auto it = vvstr.begin();
	for (; it != vvstr.end(); it++)
	{
		sort(it->begin(), it->end());
	}

	report(cin, cout, vvstr);
	
	

	return 0;
}

