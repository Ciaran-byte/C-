#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
void bubble_sort(vector<int>& v, ofstream& outfile);
void bubble_sort2(vector<int>& v, ofstream *outfile=0);
void swap(int& m, int& n);

int main()
{
	//��ν�����Ժ������ļ���д��������ݵ�����أ�

	//��һ�����ļ�д��file scope�У��ú��������ܿ������������ȱ�㣺�������ͨ����̫��
	//���������ļ���һ�����������ȱ���ǣ����������������Ҫ������Ժ���ʹ�ã���ͨ��̫��
	ofstream outfile("out.txt");

	vector<int> v = { 1,3,4,5,6,7,2 };
	bubble_sort(v, outfile);

	//���������ļ���һ��Ĭ���ֻ������Ҫ��ʱ��Ŵ����ļ����ǵú��������ͺ�������ֻ����һ���ط�дĬ��ֵ��
	//�����ں�����������д����Ϊͷ�ļ��ɼ��ԱȽϸ�.
	//ע�⣬���ò���Ĭ��Ϊ�գ���������ֻ��ʹ��ָ��
	ofstream outfile2("out2.txt");
	//bubble_sort2(v, &outfile2);
	bubble_sort2(v);

	return 0;
}


void bubble_sort(vector<int>& v,ofstream &outfile)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[j] < v[i])
			{
				swap(v[j], v[i]);
			}
		}

	}
	for (int i = 0; i < v.size(); i++)
	{
		outfile << v[i] << endl;
	}
}
void bubble_sort2(vector<int>& v, ofstream *outfile)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[j] < v[i])
			{
				swap(v[j], v[i]);
			}
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		(*outfile) << v[i] << endl;
	}
}
void swap(int& m, int& n)
{
	int t;
	t = m;
	m = n;
	n = t;
}

