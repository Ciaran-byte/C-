#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<iterator>
#include<functional>
#include<numeric>
#include<sstream>
using namespace std;

int main()
{
	//����������ʹ��
	//01 istream_iterator
	////01-1 istream_iteratoe����������ʹ�÷���
	
		istream_iterator<int> it(cin);
		istream_iterator<int> eof;
		vector<int> a;
		while (it != eof)
		{
			a.push_back(*it++);
		}
		for (auto i : a)
		{
			cout << i << endl;
		}
		cin.clear();
		cin.ignore(200, '\n');
	
	//01-2 ʹ���㷨������������
	istream_iterator<int> in(cin), eof2;
	
	cout << accumulate(in, eof2, 0) << endl;
	//02 ostream_iterator

	//������������÷�
	ostream_iterator<int> out_iter(cout, " ");
	vector<int> vec = { 1,2,3,4,5,6 };
	for (auto e : vec)
	{
		*out_iter++ = e;//�ȼ���cout<<e<<ends;
		//out_iter = e;//��ôдҲ��

	}
	cout << endl;

	//��������copy��������������������
	cout << endl;
	ostream_iterator<int> oos(cout, " ");
	copy(vec.begin(), vec.end(), oos);


	//03 ʹ��������������������

	return 0;
}

