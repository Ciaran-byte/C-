#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//����Ҫʵ��һ��������ɾ�������ظ��Ĵʣ���������Щ�����������Ȱ������ţ��ٰ��ֵ��ţ���󷵻��ж��ٸ�����n���ϵĴ�
//����ӡ��Щ��

//01 ɾ���ظ���
void elimDups(vector<string>& words)
{
	sort(words.begin(), words.end());
	auto it = unique(words.begin(), words.end());
	words.erase(it, words.end());
}

//02 
void biggies(vector<string>& words, vector<string>::size_type sz)
{
	elimDups(words);
	//�Ѵʰ��������򣬵ȳ��İ��ֵ�˳������
	stable_sort(words.begin(), words.end(), [](const string& str1, const string& str2) {return str1.size() < str2.size(); });

	//Ѱ�ҳ��ȴ���sz���ַ����ĵ�����
	auto iter=find_if(words.begin(), words.end(), [sz](const string& str) -> bool 
		{return str.size() >= sz; });

	//��¼�ж��ٸ����ȴ���sz���ַ���
	auto number = words.end() - iter;

	//��ӡ��Щ�ַ���
	for_each(iter, words.end(), [](const string& str) {cout << str<< endl; });
}

int main()
{
	vector<string> str = { "hello","hi","what are you doing","hello","hi","what","what else" };
	biggies(str, 5);

	//lambda��д��
	//  [�����б�] (�����б�) -> ����ֵ���� {���ʽ}
	//���� (�����б�)�� ->����ֵ���� �������ǿ��Բ�д�ġ���д����ֵ���ͻ���ݱ��ʽ���з���
	// lambda���ʾ���һ����������������

	//���ڲ����б�����д���Ǿֲ�������ȫ�ֱ����;ֲ���̬����ֱ���þ��У�����Ҫд�ڲ����б���
	


	return 0;
}

