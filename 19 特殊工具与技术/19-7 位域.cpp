#include<iostream>
using namespace std;

typedef unsigned Bit;
class File
{
public:
	Bit mode : 2;  //uint��32λ���ó�2λ��������
	Bit modified : 1;

	//����ʡ��
private:


};

int main()
{

	File f;
	f.mode = 4; //ֻ��2λ�����Ϊ3������4�������
	f.modified = 1;
	cout << f.mode << endl;
	cout << f.modified << endl;
	return 0;
}

