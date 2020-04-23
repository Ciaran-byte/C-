#include<iostream>
#include<exception>
#include<sstream>
using namespace std;

//��һ �׳�int ���ע��һ
void f1(int num, int max = 50)
{
	if (num > max)
		throw 42;
	cout << "�����ɹ�" << endl;
}
//���� �׳�string ���ע��һ
void f2(int num, int max = 50)
{
	if (num > max)
		throw "����Խ��";
	cout << "�����ɹ�" << endl;
}

//���� �׳�class������д�� ���ע��һ
class error
{
public:
	error(int num,int max):_num(num),_max(max){}
	void what()
	{
		cout << _num << "���������ֵ" << _max << endl;
	}
private:
	int _num;
	int _max;
};
void f3(int num, int max = 50)
{
	if (num > max)
	{
		throw error(num, max);
	}
	cout << "�����ɹ�" << endl;
}

void f4(int num, int max = 50)
{
	if (num > max)
	{
		error err(num, max);
		throw err;
	}
	cout << "�����ɹ�" << endl;
}

//���� ���ע���
class error1:public error
{
	error1(int num,int max):error(num,max){}
};
void f5(int num, int max = 50)
{
	if (num > max)
	{
		error err1(num, max);
		throw err1;
	}
	cout << "�����ɹ�" << endl;

	
}

//���� ���ע���壬�쳣���ϼ����׳�
void level1()
{
	throw 1;
}
void level2()
{
	level1();

}

//���� ���ע��������μ̳б�׼�쳣���������Լ����쳣
class exceptionError:public exception
{
public:
	exceptionError(int num,int max):_num(num),_max(max){}
	const char* what()
	{
		ostringstream ex_msg;
		static string msg;

		//����һ �ѻ���������͵Ĵ�����ַ���
		ex_msg << _num << "�������ֵ" << _max << "!" << endl;
		msg = ex_msg.str();

		//���ɶ� ���ַ������ const char *
		return msg.c_str();
	}
private:
	int _num;
	int _max;
};

void throwExceptionError(int num,int max=50)

{
	if (num > max)
	{
		throw exceptionError(num, max);
	}
	cout << "�����ɹ�" << endl;
	
}
int main()
{
	// ���ע��һ 
	//01 ����1
	cout << "�׳�int" << endl;
	try
	{
		f1(100, 50);
	}
	catch (int len)
	{
		cout << len << endl;
		
	}
	cout << endl;
	//02 ����2
	cout << "�׳�string" << endl;
	try
	{
		f2(100, 50);
	}
	catch (const char* str)
	{
		cout << str << endl;

	}
	cout << endl;

	//03 ����3-1
	cout << "�׳�class1" << endl;
	try
	{
		f3(100, 50);
	}
	catch ( error& err)
	{
		err.what();

	}
	cout << endl;

	//03 ����3-2
	cout << "�׳�class2" << endl;
	try
	{
		f4(100, 50);
	}
	catch (error & err)
	{
		err.what();

	}
	cout << endl;


	//���ע���
	//01 �Ӹ���Ѱ���쳣����
	cout << "�Ӹ���Ѱ���쳣����" << endl;
	try
	{
		f5(100, 50);
	}
	catch (error & err)
	{
		err.what();

	}
	cout << endl;

	//���ע����
	cout << "catch(...)ȫ��ץס" << endl;
	try
	{
		f4(100, 50);
	}
	catch (...)
	{
		cout << "error!" << endl;

	}
	cout << endl;

	//���ע����
	//01 catch���໥����-�쳣��������
	try
	{
		f4(100, 50);
	}
	
	//���д��ǰ���Ǵ����
	/*catch (...)
	{
		cout << "error!" << endl;

	}*/
	catch (error & err)
	{
		err.what();

	}
	cout << endl;

	//���ע����
	cout << "���ŵ������ϴ��쳣" << endl;
	try
	{
		level2();
	}
	catch (int len)
	{
		cout << len << endl;
	}
	cout << endl;
	
	//���ע���� ͨ���̳б�׼�쳣�⣬�������Լ����쳣

	cout << "�̳б�׼�쳣��" << endl;
	try
	{
		throwExceptionError(100, 50);
	}
	
	catch (exception & exp)
	{
		exp.what();
	}

	cout << endl;

	return 0;
}


//ע��һ���쳣�׳�ͨ��throw�ؼ��ʽ��У�throw�����׳��κ�������Ϊ�쳣����������int��string�ȼ�����
//Ҳ���԰���class�����ĸ������ͣ�����ʹ�÷�����������ĸ�����

//ע������쳣�׳�Ҳ�����������Ҳ��������ʱ��catch��ȥ�������쳣���͵ĸ�����û�У�����У����ǻ����ִ��catch�е�����

//ע����������һ��д��������catch(...)�����������е��쳣����

//ע���ģ�Ҫע��ľ��ǣ�catch֮�䲻�����໥�����Ĺ�ϵ�������������г�����֪����ִ���Ǹ������⣬Ҳ�����ڹ��캯��
//���׳��쳣��������ʹ��new��ʱ����Ϊ�����캯������׳��쳣����ζ�Ŷ���û�ж��壬�����ڴ��Լ��������ˣ�����
//û���壬��ζ�Ų���ִ���������������Ի�����ڴ�й¶

//ע���壺��֤���������ϴ���

//ע������ͨ���̳�exception���������Լ����쳣��ע�����㣬һ���Ǳ�����ͷ�ļ�exception������һ���ǣ�����
//�����麯��what������ֵΪconst char*��ͬʱ��������������ɣ�һ����ΰѻ����������͵Ĵ�����ַ���������
//һ���ǣ���ΰ�string���const char*