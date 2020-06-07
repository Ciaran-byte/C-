#include<iostream>
#include<bitset>
using namespace std;
int main()
{
	//01 ≥ı ºªØ
	bitset<6> bit(0b110000);
	cout << bit << endl;
	cout << bit[1] << endl;
	cout << bit.to_ulong() << endl;

	string s = "111110000000000011111111000000";
	bitset<6> str("110000");
	cout << str << endl;
	cout << str[1] << endl;

	//02 bitset ≤Ÿ◊˜

	return 0;
}

