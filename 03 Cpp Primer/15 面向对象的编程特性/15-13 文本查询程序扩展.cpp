#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<memory>
#include<string>
#include<algorithm>
#include<fstream>
#include<iterator>
#include<functional>
using namespace std;

class QueryResult;
class TextQuery
{
public:
	TextQuery(istream& is):file(new vector<string>())
	{
		string sentence;
		while (getline(is, sentence))
		{
			file->push_back(sentence);
			size_t line_no = file->size() - 1;
			istringstream ss(sentence);
			string word;
			while (ss >> word)
			{
				auto& it = WordMap[word];
				if (!it)
				{
					it.reset(new set<size_t>());
				}
				it->insert(line_no);
			}
			
		}
	}
	QueryResult query(const string&)const;
	
	

private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<size_t>>> WordMap;
};

class QueryResult
{
	friend void print(const QueryResult& qr);
	


public:
	QueryResult(const string& str, shared_ptr<vector<string>> file, shared_ptr<set<size_t>> WordLine)
		:str(str), file(file), WordLine(WordLine)
	{

	}
	set<size_t>::iterator begin()const { return (*WordLine).begin(); }
	set<size_t>::iterator end() const{ return (*WordLine).end(); }
	shared_ptr<vector<string>> get_file() const {return file; }
public:
	const string str;
	shared_ptr<vector<string>> file;
	shared_ptr<set<size_t>> WordLine;
};
QueryResult TextQuery::query (const string& str)const
{
	static shared_ptr<set<size_t>> nodata(new set<size_t>());
	auto it = WordMap.find(str);
	if (it == WordMap.end())
	{
		return QueryResult(str, file, nodata);
	}
	else
	{
		return QueryResult(str, file, it->second);
	}

}

void print(const QueryResult& qr)
{
	cout << qr.str << "出现了" << qr.WordLine->size()<<"次:" << endl;
	for (auto it = qr.begin(); it != qr.end(); it++)
	{
		cout << "(line" << *it + 1 << ")" << *(qr.file->begin() + *it) << endl;
		cout << endl;
	}
	/*for (auto it : *(qr.WordLine))
	{
		cout << "(line" << it + 1 << ")" << *(qr.file->begin()+it) << endl;
		cout << endl;
	}*/
}

class Query;
class Query_base //用于定义不同类型的计算类的基类
{
	friend class Query;
protected:
	virtual ~Query_base(){}
private:
	virtual string rep()const=0;
	virtual QueryResult evl(const TextQuery&)const = 0;
	


	
};

class Query
{
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);

public:
	Query(const string&);
	string rep()const { return qb->rep(); }
	QueryResult evl(const TextQuery& tq)const { return qb->evl(tq); }



private:
	Query(shared_ptr<Query_base> query):qb(query){}

	shared_ptr<Query_base> qb;
};

ostream& operator<<(ostream& os, const Query& query)
{
	os << query.rep();
	return os;
}

class WordQuery :public Query_base
{
	friend class Query;
private:
	
	WordQuery(const string& str) :query_word(str){}
	
	virtual string rep()const override { return query_word; }
	virtual QueryResult evl(const TextQuery& tq)const override{ return tq.query(query_word); }
private:
	string query_word;
};
Query::Query(const string& str):qb(new WordQuery(str)){}

class NotQuery :public Query_base
{
	friend class Query;
	friend Query operator~(const Query&);
	
private:
	
	NotQuery(const Query& q) :query(q){}
	virtual string rep()const override{ return "~(" + query.rep() + ")"; }
	virtual QueryResult evl(const TextQuery& tq) const override;

private:
	Query query;
};
Query operator~(const Query& q)
{
	
	return Query(shared_ptr<Query_base>(new NotQuery(q)));
}
class BinaryQuery:public Query_base
{
	friend class Query;
protected:
	BinaryQuery(const Query &lhs,const Query& rhs,const string& opSym):lhs(lhs),rhs(rhs),opSym(opSym){}
	virtual string rep()const override
	{
		return "("+lhs.rep() + opSym + rhs.rep()+")";
	}
protected:
	Query lhs, rhs;
	string opSym;
};
class AndQuery :public BinaryQuery
{
	friend class Query;
	friend Query operator&(const Query&, const Query&);
private:

	AndQuery(const Query& lhs, const Query& rhs):BinaryQuery(lhs,rhs,"&"){}
	
	virtual QueryResult evl(const TextQuery&)const override;

	
};
Query operator&(const Query& lhs, const Query& rhs)
{
	return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}
class OrQuery:public BinaryQuery
{
	friend class Query;
	friend Query operator|(const Query&, const Query&);
private:
	OrQuery(const Query& lhs,const Query& rhs):BinaryQuery(lhs,rhs,"|"){}
	virtual QueryResult evl(const TextQuery&)const override;
};

Query operator|(const Query& lhs, const Query& rhs)
{
	return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

QueryResult OrQuery::evl(const TextQuery& tq)const 
{
	auto left = lhs.evl(tq);
	auto right = rhs.evl(tq);
	shared_ptr<set<size_t>> ret_lines = make_shared<set<size_t>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());
	return QueryResult(rep(), left.get_file(), ret_lines);

	
}

QueryResult AndQuery::evl(const TextQuery& tq)const
{
	auto left = lhs.evl(tq);
	auto right = rhs.evl(tq);
	shared_ptr<set<size_t>> ret_lines = make_shared<set<size_t>> ();
	set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), left.get_file(), ret_lines);
}

QueryResult NotQuery::evl(const TextQuery& tq)const
{
	auto result = query.evl(tq);
	auto ret_lines = make_shared<set<size_t>>();
	auto beg = result.begin();
	auto end = result.end();
	size_t sz = result.get_file()->size();
	for (size_t n=0; n <sz ;n++)
	{
		if (beg == end || *beg != n)
		{
			ret_lines->insert(n);
		}
		else if (beg != end)
			++beg;

	}
	return QueryResult(rep(), result.get_file(), ret_lines);
}

int main()
{
	ifstream in_file("text.txt");
	if (!in_file)
	{
		return -1;
	}
	TextQuery tq(in_file);
	
	string s = "is";
	Query m(s);
	Query p("no");
	Query n = m&p;

	QueryResult qr = n.evl(tq);
	print(qr);
	return 0;
}

