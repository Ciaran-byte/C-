#include<iostream>
#include<queue>
#include<deque>
#include<list>
#include<list>
using namespace std;
int main()
{
	//01 ˵���Ͷ��巽��
	//���ȼ�����
	//�����Ƚ��ȳ���˭����˭��ǰ
	//�Ƚϳ��õı������ֵ���ȶ���

	//��Ҫ�ܹ�����������ʣ����Բ���ʹ��list
	//Ĭ����ʹ��vector������
	priority_queue<int> a;

	priority_queue<int, deque<int>> b;

	//02 ����ʹ��
	a.push(10);
	a.push(20);
	a.push(-1);

	cout << "һ����" << a.size() << endl;
	cout << a.top() << endl; //��ǰ��������ģ�����������ȼ�Ԫ��
	
	while (!a.empty())
	{
		
		//ÿ��ɾ���Ķ�������
		cout <<"ɾ��"<< a.top() << endl;
		a.pop();
	}

	return 0;
}