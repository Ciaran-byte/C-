#include<iostream>
#include<regex>
using namespace std;
int main()
{
	
		//ÿ�����ű�ʾһ���ӱ��ʽ��str(0����ʾ��ʾȫ��ƥ����ʽ
		regex r("([[:alnum:]]+)\\.(cpp|cxx|cc)$", regex::icase);

		string str;
		smatch results;

		while (cin >> str)
		{
			if (regex_search(str, results, r))
			{
				cout << results.str(1) << endl;
			}
		}

	return 0;
}




