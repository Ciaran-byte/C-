#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<functional>
using namespace std;

template<typename inputIterator,typename outputIterator,typename valType,typename comp>
outputIterator filter(inputIterator first, inputIterator last, outputIterator at, valType val, comp pred)
{
	while ((first =find_if(first,last,bind2nd(pred,val )))!=last )
	{
		cout << "发现了一个！" <<*first<< endl;
		*at++ = *first++;
		
	}
	return at;
}

int main()
{
	


	vector<int> ivec = { 1,4,5,2,6,7,8 };
	



	list<int> ilist = { 1,4,6,7,8,9,12,3,4 };
	


	//int dst_ivec[10];
	vector<int> dst_ivec(10);

	
	filter(ivec.begin(), ivec.end(), dst_ivec.begin(), 5, less<int>());
	cout << endl;

	filter(ilist.begin(), ilist.end(), dst_ivec.begin(), 5, greater<int>());

	
	

	return 0;
}

