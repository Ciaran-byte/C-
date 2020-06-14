#include<iostream>
#include<cstdlib>
using namespace std;


void* operator new(size_t size)
{
	cout << 1 << endl;
	if (void* mem = malloc(size))
	{
		return mem;
	}
	else
	{
		throw bad_alloc();
	}
}

void operator delete(void* mem)noexcept
{
	cout << 2 << endl;
	free(mem);
}
int main()
{
	int *a = new int(5);
	delete a;
	return 0;
}


