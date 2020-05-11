#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;
class Person
{
public:
	string name;
	vector<string> numbers;
};
int main()
{
	
	vector<Person> vec;
	//string�����������ã��ܹ�ʵ�ֲ���ַ���������ַ���������

	//01 ����ַ���
	//������ļ��н��ж�ȡһ����¼���Ϳ��Դ�istringstream�����ַ�������ʶ�ȡ��ʵ���ַ����Ĳ��
	//phone �ļ�����һЩ�˵ĵ绰����

	ifstream infile("phone.txt");
	string s;
	while (getline(infile, s)) //�ȶ�һ�У�һ�а�������͵�绰����
	{
		
		istringstream iss(s);
		Person p;
		string numbers;
		iss >> p.name; //��һ���ַ���������
		while (iss >> numbers, !iss.eof())//������ַ������ǵ绰����
		{
			p.numbers.push_back(numbers);
		}
		iss.clear();
		vec.push_back(p);
		
	}
	auto iter = vec.begin();
	while (iter != vec.end())
	{
		cout << iter->name << endl;
		iter++;
	}
	infile.close();
	infile.open("phone.txt");

	//ֱ�������������
	cout << endl;
	cout << "ֱ�������������" << endl;
	while (getline(infile, s))
	{
		istringstream iss;
		iss.str(s);//������istringstream��д���ַ��������ߴ�ostringstream������ַ���
		string mystring;
		while (iss >> mystring)
		{
			cout << mystring << ends;
		}
		iss.clear();
		cout << endl;
	}

	//02 ʹ��ostringstream�ϲ��ַ���

	ostringstream os;
	int a = 5;
	os << "2334" << a;
	cout << os.str();
	return 0;
}

