#include<iostream>
#include<regex>
using namespace std;
int main()
{
	//01 ������ʽ�Ļ����÷�
	string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*"; //[[:alpha:]]����������ĸ *��ʾ�ظ���λ���1��
	regex r(pattern);  //����������ʽ��
	smatch results;  //��������������
	string test_str = "receipt freind theif receive";
	if (regex_search(test_str, results, r))  //��ָ���ַ���ʹ��������ʽ���в��ң������results��
	{
		cout << results.str() << endl;
	}

	//02 ָ��regex�����ѡ��
	cout << endl;
	try
	{

		cout << "02" << endl;

		regex r2("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase); //^��ʾƥ���ַ���������ǰ�棬$��ʾƥ���ַ������������
		//icaseѡ���ʾ���Դ�Сд
		smatch results2;
		string filename;
		while (cin >> filename)
			if (regex_search(filename, results2, r2))
			{
				cout << results2.str() << endl;
			}

	}
	catch (regex_error e)
	{
		cout << e.what() << "\ncode:" << e.code() << endl;
	}

	//03 ������ʽ�������
	cout << endl;
	cout << "03" << endl;
	string pattern3("[^c]ei");
	pattern3 = "[[:alpha:]]" + pattern3 + "[[:alpha:]]";
	regex r3(pattern3, regex::icase);
	string test_str2 = "receipt freind theif receive";

	for (sregex_iterator it(test_str2.begin(), test_str2.end(), r3), end_it; it != end_it; it++)
	{
		cout << it->str() << endl;
	}
	


	return 0;
}

