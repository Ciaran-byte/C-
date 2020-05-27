#include<iostream>
#include<memory>
using namespace std;

class HasPtr
{
public:
	HasPtr(const string& s = string()):ps(new string(s)),i(0)
	{

	}
	HasPtr(HasPtr&rhs)
	{
		cout << 1 << endl;
		i = rhs.i;
		if (ps != rhs.ps)
		{
			delete ps;
			ps = new string(*rhs.ps);
		}
	}
	HasPtr& operator=(HasPtr& rhs)
	{
		cout << 2 << endl;
		i = rhs.i;
		if (ps != rhs.ps)
		{
			delete ps;
			ps = new string(*rhs.ps);
		}
		return *this;
	}
private:
	string* ps;
	int i;
};
int main()
{
	

	return 0;
}

