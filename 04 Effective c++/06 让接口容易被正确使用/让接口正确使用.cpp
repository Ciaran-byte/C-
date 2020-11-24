#include<iostream>
using namespace std;

//01 ����һ��ͨ���������ͣ�������������ݣ���ֹ�û��������

struct  Month
{
	explicit Month(int m) :val(m) {}
	int val;
};

struct Day
{
	explicit Day(int d) :val(d) {}
	int val;
};

struct Year
{
	explicit Year(int y) :val(y) {}
	int val;
};

class Date
{
public:
	//Date(int month, int day, int year); //������Ʒǳ��Ĳ��ã���Ϊ�û���ʱ�����������

	Date(const Month& m, const Day& d, const Year& y):month(m.val),day(d.val),year(y.val){}
	//������ƾͱȽϺã���Ϊÿ���඼��explicit�Ĺ��캯�������������ʾ�Ķ��壬�����׳����⡣
	
private:
	int month;
	int day;
	int year;

private:
};


//02 ���ɶ���ͨ����������ֵ����һ��ǿ����������
class MONTH
{
public:
	static MONTH Jan() { return MONTH(1); }
	static MONTH Feb() { return MONTH(2); }
	int val;

private:
	explicit MONTH(int m) :val(m) {} //��ֹ���������ͱ��û�����
};

class DATE
{
public:
	
	//MONTH�����ṩ��static�Ľӿ�
	DATE(const MONTH& m, const Day& d, const Year& y) :month(m.val), day(d.val), year(y.val) {}
	

private:
	int month;
	int day;
	int year;

private:
};
int main()
{
	//01 ����һ
	// Date d(2,24,1980); //������ȷ�����룬��Ϊ���ܷ�����ʽת��
	Date d(Month(2),Day(24),Year(1980));

	//���ɶ�
	DATE dd(MONTH::Jan(), Day(24), Year(1980));
	return 0;
}