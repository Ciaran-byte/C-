#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	//01 ��ʽ����
	//01-1 bool��ʽ����
	cout << "ԭʼ״̬" << endl;
	cout << "default bool values " << true << " " << false << endl;
	
	cout << "��ʽ��" << endl;
	cout << " alpha bool values " << boolalpha << true << " " << false << endl;
	
	cout << "������ʽ����Ӱ��" << endl;
	cout << "default bool values " << true << " " << false << endl; //boolaplha�����Ӱ����������ʽ

	cout << "ȥ��ʽ��" << endl;
	cout << "default bool values " << noboolalpha<<true << " " << false << endl;

	cout << "���θ�ʽ������" << endl;
	cout << "default bool values " << boolalpha<<true << " " << false<<noboolalpha << endl;
	cout << "default bool values " << true << " " << false << endl;

	//01-2 ���Ƹ�ʽ����

	cout << endl;
	cout << uppercase << endl;//��ӡ���Ƶ�ǰ������ʾΪ��д��ĸ
	cout << showbase << endl; //��ӡʱ��ʾ�����Ƕ��ٽ��Ƶ�
	cout << "default " << 1024 << endl;
	cout << "oct " << oct <<1024<< endl;
	cout << "hex " << hex << 1024 << endl;
	cout << "dec " << dec << 1024 << endl;
	cout << noshowbase << endl;//ֹͣ��ʾ�����Ƕ��ٽ��Ƶ�
	cout << nouppercase << endl;//��ǰ���ű��Сд��ĸ

	//01-3 ���ȿ���

	cout << "Precision: " << cout.precision() << " val " << sqrt(2.0) << endl;
	cout.precision(10);
	cout << "Precision: " << cout.precision() << " val " << sqrt(2.0) << endl;
	cout << setprecision(6);
	cout << "precision: " << cout.precision() << ",value: " << sqrt(2.0) << endl;
	cout.precision(6);
	//01-4 ��ѧ����������
	cout << endl;
	cout << "default " << 100*sqrt(2.0) << endl;
	cout << "scientific " << scientific << 100*sqrt(2.0) << endl;
	cout << "fixed decimal " << fixed << 100 * sqrt(2.0) << endl;
	cout << "hex " << hexfloat << 100 * sqrt(2.0) << endl;
	cout << "defaults " << defaultfloat << 100 * sqrt(2.0) << endl;

	//01-5 ��ӡС����
	cout << endl;
	cout << 10.0 << endl;
	cout << showpoint << 10.0 << noshowpoint << endl;

	//01-6 ����
	int i = -16;
	double d = 3.1415926;
	cout << "i= " << setw(12) << i << " next col" << endl;
	cout << "d= " << setw(12) << d << " next col" << endl;

	cout << left << "i= " << setw(12) << i << "next col" << endl;
	cout << "d= " << setw(12) << d << " next col" << endl;

	cout << right << "i= " << setw(12) << i << "next col" << endl;
	cout << "d= " << setw(12) << d << " next col" << endl;

	cout << internal << "i= " << setw(12) << i << "next col" << endl;
	cout << "d= " << setw(12) << d << " next col" << endl;

	cout << setfill('#');
	cout << internal << "i= " << setw(12) << i << "next col" << endl;
	cout << "d= " << setw(12) << d << " next col" << endl;
	cout << setfill(' ');


	return 0;
}

