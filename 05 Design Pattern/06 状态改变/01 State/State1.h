#pragma once

#include<iostream>
using namespace std;

//�������������������ͨѶ
//�����������Ĳ�ͬ״̬��Ӧ�ò�ȡ��ͬ�Ĵ�����
//Stateģʽ���ڽ�������״̬����ı䣬��ΪҲ�ᷢ���ı�
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

	//��δ�����ֵ������Strategy��Щ���ƣ����Ǻܶ��if��else
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