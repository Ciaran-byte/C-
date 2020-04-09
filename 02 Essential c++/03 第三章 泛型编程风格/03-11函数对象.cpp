#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//01 ��������
template <typename inputIterator>
class myOutput
{
public:
	void operator()(inputIterator first, inputIterator last)
	{
		for (; first != last; first++)
		{
			cout << (*first) << endl;
		}
	}



};

//02 һԪν��
template<typename num>
class multiple
{

public:
	int val;
	//��Ϊ��Ҫָ��Ҫ��˭�ı���������������Ҫһ������ı���
	
	//���캯��
	multiple(int val):val(val){}

	//��������
	bool operator()(num a)
	{
		return (a % val == 0);
	}
};

//03 transform
template<typename T>
class multiply
{
public:
	T operator()(T a, T b)
	{
		return a * b;
	}
};
int main()
{
	//01 ʲô�Ǻ�������
	//��������ʵ�ʾ��������()�����أ���һ�����������˺������÷���
	//��Ϊ���������������еģ���˿��Ե����������ж��壬Ҳ������һ�������ĺ��������������ݵ��ǵ�ַ
	//��������ͺ����Ƿǳ����Ƶģ�������Ϊ�����������������ԣ�������������ݱ������ܹ�����һЩ��Ϣ
	//��������������һ���򵥵ĺ������󡣴�ӡvector�����

	//01-1��������myOutput��������������()����˶��������ʵ��a֮��ʹ�������()���Ϳ��Ե�����ʹ��
	//����Ǻ�������
	vector<int> ivec = { 1,2,3,8,5,6 };
	myOutput<vector<int>::iterator> a;
	a(ivec.begin(), ivec.end());
	cout << endl;

	//01-2 Ҳ����ͨ���������ַ������������ú�������
	myOutput<vector<int>::iterator>()(ivec.begin(), ivec.end());
	cout << endl;

	//02 ν��-����ֵΪbool�ĺ������󣬱���Ϊν�ʡ�
	//�����б�Ϊһ������ʱ������һԪν�ʣ������б�Ϊ��������ʱ��������Ԫν�ʣ�������ܶຯ����ʹ��ν����Ϊ��������
	//����һ������Ҫ���������һ���������ҵ���һ��4�ı���

	//02-1�������ʹ���˺��й��캯���ĺ�������
	cout<<*(find_if(ivec.begin(), ivec.end(), multiple<int>(4)))<<endl;

	//02-2���й��캯���ĺ��������ʹ��
	multiple<int> mul(4);//��Ҫ�����캯���������һ����
	mul(8);//���ù��캯��

	//02-3 ������
	multiple<int>(4)(8);//����8�Ƿ�Ϊ4�ı���

	//03 transform��ʹ��
	vector<int> t1 = { 1,2,3,4 };
	vector<int> t2 = { 2,3,4,5 };
	vector<int> t3(4);
	transform(t1.begin(), t1.end(), t2.begin(),t3.begin(), multiply<int>());
	for (int i = 0; i < t3.size(); i++)
	{
		cout << t3[i] << endl;
	}
	return 0;
}