#include<iostream>
#include<vector>
using namespace std;

class myClass
{
public:
	myClass(int num):_num(num){}
	friend ostream& operator<<(const myClass& cls, ostream& os);
	friend ostream& operator<<( ostream& os, const myClass& cls);
	friend istream& operator>>(istream& is,  myClass& cls);
	
	
private:
	int _num;
};

ostream& operator<<(const myClass& cls, ostream& os )
{
	os << cls._num;
	return os;
}
ostream& operator<<(ostream& os, const myClass& cls)
{
	os << cls._num;
	return os;
}

istream& operator>>(istream& is,  myClass& cls)
{
	
	is >> cls._num;
	
	return is;
}
int main()
{
	//01 ostream
	myClass cs1(5);
	myClass cs2(6);

	cout<<cs1;
	cout << endl;


	//02 istream
	cin >> cs1;
	cout << cs1;

	return 0;
}