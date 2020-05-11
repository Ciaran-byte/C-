#include<iostream>
using namespace std;

//01 const_cast�����ص�һ�ֵ����÷�
const string& shorter(const string& str1, const string& str2)
{
	return str1.size() > str2.size() ? str2 : str1;
}

string& shorter(string& str1, string& str2)
{
	//�ѷǳ�������ת��Ϊ�������ã�����shorter
	auto& r = shorter(const_cast<const string&> (str1), const_cast<const string&>(str2));


	//�ѳ��������ٱ�طǳ������ã����з���
	return const_cast<string&>(r);

}

int main()
{
	//01 const_cast�뺯������
	//const_cast��c++�е�һ������ת���������ܹ�ȥ���ײ�const�����const���ԡ�
	//���������һ��ָ������ָ�룬����ָ��������ǳ������Ϳ�������const_castȥ���������ԣ�
	//��ָ���ܹ��޸Ķ���

	//���ǣ����ָ��������ǳ�������ô����const_castȥ����������֮�����������û���ָ���޸�ԭ������.,
	//�����Ϊ��δ�����,���ܻ������


	//const_cast����ֻ��ȥ���ײ�const���ԣ������ܶԱ������ͽ���ת��

	//01-1 ����ȷ��ʹ�ð�����ǿ��ͨ��const_castȥ��const���ԣ����������޸�const���󣬿��ܻ�������
	const string str = "123";
	const  string& s = str;
	string& q = const_cast<string&>(s);
	q[0] = '3';
	cout << str << endl;


	//01-2 const_cast��������Ϊ
	//const_cast�������ں������أ�������һ�麯����һ��������Ҫ����const�����ã�����const������
	//������һ���������ܷ�const�����ã����ط�const������

	//ע�⣬��Ȼ����const������Ϊ���ص����������ǵײ�const�ǿ��Ե�

	//������������һ���ַ������̱ȽϺ���





	return 0;
}


