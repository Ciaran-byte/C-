#include<iostream>
using namespace std;
class mycls
{
public:
	friend int operator+(const mycls&,const mycls&);
	friend bool operator==(const mycls&, const mycls&);
	friend bool operator!=(const mycls&, const mycls&);
private:
	int a;
};

//���������
int operator+(const mycls& m, const mycls& n)
{
	return m + n;
}

//��������
bool operator==(const mycls& m, const mycls& n)
{
	return m.a == n.a;
}
bool operator!=(const mycls& m, const mycls& n)
{
	return !(m == n);
}

//��ϵ�����

int main()
{

	return 0;
}

