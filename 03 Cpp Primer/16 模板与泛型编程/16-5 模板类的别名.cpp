#include<iostream>
#include<vector>
#include<string>
using namespace std;
template<typename T> using vecV = vector<T>;
template<typename T> using twin = pair<T, int>;
int main()
{
	//01 ʹ��tepedefֻ�ܶ�ȷ����ģ��ʵ�����б��� 
		typedef vector<string> vecStr;
		
	vecStr v = { "234","34" };

	//02 ʹ��using���ԶԺ���ģ�������б���
	vecV<string> a = { "12","sdf" };

	//03 ��ģ���������ʱ��̶�����һ��
	twin<int> t;

	return 0;
}

