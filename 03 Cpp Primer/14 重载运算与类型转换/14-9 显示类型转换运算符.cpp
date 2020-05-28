#include<iostream>
using namespace std;
class mycls
{
public:
	 explicit mycls(int a) :_a(a) { cout << "构造函数！" << endl; }
	explicit operator int()const
	{
		return _a;
	}
	mycls& operator=(const mycls& cms)
	{
		cout << "拷贝复制函数！" << endl;
		_a = cms._a;
	}
	mycls(const mycls& cls)
	{
		cout << "拷贝构造！" << endl;
		_a = cls._a;
	}
	~mycls()
	{
		cout << "析构!" << endl;
	}
private:
	int _a;
};

int main()
{
	
	mycls b = static_cast<mycls>(5);
	mycls c = mycls(5);

	int a = static_cast<int>(b);

	//将构造函数和类型转换函数定义为explict后，将不能通过单个参数进行隐式的转换，必须要用类型转换函数进行显示转换
	
	
	return 0;
}

