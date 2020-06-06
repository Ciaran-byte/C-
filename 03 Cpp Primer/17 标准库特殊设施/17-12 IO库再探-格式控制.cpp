#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	//01 格式控制
	//01-1 bool格式控制
	cout << "原始状态" << endl;
	cout << "default bool values " << true << " " << false << endl;
	
	cout << "格式化" << endl;
	cout << " alpha bool values " << boolalpha << true << " " << false << endl;
	
	cout << "持续格式化的影响" << endl;
	cout << "default bool values " << true << " " << false << endl; //boolaplha会持续影响后面的流格式

	cout << "去格式化" << endl;
	cout << "default bool values " << noboolalpha<<true << " " << false << endl;

	cout << "单次格式化控制" << endl;
	cout << "default bool values " << boolalpha<<true << " " << false<<noboolalpha << endl;
	cout << "default bool values " << true << " " << false << endl;

	//01-2 进制格式控制

	cout << endl;
	cout << uppercase << endl;//打印进制的前导号显示为大写字母
	cout << showbase << endl; //打印时显示数字是多少进制的
	cout << "default " << 1024 << endl;
	cout << "oct " << oct <<1024<< endl;
	cout << "hex " << hex << 1024 << endl;
	cout << "dec " << dec << 1024 << endl;
	cout << noshowbase << endl;//停止显示数字是多少进制的
	cout << nouppercase << endl;//把前导号变成小写字母

	//01-3 精度控制

	cout << "Precision: " << cout.precision() << " val " << sqrt(2.0) << endl;
	cout.precision(10);
	cout << "Precision: " << cout.precision() << " val " << sqrt(2.0) << endl;
	cout << setprecision(6);
	cout << "precision: " << cout.precision() << ",value: " << sqrt(2.0) << endl;
	cout.precision(6);
	//01-4 科学计数法控制
	cout << endl;
	cout << "default " << 100*sqrt(2.0) << endl;
	cout << "scientific " << scientific << 100*sqrt(2.0) << endl;
	cout << "fixed decimal " << fixed << 100 * sqrt(2.0) << endl;
	cout << "hex " << hexfloat << 100 * sqrt(2.0) << endl;
	cout << "defaults " << defaultfloat << 100 * sqrt(2.0) << endl;

	//01-5 打印小数点
	cout << endl;
	cout << 10.0 << endl;
	cout << showpoint << 10.0 << noshowpoint << endl;

	//01-6 补白
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

