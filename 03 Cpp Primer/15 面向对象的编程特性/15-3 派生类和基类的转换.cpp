#include<iostream>
using namespace std;
class Quote
{
public:
	Quote() = default;
	Quote(const string& book, double sales_price) :bookNo(book), price(sales_price) {}


	string isbn()const
	{
		return bookNo;
	}
	virtual double net_price(size_t n)const
	{
		return n * price;
	}
	virtual ~Quote() = default;
private:
	string bookNo;
protected:
	double price = 0.0;

};

class Bulk_quote :public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const string& book, double p, size_t qty, double disc)
		:Quote(book, p), min_qty(qty), discount(disc) {}
	virtual double net_price(size_t n)const override
	{

		if (n >= min_qty)
		{
			return n * (1 - discount) * price;
		}
		else
		{
			return n * price;
		}

	}
	virtual ~Bulk_quote() {}
private:
	size_t min_qty = 0;
	double discount = 0.0;
};

int main()
{
	Quote qt;
	//Bulk_quote bk* = qt; //������ѻ���ת��Ϊ�̳��࣬��Ϊ�̳����еĺܶණ������û��

	Bulk_quote bk2;
	Quote* qt2 = &bk2;  //���аѼ̳���ת��Ϊ���࣬��Ϊ������Ҫ�ļ̳��඼��

	Bulk_quote bk3;
	Quote qt3 = bk3;  //����ֱ�ӵ��ڼ̳���Ҳ���ԣ��̳������Ĳ��ֻᱻ�е�
	return 0;
}

