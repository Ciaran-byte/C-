#include<iostream>
using namespace std;
class Quote
{
public:
	Quote() = default;
	Quote(const string &book,double sales_price):bookNo(book),price(sales_price){}

	
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
		:Quote(book,p),min_qty(qty),discount(disc){}
	virtual double net_price(size_t n)const
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
	virtual ~Bulk_quote(){}
private:
	size_t min_qty = 0;
	double discount = 0.0;
};

class noMoreThan:public Quote
{
public:
	noMoreThan(const string& bookno,double price,size_t limit,double discount)
		:Quote(bookno,price),limit(limit),discount(discount){}
	virtual ~noMoreThan(){}
	virtual double net_price(size_t n)const
	{
		if (n <= limit)
		{
			return n * price * (1 - discount);
		}
		else
		{
			return limit * price * (1 - discount) + price * (n - limit);
		}
	}
private:
	size_t limit;
	double discount;

};

double print_total(ostream& os, const Quote& item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN" << item.isbn()
		<< "# sold:" << n << "total due: " << ret << endl;
	return ret;
}
int main()
{
	Bulk_quote bq("2011", 51, 10, 0.1);
	print_total(cout, bq, 40);

	noMoreThan mt("three bodies", 200, 20, 0.3);
	print_total(cout, move(mt), 100);

	
	
	
	
	

	return 0;
}

