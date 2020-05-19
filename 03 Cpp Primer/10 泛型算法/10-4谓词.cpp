#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template <class valType>
bool isshorter(const valType& v1, const valType& v2)
{
	return (v1 < v2);
}
bool shorter(const string& v1, const string& v2)
{
	return (v1.size() < v2.size());
}
int main()
{
	//01 ν�ʾ��Ƿ���ֵΪbool��һ�ֺ���
	vector<int> v1 = { 1,7,3,4,5 };
	sort(v1.begin(), v1.end(), isshorter<int>);

	for (auto i : v1)
	{
		cout << i << endl;
	}

	//02 ���ַ�����������Ҫ���Ȱ����������ٰ��ֵ�˳������
	//stable_sort�����ܹ���֤�ȳ��ַ������ֵ�����
	vector<string> s = { "ac","bc","abc","ba","abcd","aaaaaaaa"};
	stable_sort(s.begin(), s.end(),shorter);
	for (auto i : s)
	{
		cout << i << endl;
	}
	//ֱ������Ļ�������ȫ�����ǰ��ֵ�˳���ŵġ�



	return 0;
}

