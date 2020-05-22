#include<iostream>
#include<memory>
#include<vector>
#include<map>
#include<set>
#include<fstream>
#include<sstream>
using namespace std;

class QueryResult;
class TextQuery
{
public:
	using line_no = std::vector<string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&)const;
	

private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wm;

};

TextQuery::TextQuery(std::ifstream& in_file) :file(new vector<string>())
{
	string sentence;
	string word;
	line_no no = 0;
	while (getline(in_file,sentence))
	{
		no++;
		file->push_back(sentence);
		istringstream is(sentence);
		while (is >> word)
		{
			auto& line = wm[word];
			if (!line)
			{
				line.reset(new set<line_no>());

			}
			line->insert(no);
		}
	}
}
class QueryResult
{
public:
	
	friend void print(const QueryResult& qr);
	QueryResult
	(
		const string& str,
		shared_ptr<vector<string>> file,
		shared_ptr<set<TextQuery::line_no>> p
	):sought(str),_file(file),_p(p){}
private:
	string sought;
	shared_ptr <vector<string>> _file;
	shared_ptr<set<TextQuery::line_no>> _p;

};
QueryResult TextQuery::query(const std::string& str)const
{
	static shared_ptr<set<line_no>> no_data(new set<line_no>);

	auto loc = wm.find(str);
	if (loc != wm.end())
	{
		return QueryResult(str, file, loc->second);
	}
	else
	{
		return QueryResult(str, file, no_data);
	}
}

void print(const QueryResult& qr) 
{
	cout << qr.sought << " occurs" << qr._p->size() << " " << endl;
	auto it = qr._p->begin();
	auto end = qr._p->end();
	while(it!=end)
	{
		cout << "(line " << *it << " " << (*(qr._file))[(*it)-1] <<")"<< endl;
		it++;
		
	}

}
int main()
{
	ifstream in_file("1.txt");
	TextQuery tq(in_file);
	string word;
	while (cin >> word)
	{
		print(tq.query(word));

	}
	

	return 0;
}

