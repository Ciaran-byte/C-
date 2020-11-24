#include "const_test.h"

TextBlock::TextBlock(const string& s)
{
	text = s;
}

const char& TextBlock::operator[](size_t position)const
{
	cout << "const" << endl;
	return text[position];
}
char& TextBlock::operator[](size_t position)
{
	cout << "non-const" << endl;
	return text[position];
}

void pnt1(TextBlock& tb)
{
	cout << tb[0] << endl;
}
void pnt2(const TextBlock& tb)
{
	cout << tb[0] << endl;
}


TextBlock2::TextBlock2(const string& s)
{
	text = s;
}

const char& TextBlock2::operator[](size_t position)const
{
	cout << "const" << endl;
	return text[position];
}
char& TextBlock2::operator[](size_t position)
{
	cout << "non-const" << endl;

	//非常精妙的转型写法
	return const_cast<char&> (static_cast<const TextBlock2&>(*this)[position]);
}

void Bpnt1(TextBlock2& tb)
{
	cout << tb[0] << endl;
}
void Bpnt2(const TextBlock2& tb)
{
	cout << tb[0] << endl;
}
