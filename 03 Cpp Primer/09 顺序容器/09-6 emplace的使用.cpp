#include<iostream>
#include<vector>
using namespace std;

class myClass
{
public:
	myClass(int a = 0,int b = 0):_a(a),_b(b){}
private:
	int _a;
	int _b;
};
int main()
{
	//ԭʼ��vector
	vector<myClass> vec;
	myClass cls1(0, 0);
	myClass cls2(1, 1);
	myClass cls3(2, 2);
	vec.push_back(cls1);
	vec.push_back(cls2);
	vec.push_back(cls3);

	//ʹ��emplace_back �����������빹�ɺ�����������ʱ�Ķ���
	myClass test(3, 3);
	vec.emplace_back(test);	
	vec.emplace_back(4, 4);  

	//vec.push_back(0, 0);
	vec.push_back(myClass(4, 4));

	//emplace ��emplace_back,emplace_front �ֱ��Ӧinsert��push_back,push_front ��������
	//emplace��Щ�����������ֵ��Ϊ����ֵ������myClass��Ĺ��캯���У�����һ���µ�myClass����
	//�������λ���ڴ��У�Ȼ��������ʱ��������vec��

	//��push_back��Щ�����Ͳ��߱�ͨ������ֵ�����빹�캯��������ʱ������������
	return 0;
}

