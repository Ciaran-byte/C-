#include<iostream>
using namespace std;
class myClass
{
public:
	int myNum()
	{
		
		return num;
	}

	int myNum2()const
	{
		
		return num;
	}
private:
	 int num = 1;
};

int main()
{
	//01 ��ĳ�Ա�������ʳ�Ա������ʵ��
	//ͨ��������Ҫͨ�����еĺ�������˽�г�Ա��������������

	myClass cls;
	cout << cls.myNum();

	//	������仰����ôʵ�ֵ���cls�е�num������أ�
	//������Ϊ��ÿһ�����ж���һ�����ص�ָ��this��ָ��ʵ������
	//return num ʵ���ϵȼ��� return this.num  ֻҪ�ⲿ��ʵ�������ܹ����Լ�ָ�봫����������������ܹ��ҵ�
	//ʵ�������еĳ�Ա����

	//	���ԣ�cls.myNum()��仰��ʵ���ϸ�����myNum(&cls); cls���ʵ��������Լ��ĵ�ַ�����˺���myNum
	//Ȼ��thisָ��õ��˸�ֵ


	//02 thisָ��ı���
	//	ͬʱ��Ӧ��ע��һ�£�thisָ�뱾���Ǹ�����ָ�룬���ܸ��ĵ�ַ��ָ��

	//03 const��Ա����
	//const���͵ĳ�Ա������ָ��ͨ������������������޸����еĳ�Ա����
	//const��Ա�����ı������ڣ���thisָ������ָ�����ĳ���ָ�룬��˾Ͳ����ں������޸ĳ�Ա������
	
	//�ȼ���
	// int myNum2(const myClass* const this)
	//{
	//           return this.num;
	//}

	return 0;
}

