#pragma once

#include<iostream>
using namespace std;

//这个案例描述的是网络通讯
//对于网络流的不同状态，应该采取不同的处理方法
//State模式用于解决对象的状态如果改变，行为也会发生改变
enum NetworkState
{
	Network_Open,
	Network_Close,
	Network_Connect,
};

class NetworkProcessor
{
	NetworkState state;
public:

	//这段代码出现的情况与Strategy有些相似，都是很多的if和else
	void Operator1()
	{
		if (state == Network_Open)
		{
			state = Network_Close;
		}
		else if (state == Network_Close)
		{
			state = Network_Connect;
		}
		else if (state == Network_Connect)
		{
			state = Network_Open;
		}
	}
};