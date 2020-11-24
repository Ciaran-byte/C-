#include<iostream>
using namespace std;


template <typename T>
class smart_ptr1
{
public:
	explicit smart_ptr1(T* realPtr) :realPtr(realPtr) {}

	
private:
	T* realPtr;
};



template <typename T>
class smart_ptr
{
public:
	explicit smart_ptr(T* realPtr):realPtr(realPtr){}

	template<typename U>
	smart_ptr(const smart_ptr<U>& other) : realPtr(other.get()) { }

	 T* get() const { return realPtr; }
private:
	T* realPtr;
};



class A
{
public:
	virtual void ptr() { cout << "a" << endl; }
};

class B:public A
{
public:
	virtual void ptr() { cout << "b" << endl; }
};

int main()
{
	//01 ���ڷ�������˵�����ǳ�����ͨ���������͵ķ�������ָ�룬��֧���麯���ĵ���
	//��ʵ�ϣ�����ָ��shared_ptrҲ��֧��ʹ�������ָ��ָ�������п�������ģ�������ôʵ�ֵ���?
	shared_ptr<A> apA= make_shared<A>();
	shared_ptr<A> apB = make_shared<B>();
	apA->ptr();
	apB->ptr();
	
	//02 ������ʵ��һ����򵥵�����ָ����smart_ptr1
	A a;
	B b;
	A* pa = &a;
	B* pb = &b;
	smart_ptr1<A> sma(pa);
	smart_ptr1<B> smb(pb);

	//smart_ptr1<A> asmb(smb);
	//���Կ��������ֱ��ʹ��B���͵�����ָ���A���ͽ��п������죬�Ǳ���ġ�
	//��Ϊ��������ָ����˵����������֮���Ƕ����ģ������ڼ̳в��̳��������
	//�����������Ϊÿһ�����Ͷ�����һ�ֿ������캯�����ǲ���ʵ�ġ�
	//��Ϊģ����ζ������������Ϳ��Ա����󻯣����ǲ�����Ϊ���������ָ�����Ͷ����Լ��Ŀ�������

	//03 ��������ô������ָ��Ŀ�������
	//���ʱ���������뷺���Ĺ��캯���������
	//��smart_ptr��Ŀ������캯�������Ƿ��֣��������캯��Ҳ�Ǹ�������
	//���˷������Ժ󣬾Ϳ���ʵ��������������ָ��Ļ��࿽��


	//template<typename U>
	//smart_ptr(const smart_ptr<U> & other);

	//���£��ǲ��ǻ���Щ����?���ǲ�ϣ������һЩָ�������ת��������doubleָ����intָ�룬��ô��
	//�����Ŀ������캯����������޶���?

	//���ʱ�����ǹ�����һ��get������������ָ�룬ͨ����ʼ���б�ķ������п�������
	//�ڳ�ʼ���б��У�ֻҪ֧����ʽ����ת����ʱ��������صĿ������캯������ͨ������

	int ia = 5;
	double db = 6.0;
	int* pia = &ia;
	double* pdb = &db;
	smart_ptr<int> smpia(pia);
	smart_ptr<double> smpdb(pdb);

	//smart_ptr<int> sm(smpdb); //double��ָ��תint���ܱ�����ͨ��
	//smart_ptr<double> sm(smpdb); //int��ָ��תdoubleҲ���ܱ�����ͨ��

	A a1;
	B b1;
	smart_ptr<A> pa1(&a1);
	smart_ptr<B> pb1(&b1);
	smart_ptr<A> pa2(pb1); //���������ܹ�����
	//smart_ptr<B> pb2(pa1); //�������Ͳ��ܹ�����

	

	//04 ���˷����Ŀ����������⣬Ҳ������ͬ���ķ���ʵ�ָ�ֵ����
	//ͬʱ��д���캯����ʱ��Ӧ��֧�ֲ�ͬ��������ָ��֮���ת��
	//����shared_ptr,weak_ptr,unique_ptr��
	//ҲӦ��ͨ�������Ĺ��캯����������

	return 0;
}

