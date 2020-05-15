#include<iostream>
#include<vector>
using namespace std;

class myClass
{
public:
	myClass(int a = 0,int b = 0):_a(a),_b(b){}
private:
	int _a;
	int _b;
};
int main()
{
	//原始的vector
	vector<myClass> vec;
	myClass cls1(0, 0);
	myClass cls2(1, 1);
	myClass cls3(2, 2);
	vec.push_back(cls1);
	vec.push_back(cls2);
	vec.push_back(cls3);

	//使用emplace_back ，变量被送入构成函数，产生临时的对象
	myClass test(3, 3);
	vec.emplace_back(test);	
	vec.emplace_back(4, 4);  

	//vec.push_back(0, 0);
	vec.push_back(myClass(4, 4));

	//emplace 和emplace_back,emplace_front 分别对应insert，push_back,push_front 三个函数
	//emplace这些函数会把输入值作为构造值，送入myClass类的构造函数中，产生一个新的myClass对象
	//这个对象位于内存中，然后把这个临时对象送入vec中

	//而push_back这些函数就不具备通过构造值，送入构造函数产生临时变量的能力。
	return 0;
}

