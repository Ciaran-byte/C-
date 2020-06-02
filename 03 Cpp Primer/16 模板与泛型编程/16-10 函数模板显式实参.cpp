#include<iostream>
using namespace std;
template<typename T1,typename T2,typename T3>
T1 sum(T2 t2, T3 t3)
{
	T1 t1 = t2 + t3;
	return t1;
}
int main()
{

	sum<int>(1, 2);
	
	return 0;
}