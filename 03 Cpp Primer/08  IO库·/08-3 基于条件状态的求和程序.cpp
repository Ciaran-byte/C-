#include<iostream>
using namespace std;
int main()
{
	int i;
	int sum = 0;
	while (cin >> i, !cin.eof())  //ʹ���˶��ű�־�����ұ��Ǹ�������Ϊѭ���ı�־����
	{
		if (cin.bad())//����ϵͳ��������������Ϊ����ֻ���׳��쳣
			throw runtime_error("system is bad");
		if (cin.fail())
		{
			cerr << "�����������⣬����һ����Ч����" << endl;
			cin.clear();//�����ǰ����ı�־λ
			cin.ignore(200,'\n');//����cin���е�200����ĸ������������з�����ǰ��ֹ�������
			continue;
		}
		sum += i;
		cout << "sum is " << sum << endl;
	}

	return 0;
}

