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
	//Bulk_quote bk* = qt; //不允许把基类转换为继承类，因为继承类中的很多东西基类没有

	Bulk_quote bk2;
	Quote* qt2 = &bk2;  //运行把继承类转换为基类，因为基类需要的继承类都有

	Bulk_quote bk3;
	Quote qt3 = bk3;  //基类直接等于继承类也可以，继承类多余的部分会被切掉
	return 0;
}

