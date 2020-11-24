#include<iostream>
using namespace std;


//01 假设有类Rational
class Rational
{
public:
	Rational(int numerator = 0, int denominator = 1):numerator(numerator),denominator(denominator){}
	int Numerator()const { return numerator; }
	int Denominator()const { return denominator; }

private:
	int numerator;
	int denominator;
};

const Rational operator*(const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

//02 假设有模板类
template<typename T>
class Rational2
{
public:
	Rational2(const T& numerator = 0, const T& denominator = 1):numerator(numerator), denominator(denominator) {}
	const T& Numerator()const { return numerator; }
	const T& Denominator()const { return denominator; }

private:
	T numerator;
	T denominator;
};

template<typename T>
const Rational2<T>  operator*(const Rational2<T> & lhs, const Rational2<T> & rhs)
{
	return Rational2<T>(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

//03 在类模板中声明友元
template<typename T>
class Rational3
{
public:
	Rational3(const T& numerator = 0, const T& denominator = 1) :numerator(numerator), denominator(denominator) {}
	const T& Numerator()const { return numerator; }
	const T& Denominator()const { return denominator; }

	//friend const Rational3<T> operator*(const Rational3<T>& lhs, const Rational3<T>& rhs);
	//friend const Rational3 operator*(const Rational3& lhs, const Rational3& rhs);
	//在类模板内部，省略T不写也是可以的，上下两种写法是等价的
	//但是这两个函数，并不能被正确的连接，因为无法通过类内部的友元的定义，找到类外部的实现，二者是独立的

	//解决方法就是，在类内给友元写一个实现，调用外部的运算符重载函数，这样就能够通过类内的友元找到函数定义
	//同时借用外部non-member函数实现更加通用的隐式类型转换
	

private:
	T numerator;
	T denominator;
};

template<typename T>
const Rational3<T> operator*(const Rational3<T>& lhs, const Rational3<T>& rhs)
{
	return Rational3<T>(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}


//04 解决友元的连接
template<typename T>
class Rational4
{
public:
	Rational4(const T& numerator = 0, const T& denominator = 1) :numerator(numerator), denominator(denominator) {}
	const T& Numerator()const { return numerator; }
	const T& Denominator()const { return denominator; }
	friend const Rational4 operator*(const Rational4& lhs, const Rational4& rhs)
	{
		return Rational4<T>(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
	}


	//解决方法就是，在类内给友元写一个实现，这样就能够通过类内的友元找到函数定义，同时兼具通用的隐式类型转换功能
	


private:
	T numerator;
	T denominator;
};

template<typename T>
const Rational4<T> operator*(const Rational4<T>& lhs, const Rational4<T>& rhs)
{
	return Rational4<T>(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}
int main()
{
	//01 non-member的运算符重载函数，支持隐式类型转换
	Rational a(3,5);
	Rational b(1, 2);
	cout << (a * b).Denominator() << endl;
	Rational onEight(1, 8);
	Rational oneHalf(1, 2);
	Rational result = oneHalf * onEight;

	result = oneHalf * 2; //数字2可以进行隐式类型转换
	result = 2 * oneHalf; //只有non-member的运算符重载，才能完成这种类型的隐式类型转换
	cout << result.Denominator() << endl;

	//02 那么，对于模板类，是否这种隐式类型转换也成立呢?
	Rational2<int> oneFourth(1, 4);
	Rational2<int> oneSixth(1, 6);
	Rational2<int> rst = oneFourth * oneSixth;
	
	//rst = oneFourth * 2; //不可以使用

	//上面的代码不可使用的原因是，ontFourth可以通过Rational2<int>类型推导T是int
	//但是2不能用过模板类的构造函数被解释为Rational2<int>，因为模板类默认不会发生构造函数的隐式类型转换
	//因此通过int类型，没有办法推导 Rational2<T>是否能输入一个2，因为编译器找不到要调用的函数，就不能编译


	//03 使用友元，解决编译识别问题
	Rational3<int> one(1, 1);
	Rational3<int> two(2, 1);
	Rational3<int> rst2 = one * two;
	//使用友元的原理是，当我们定义了Rational3<int>后，这个类就会被具象化，friend会展开运算符*的真实面貌
	//函数operatio*就不再是一个模板类，而是一个正常的函数，就能够通过隐式类型转换，找到该调用的这个函数了
	//但是不巧的是，使用友元的方法，能够成功编译，但是不能被正确的连接

	//不能被正确连接的原因是，类内部和外部的 operator*函数其实是完全独立的。找到了内部的friend，但是却找不到具体的实现方法

	//04 解决友元的连接问题
	Rational4<int> three(3, 1);
	Rational4<int> rst3 = three * 3;
	cout << rst3.Numerator();
		return 0;
}

