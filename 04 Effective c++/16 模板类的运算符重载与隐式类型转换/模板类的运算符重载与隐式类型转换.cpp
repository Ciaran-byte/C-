#include<iostream>
using namespace std;


//01 ��������Rational
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

//02 ������ģ����
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

//03 ����ģ����������Ԫ
template<typename T>
class Rational3
{
public:
	Rational3(const T& numerator = 0, const T& denominator = 1) :numerator(numerator), denominator(denominator) {}
	const T& Numerator()const { return numerator; }
	const T& Denominator()const { return denominator; }

	//friend const Rational3<T> operator*(const Rational3<T>& lhs, const Rational3<T>& rhs);
	//friend const Rational3 operator*(const Rational3& lhs, const Rational3& rhs);
	//����ģ���ڲ���ʡ��T��дҲ�ǿ��Եģ���������д���ǵȼ۵�
	//���������������������ܱ���ȷ�����ӣ���Ϊ�޷�ͨ�����ڲ�����Ԫ�Ķ��壬�ҵ����ⲿ��ʵ�֣������Ƕ�����

	//����������ǣ������ڸ���Ԫдһ��ʵ�֣������ⲿ����������غ������������ܹ�ͨ�����ڵ���Ԫ�ҵ���������
	//ͬʱ�����ⲿnon-member����ʵ�ָ���ͨ�õ���ʽ����ת��
	

private:
	T numerator;
	T denominator;
};

template<typename T>
const Rational3<T> operator*(const Rational3<T>& lhs, const Rational3<T>& rhs)
{
	return Rational3<T>(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}


//04 �����Ԫ������
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


	//����������ǣ������ڸ���Ԫдһ��ʵ�֣��������ܹ�ͨ�����ڵ���Ԫ�ҵ��������壬ͬʱ���ͨ�õ���ʽ����ת������
	


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
	//01 non-member����������غ�����֧����ʽ����ת��
	Rational a(3,5);
	Rational b(1, 2);
	cout << (a * b).Denominator() << endl;
	Rational onEight(1, 8);
	Rational oneHalf(1, 2);
	Rational result = oneHalf * onEight;

	result = oneHalf * 2; //����2���Խ�����ʽ����ת��
	result = 2 * oneHalf; //ֻ��non-member����������أ���������������͵���ʽ����ת��
	cout << result.Denominator() << endl;

	//02 ��ô������ģ���࣬�Ƿ�������ʽ����ת��Ҳ������?
	Rational2<int> oneFourth(1, 4);
	Rational2<int> oneSixth(1, 6);
	Rational2<int> rst = oneFourth * oneSixth;
	
	//rst = oneFourth * 2; //������ʹ��

	//����Ĵ��벻��ʹ�õ�ԭ���ǣ�ontFourth����ͨ��Rational2<int>�����Ƶ�T��int
	//����2�����ù�ģ����Ĺ��캯��������ΪRational2<int>����Ϊģ����Ĭ�ϲ��ᷢ�����캯������ʽ����ת��
	//���ͨ��int���ͣ�û�а취�Ƶ� Rational2<T>�Ƿ�������һ��2����Ϊ�������Ҳ���Ҫ���õĺ������Ͳ��ܱ���


	//03 ʹ����Ԫ���������ʶ������
	Rational3<int> one(1, 1);
	Rational3<int> two(2, 1);
	Rational3<int> rst2 = one * two;
	//ʹ����Ԫ��ԭ���ǣ������Ƕ�����Rational3<int>�������ͻᱻ���󻯣�friend��չ�������*����ʵ��ò
	//����operatio*�Ͳ�����һ��ģ���࣬����һ�������ĺ��������ܹ�ͨ����ʽ����ת�����ҵ��õ��õ����������
	//���ǲ��ɵ��ǣ�ʹ����Ԫ�ķ������ܹ��ɹ����룬���ǲ��ܱ���ȷ������

	//���ܱ���ȷ���ӵ�ԭ���ǣ����ڲ����ⲿ�� operator*������ʵ����ȫ�����ġ��ҵ����ڲ���friend������ȴ�Ҳ��������ʵ�ַ���

	//04 �����Ԫ����������
	Rational4<int> three(3, 1);
	Rational4<int> rst3 = three * 3;
	cout << rst3.Numerator();
		return 0;
}

