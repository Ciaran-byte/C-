#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	//01 binary_search ��ʹ�þ�����ע������Ƚ���һ������
	vector<int> ivec = { 1,3,2,6,9,4 };
	vector<int> cpy(ivec.size());
	copy(ivec.begin(), ivec.end(), cpy.begin());
	sort(cpy.begin(), cpy.end());
	
	cout << binary_search(cpy.begin(), cpy.end(), 2) << endl;

	//02 ����������ʹ�þ���
	vector<int> test = { 1,2,3 };
	vector<int>::iterator iv = search(cpy.begin(), cpy.end(), test.begin(), test.end());
	
	cout << (iv==cpy.end()) << endl;
	return 0;
}



