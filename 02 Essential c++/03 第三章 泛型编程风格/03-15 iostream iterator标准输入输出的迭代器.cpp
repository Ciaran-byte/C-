#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
using namespace std;
int main()

{
	vector<string> words;

	//���������
	istream_iterator<string> it(cin);
	istream_iterator<string> eof;

	//��������������ݷ��õ�������
	copy(it, eof, back_inserter(words));

	//����
	sort(words.begin(), words.end());
	
	ostream_iterator<string> os(cout, " ");

	copy(words.begin(), words.end(), os);

	return 0;
}

