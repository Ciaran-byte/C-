#include<iostream>
#include<set>
#include<vector>
#include<memory>
using namespace std;
//basket�����ڱ���ÿ����ļ�¼�������������ܶ��
//Quote�����κ��Ż����ߵ�ͼ�����
//Bulk_quote �����Ż����ߵ�ͼ���࣬�̳�Quote
class Quote
{
public:
	
	Quote(const string& book, double price) :bookno(book), price(price) {}
	virtual double net_price(size_t n)const
	{
		//cout << "quote" << endl;
		return price * n;
	}
	virtual ~Quote() {}
	virtual Quote* clone() const&  //���ڷ�����Ŀ�����
	{
		return new Quote(*this);
	}
	virtual Quote* clone() &&  //����ת�����ַ�Ŀ���Ȩ
	{
		return new Quote(move(*this));
	}
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
	virtual Bulk_quote* clone() const&
	{
		return new Bulk_quote(*this);
	}
	virtual  Bulk_quote* clone()&&
	{
		return new  Bulk_quote(move(*this));
	}
private:
	size_t limit;
	double discount;
};
double print_total(ostream& os, const Quote& item, size_t n)
{
	double sale = item.net_price(n);
	os << item.isbn() << "��" << n << "����" << "�����۶�Ϊ" << sale << endl;
	return sale;

}



class basket
{
public:
	 void  add_item(const shared_ptr<Quote>& sale) //��15-11��ȣ��������������غ�����������basket�������Ԫ��
	{
		items.insert(sale);
	}
	void add_item(const Quote& sale)//ϣ���ܹ����౾�������󣬵��ǲ���ֱ�Ӵ�������󣬷�����̳����ʱ�����ݻᷢ���ض�
	{
		items.insert(shared_ptr<Quote>(sale.clone()));
	}
	void add_item(Quote&& sale)
	{
		items.insert(shared_ptr<Quote>(move(sale).clone()));
	}
	double total_receipt(ostream&)const;
private:
	static bool compare(const shared_ptr<Quote>& rhs, const shared_ptr<Quote>& lhs)
	{
		return rhs->isbn() < lhs->isbn();
	}

	multiset<shared_ptr<Quote>, decltype(compare)*>
		items{ compare };//�����ڶ�����������ʼ��������ʹ��=���߻����š�
};

double basket::total_receipt(ostream& os)const
{
	double total = 0;

	for (auto it = items.cbegin(); it != items.cend(); it = items.upper_bound(*it))
	{
		total += print_total(os, **it, items.count(*it));
	}
	os << "���ռ۸�" << total << endl;
	return total;
}


int main()
{
	basket bsk;
	Quote q1("001", 50);
	Bulk_quote q2("002", 50,2,0.4);
	bsk.add_item(make_shared<Quote>("001", 50));
	bsk.add_item(make_shared < Bulk_quote>("002", 50, 2, 0.4));
	bsk.add_item(make_shared<Quote>("001", 50));
	bsk.add_item(make_shared < Bulk_quote>("002", 50, 2, 0.4));
	bsk.add_item(make_shared<Quote>("001", 50));
	bsk.add_item(make_shared < Bulk_quote>("002", 50, 2, 0.4));
	bsk.add_item(q1);
	bsk.add_item(move(q2));
	
	bsk.total_receipt(cout);
	return 0;
}

