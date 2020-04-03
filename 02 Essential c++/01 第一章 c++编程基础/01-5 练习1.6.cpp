#include<iostream>
#include<fstream>
#include<vector>
#include<iterator>
using namespace std;
int main()
{
	// vector版本
	int num;
	vector<int> numbers;

	while ((cin >> num))
	{
		numbers.push_back(num);
	}
	
	double sum = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		sum+=numbers[i];

	}
	cout << sum << endl;
	cout << sum / numbers.size()<< endl;
	 

	//数组版本
	const int array_size = 128;
	int arr[array_size];
	double SUM;
	int index = 0;
	int value;
	while (cin >> value && index < array_size)
	{
		arr[index++] = value;
	}
	SUM = 0;
	for (int i = 0; i < index; i++)
	{
		SUM += arr[i];
	}

	cout << SUM << endl;
	cout << SUM / index << endl;
	

	return 0;
}

