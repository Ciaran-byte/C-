#include<iostream>
#include<vector>
#include<list>
#include<functional>
#include<algorithm>
using namespace std;

//01 方法一
vector<int> myFind1(const vector<int>& ivec, int val)
{
	vector<int> local_vec;
	vector<int>::const_iterator it = ivec.begin();
	vector<int>::const_iterator end = ivec.end();
	while ((it = (find_if(it, end, bind2nd(greater<int>(), val)))) != end)
	{
		local_vec.push_back(*it);
		it++;
	}
	return local_vec;
}

//02 方法二
vector<int> myFind2(const vector<int>& ivec, int val)
{
	//原始数列进行排序

	vector<int> local_vec(ivec);

	
	sort(local_vec.begin(), local_vec.end());


	
	vector<int>::iterator iter = find_if(local_vec.begin(), local_vec.end(), bind2nd(greater<int>(), val));

	local_vec.erase( local_vec.begin(),iter);
	return local_vec;

}
int main()
{
	vector<int> ivec1 = { 1,8,3,3,4,4,5,10,4,7 };
	//01 方法一，进行逐个的查找
	vector<int> dst_ivec1 = myFind1(ivec1, 5);
	for (size_t i=0; i < dst_ivec1.size(); i++)
	{
		cout << dst_ivec1[i] << endl;
	}
	cout << endl;


	//02 方法二，排序后删除不需要的部分
	vector<int> dst_ivec2 = myFind2(ivec1, 5);
	for (size_t i = 0; i < dst_ivec2.size(); i++)
	{
		cout << dst_ivec2[i] << endl;
	}
	return 0;
}

