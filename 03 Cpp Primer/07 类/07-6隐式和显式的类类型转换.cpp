#include<iostream>
#include<vector>
using namespace std;

//01 ����һ
class animal
{
public:
	animal(string name):_name(name){}

	
	string _name;
};


void print(animal al)
{
	cout << al._name<<endl;
}


class cat
{
public:
	cat(animal& ani) :_name(ani._name) {}

	string _name;
};
void print2(cat ct)
{
	cout << ct._name << endl;
}

//02 ����2
class pig
{
public:
	explicit pig(const string & str):_name(str){}
	string _name;

};

void pig_print(const pig& p)
{
	cout << p._name << endl;
}
int main()
{
	//01 ��ʽ����ת��
	//01-1 ֻ��һ�������Ĺ��캯�����׷�����ʽ������ת��
	//�������Ƕ�����һ��animal�࣬���캯��ֻ��Ҫһ��string�����Ϳɡ�
	//���Ƕ�����һ������print,���ڴ�ӡanimal������
	//��ô
	string s = "cat";
	print(s);
	//���Ƿ��������������������һ���ַ���������Ҳ�ܹ����У�����Ƿ�������ʽ��������ת��
	//��Ϊ�ַ���s����ͨ�����캯������һ��animal���ͣ������൱����s������һ����ʱ��animal����Ȼ�����뺯��




	//01-2 ������ʽ����ת��ֻ�ܷ���һ��
	//01-1˵����������ʽ������ת��ֻ�ܷ���һ�Σ��������������һ��cat�࣬cat����Ҫһ��animal������й���

	//(1)ʹ���ַ�������print2����
	string p = "cct";
	//print2(s);//����ʹ��

	//(2) ʹ��animal����print2����
	animal m(p);
	print2(m);//�ܹ�ʹ��
	//	�����һ���Ͳ����ã��ڶ����Ϳ����ã�Ϊʲô�أ�
	//��Ϊ�����һ������ʹ�ã��ض����ַ������뺯����ͨ��animal�Ĺ��캯��������animal�����ټ�����animal
	//����Ĺ��캯��������cat���󣬶���ʽ����ת��ֻ�ܷ���һ����������̷�������������ת��������ǲ����õ�


	//���ڶ����������ܹ�ʹ�ã���ʽ��Ϊanimal�ൽcat��ֻ��Ҫ����һ����ʽת��




	//01-3 ͨ���ؼ���explicit����������һӰ��

	//		��ʱ��������ʽ����ת�����������⣬���ԣ�����ֻҪ�ѹ��캯������Ϊexplicit�Ͳ���������������ת��������
	//�������Ƕ�����pig�࣬���캯�������explicit��
	string str1 = "12323";
	
	//pig_print(str1); //���ʱ����仰�ͱ�ɴ�����ˣ���Ϊ������������ת��


	//01-4 explicit�ؼ��ֶԿ�����Ӱ��


	pig pg(str1);
	//pig p2 = p; //����ʹ��
	pig p3(pg);
	//		���ǿ��Կ����������캯�����explicit�Ժ󣬵ȺŸ�ֵ�ķ�������������ʹ���ˣ�������Ϊ
	//���캯��������Զ�ת�����ܺ󣬵ȺŲ��ܵ��ù��캯���ˣ����ԣ�ֻ��ͨ����ʼ�����ֶν��д���������
	//������ͨ����ֵ���ֶδ��������ˡ�

	animal an1(str1);
	animal an2 = an1;

	//02 ��ʽ������ת��
	//��������ʽ����ת��֮����ʽ�Ļ��ǿ���ʹ�õ�
	//02-1 ��ʽ����
	//ǿ������ת��
	string pigstr = "pig";
	pig_print((pig)(pigstr));

	//02-2 ��ʽ����ת��
	pig_print(static_cast<pig>(pigstr));

	return 0;
}

