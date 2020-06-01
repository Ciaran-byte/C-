#include<iostream>
#include<vector>
using namespace std;
class Quote
{
public:
	Quote() {}
	Quote(const string& book, double price) :bookno(book), price(price){}
	virtual double net_price(size_t n)const
	{
		cout << "quote" << endl;
		return price * n;
	}
	virtual ~Quote(){}
private:
	string bookno;
	
protected:
	double price;
};

class Bulk_quote:public Quote
{
public:
	Bulk_quote(){}
	Bulk_quote(const string& str,double price,size_t limit,double discount):Quote(str,price),limit(limit),discount(discount){}
	virtual double net_price(size_t n)const
	{
		cout << "bulk_quote" << endl;
		if (n <= limit)
		{
			return price * n;
		}
		
		else
		{
			return limit * price + (n - limit) * price * (1 - discount);
		}
	}
	~Bulk_quote(){}

private:
	size_t limit;
	double discount;
};
int main()
{
	//容器中不能储存不同类型的对象，如果想同时储存基类和派生类，容器应该定义为指针类型
	//最好的智能指针
	vector<shared_ptr<Quote>> basket;
	basket.push_back(make_shared<Quote>("three bodies", 35));
	basket.push_back(make_shared<Bulk_quote>("fairy", 35,20,0.4));
	cout << basket.back()->net_price(40) << endl;
	cout << basket.front()->net_price(40) << endl;
	return 0;
}
