#include<iostream>
#include<string>
using namespace std;
int main()
{
	//01 string�Ĺ���
	//01-1 ��char *����
	const char* cp= "123456";
	//��1��ֱ�ӿ�����ǰ����cp�����Կ��ַ���β
	string s(cp);
	const char cp2[2]= { '0','1'};
	string t(cp2); //��βû�п��ַ����������֪���ø��Ƶ�����ͽ���������������
	//cout << t << endl;
	
	//(2) ָ��λ�ÿ���,����ǰ����

	string s2(cp, 3);
	cout <<"s2 "<< s2 << endl;

	//(3) ָ����Χ����
	string s3(cp, 2, 6);
	cout << "s3 " << s3 << endl;
	//01-2 ��string���й���
	string S = "124444222";
	string s4 = S.substr(0, 5);
	cout << "s4 " << s4 << endl;

	//02 �ı�string�������취
	//assign,insert,erase

	//03 append��replace
	//03-1 append�ǽ��ַ������뵽����һ���ַ��������
	string s5 = "cpp";
	string s6 = " primer";
	s5.append(s6);
	cout <<"s5 "<<s5 << endl;

	//�ȼ���
	string s7 = "cpp";
	s7.insert(s7.size(), s6);
	cout << "s7 " << s7 << endl;

	//03-2 replace

	string s8 = "123456789";
	s8.replace(2, 4, "hell");
	cout << "s8 " << s8 << endl;
	//������2��ʼ�������ĸ��ַ�ɾ��������hell������������ַ������Ȳ�һ���պõ���ɾ���ĳ���
	
	//�ȼ���
	s8.erase(2, 4);
	s8.insert(2, "3456");
	cout << "s8 " << s8 << endl;

	//04 �ַ���������
	//find�������ص���string���±� size_type���͵�
	//����ʧ�ܻ᷵�� string::npos

	//04-1 ������ȫƥ��
	string s9 = "annabele";
	auto pos = s9.find("anna");
	cout <<"pos "<<pos << endl;
	pos = s9.find("bele");
	cout << "pos " << pos << endl;


	//04-2 ����numbers���Ƿ��и�nameһ�����ַ�-->�ڸ����ַ�����������һƥ���ֵ
	string numbers("01234567890"), name("r2d2");
	auto pspsps = name.find_first_of(numbers);
	cout << pspsps << endl;

	//04-2 ������һ�������б��е�ֵ
	auto nt = name.find_first_not_of(numbers);
	cout << nt << endl;

	//05 �ַ�����ֵת������


	string db = "3.134";
	double db_d = stod(db);
	cout << db_d << endl;

	int a = 50;
	string s = to_string(a);

	return 0;
}