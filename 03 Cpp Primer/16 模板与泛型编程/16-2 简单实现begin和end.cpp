#include<iostream>
using namespace std;

template<typename T,size_t N>
const T* my_begin(const T(&a)[N])
{
	return &a[0];
}

template<typename T,size_t N>
const T* my_end(const T(&a)[N])
{
	return &(a + N);
}

int main()
{
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	cout << *my_begin<int, 10>(a) << endl;
	return 0;
}


