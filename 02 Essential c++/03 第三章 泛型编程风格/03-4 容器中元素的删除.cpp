#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
int main()
{
	list<int> ilist = { 1,2,3,4,5,6 };
	
	//01 ��һ��ɾ���ķ���-��λ��ɾ��
	list<int>::iterator it = find(ilist.begin(), ilist.end(), 5);
	ilist.erase(it);

	//02 ɾ��һ��
	list<int>::iterator begin = find(ilist.begin(), ilist.end(), 2);
	list<int>::iterator end = find(ilist.begin(), ilist.end(), 4);
	ilist.erase(begin, end);
	//���Ӧ��ʣ��1,4,6��Ϊɾ��ɾ�ң��ұߵı߽�4�Ǳ�����������
	begin = ilist.begin();
	end = ilist.end();
	for (; begin != end; begin++)
	{
		cout << *(begin) << endl;
	}

	//ע�⣬����list��һ��˫���������������֧��ƫ�����㣬ʹ��+�޸ĵ�ַ�ǷǷ���
	


	return 0;
}

