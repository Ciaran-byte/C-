#include<iostream>
#include<typeinfo>
using namespace std;
class A
{
public:
	void print() { cout << "A" << endl; }
	virtual ~A() {  }
};

class B :public  A
{
public:
	void print() { cout << "B" << endl; }
	virtual ~B(){  }
};
class D :public A, public B
{
public:
	void print() { cout << "D" << endl; }
	virtual ~D() {  }
};
int main()
{
	
	
		
	A* pa = new D();
	B* pb = dynamic_cast<B*>(pa);
	if(pb)
	pb->print();
	
	
	return 0;
}


