#include<iostream>
using namespace std;
//        ��ʾ�����в�������   ��ʾ�����в�����ֵ���ַ�������
int main(int argc,char **argv)
{
	//ע�⣬argv��0�����������в������������������֡�����������е�ʱ��Ӧ������������������
	int start, end, step;

	//�ж����������еĲ��������Ƿ�����Ҫ�����4�ǰ���argv��0���Ĳ�������
	if (argc != 4)
	{
		cout << "��������������԰���" << endl;
		return -1;
	}
	start = atoi(argv[1]);//�ַ���ת����
	end = atoi(argv[2]);
	step = atoi(argv[3]);
	for (int k = start; k < end; k += step)
	{
		cout << k << endl;
	}

	//cout << argc << endl;
	return 0;
}

