#include<iostream>
using namespace std;

class printIn
{
public:
	template<typename valType>
	void print(const valType& val)
	{
		cout << val << endl;
	}
private:
};


template <typename elemType>
class P2
{
public:
	P2(const elemType& elem):_elem(elem){}
	template<typename valType>
	void print(const valType& val)
	{
		cout << val << endl;
		cout << _elem << endl;
	}
private:
	elemType _elem;
};
int main()
{
	//01 member template function
	printIn p;
	p.print<int>(1);

	p.print("abc");

	p.print('a');

	//02 模板类中的模板函数
	
	P2<int> p2(1);
	p2.print<string>("22222");
	
	return 0;
}




