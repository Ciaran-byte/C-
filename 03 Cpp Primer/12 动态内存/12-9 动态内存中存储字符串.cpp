#include<iostream>
#include<memory>
using namespace std;
void print()
{
	string s;
	cin >> s;
	char* str = new char[s.size() + 1];
	strcpy(str, s.c_str());
	cout << str << endl;
	delete []str;
}
int main()
{
	string s1 = "123";
	string s2(5,'a');
	
	char* str = new char[s1.size() + s2.size() + 1];

	strcpy(str, (s1 + s2).c_str());
	cout << str << endl;
	delete[] str;

	
	print();

	return 0;
}



