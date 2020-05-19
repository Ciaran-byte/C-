#include<iostream>
#include<map>
#include<utility>
using namespace std;
int main()
{
	map<string, int> mp;
	//01 �������
	mp.insert({ "nihao",1 });
	mp.insert(make_pair("hah", 2));
	auto p=mp.insert(pair<string, int>("ok", 3));

	//02 �鿴��������ķ���ֵ������ֵ��pair���ͣ�first������ǲ���Ԫ�ص�ָ�룬second�������bool���͵�Ԫ�أ���֪�����Ƿ�ɹ�
	cout << (p.first)->first << endl;
	cout << (p.first)->second << endl;
	cout << p.second << endl;

	//���Ԫ���Ѿ����ڣ���ôinsert��secondֵ�ͻ�Ϊfalse

	//03 ɾ������
	map<string, int> del = { {"Aa",1},{"Bb",2 },{"Cc",3} };
	del.erase(del.begin());  //ͨ��ɾ������
	del.erase(del.begin(), del.end()); //ͨ��ɾ������


	map<string, int> de2 = { {"Aa",1},{"Bb",2 },{"Cc",3} };
	cout << de2.erase("Aa") << endl;//����ֵΪɾ���˼����ùؼ���Ԫ�أ�map��Ϊ�������ظ������Է���ֵֻ��0����1

	multimap<string, int> de3 = { {"Aa",1}, {"Aa",2}, {"Aa",3} };
	cout << de3.erase("Aa") << endl;//multimap������ �ظ��Ĺؼ��ʣ�����ɾ������ֵΪ3
	
									
	//04 map�±����
	//ȱ�㣬���������û�в��ҵ�ֵ�����Զ������������ϣ����������ʹ��find������

	//ֻ�ܶ�map��unordered_map�����±������multi����Ϊ�ؼ��ʲ�Ψһ��û�����±����
	

	map<string, int> de4 = { {"Aa",1},{"Bb",2 },{"Cc",3} };

	//����д��
	cout << de4["Aa"] << endl;
	cout << de4.at("Aa") << endl;


	//05 ����Ԫ��
	//05-1 find��count
	//���ڷ�multi��������find��count��ʵЧ��һ��
	//��multi��������ͨ��conut�����ܹ�����������顮

	multimap<string, int> de5= { {"Aa",1}, {"Aa",2}, {"Aa",3} };
	map<string, int> de6 = { {"Aa",1},{"Bb",2 },{"Cc",3} };
	cout<<de5.count("Aa")<< endl;
	cout << de6.count("Aa") << endl;
	cout << de6.find("Aa")->second << endl; //find�������ص�������count��������int

	//���ֵȼ۵���������
	if(de6.find("Aa")!=de6.end()){}
	if(de6.count("Aa")){}
	
	//05-2 ����ķ���ֵ���ǵ�����
	//upper_bound(k) ���ص�һ���ؼ��ִ���k��Ԫ��a>b
	//equal_range(k) ���ص�һ���ؼ��ֵ���k��Ԫ��
	//lower_bound(k) ���ص�һ���ؼ��ֲ�С��k��Ԫ�� a>=b

	//05 - 3 ��multi�������в���Ԫ��

	return 0;
}






