#include<iostream>
#include<queue>
#include<deque>
#include<list>

using namespace std;
int main()
{
	//01 queue�Ķ��壬����ʹ��vector����Ϊvector��֧��push_front���ֲ���
	queue<int, deque<int>> a;
	queue<int, list<int>> b;
	queue<int> c;//Ĭ����deque
	//02 queue�Ļ���ʹ��

	//a.empty();
	//a.size();
	//a.front(); //�鿴��ͷ����
	//a.back();//�鿴��β����
	//a.pop(); 
	//a.push(1);

	//03 ʹ������
	b.push(10);
	b.push(15);
	b.push(20);

	
	cout << "һ����" << b.size() << endl;
	cout << "����" << b.front() << endl;//ֻ�鿴��ɾ��
	cout << "��β" << b.back() << endl;
	
	//ɾ��pop���ڶ���ɾ��
	b.pop();
	cout << b.front() << endl;

	while (b.size())
	{
		cout << "ɾ��" << b.front() << endl;
		b.pop();
	}
	if (b.empty())
	{
		cout << "����" << endl;
	}
	return 0;
}

