#include<iostream>
using namespace std;

//01 ����ָ����ô��
//01-1 ��������һЩר�Ŵ�ӡ�������ֵĺ���
void fibonPrint()
{
	cout << "this is fibon" << endl;
}

void lucusPrint()
{
	cout << "this is lucus" << endl;
}
void pellPrint()
{
	cout << "this is pell" << endl;
}
void trianglePrint()
{
	cout << "this is triangle" << endl;
}
void squarePrint()
{
	cout << "this is square" << endl;
}
void pentPrint()
{
	cout << "this is pent" << endl;
}


//01-2 ��������һ��ר�Ŵ������еĺ���(���践�����еڼ������֣�,���������Ժ��ӡ��������

//���ֱ��д��Ҫд�������������fibno�����Ĵ�ӡfibno����,��Ҫд�������
void func_fibno()
{
	//���ʲô����

	fibonPrint();
}
void func_pell()
{
	pellPrint();
}

//ʹ�ú���ָ��,������һ����������ȫ���ĺ���
void func2(void (*ptr)(void))
{
	ptr();
}

//02 ����ָ��ʹ�õĽ�һ���Ż�

//�����������溯��ָ�룬�����Ϳ�����������������
void (*ptr_array[])(void) =
{
	fibonPrint,lucusPrint,pellPrint,trianglePrint,squarePrint,pentPrint
};

//��ö�ٸ�ÿ�����и�������

enum ns_type
{
	ns_bibno,
	ns_lucus,
	ns_pell,
	ns_triangle,
	ns_square,
	ns_pent
};


int main()
{
	//������⣺��ͬ�������б�ͬ������ֵ�ĺ�������������������Ҫ������Щ�������Ϳ��ú���ָ��ķ�����
	//���ٺ����Ķ�����������Ϊ�൱����ҪΪÿ�����õĺ���дһ��ר�ŵĺ�����

	//01 ����ָ���ʹ��
	//ֱ��д���������Ĵ���+��ӡ����
	func_fibno();
	func_pell();

	//�ú���ָ��Ϳ���һ������������,������Ч��һ�������Ǹ���
	func2(fibonPrint);
	func2(pellPrint);
	
	//02 �����еķ����Ż�����ָ�룬��ȻҪ��ס�ܶຯ��������

	//�����жԺ���ָ����й������ӵķ���
	func2(ptr_array[0]);
	func2(ptr_array[ns_pell]);
	return 0;
}

