#include<iostream>
#include<set>
#include<vector>
#include<memory>
using namespace std;
class Quote
{
public:
	Quote() {}
	Quote(const string& book, double price) :bookno(book), price(price) {}
	virtual double net_price(size_t n)const
	{
		//cout << "quote" << endl;
		return price * n;
	}
	virtual ~Quote() {}
	string isbn()const
	{
		return bookno;
	}
private:
	string bookno;

protected:
	double price;
};

class Bulk_quote :public Quote
{
public:
	Bulk_quote() {}
	Bulk_quote(const string& str, double price, size_t limit, double discount) :Quote(str, price), limit(limit), discount(discount) {}
	virtual double net_price(size_t n)const
	{
		//cout << "bulk_quote" << endl;
		if (n <= limit)
		{
			return price * n;
		}

		else
		{
			return limit * price + (n - limit) * price * (1 - discount);
		}
	}
	~Bulk_quote() {}

private:
	size_t limit;
	double discount;
};
double print_total(ostream& os, const Quote& item, size_t n)
{
	double sale = item.net_price(n);
	os << item.isbn() << "有" << n << "本，" << "总销售额为" << sale << endl;
	return sale;

}



class basket
{
public:
	void add_item(const shared_ptr<Quote> &sale)
	{
		items.insert(sale);
	}

	double total_receipt(ostream&)const;
private:	
	static bool compare(const shared_ptr<Quote>& rhs, const shared_ptr<Quote>& lhs)
	{
		return rhs->isbn() < lhs->isbn();
	}

	multiset<shared_ptr<Quote>, decltype(compare)*>
		items{ compare };//在类内对类类型做初始化，必须使用=或者花括号。
};

double basket::total_receipt(ostream& os)const
{
	double total = 0;
	
	for (auto it = items.cbegin(); it != items.cend(); it = items.upper_bound(*it))
	{
		total+=print_total(os, **it, items.count(*it));
	}
	os << "最终价格" << total << endl;
	return total;
}
int main()
{
	basket bsk;
	bsk.add_item(make_shared<Quote>("001", 50));
	bsk.add_item(make_shared < Bulk_quote>( "002", 50, 2, 0.4));
	bsk.add_item(make_shared<Quote>("001", 50));
	bsk.add_item(make_shared < Bulk_quote>("002", 50, 2, 0.4));
	bsk.add_item(make_shared<Quote>("001", 50));
	bsk.add_item(make_shared < Bulk_quote>("002", 50, 2, 0.4));

	bsk.total_receipt(cout);
	return 0;
}

