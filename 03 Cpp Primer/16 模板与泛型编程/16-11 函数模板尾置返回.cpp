#include<iostream>
#include<vector>
using namespace std;

//01 ͨ��β�÷��ظ�ģ���������������
template<typename It>
auto fcn(It beg, It end)->decltype(*beg) //����β�÷��أ���Ϊ��ȷ��������ָ����ʲô���ͣ�����ŵ���ͷ����ʱ��beg��û���壬�޷���������
{
	///
	return *beg;
}



int main()
{
	vector<int>  vec = { 1,2,3,4 };
	
	cout << fcn(vec.begin(), vec.end()) << endl;

	return 0;
}


