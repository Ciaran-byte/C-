#include<iostream>
#define ON 1
using namespace std;


#if ON
	//ʹ����Template_Method
#include "Template2_App.h"
#elif

	//��ʹ��Template_Method
#include"Template1_App.h"

#endif

int main()
{
#if ON
	//ʹ����Template Method
	//ʹ����֮��Run������������library�У�һЩ�б䶯�Ĳ���д�����麯������application���̳�ʵ�֡�
	//����ʵ�ֵĲ����ڿ����Ѿ���ɣ�ֻ�Ǿ���ʵ��ϸ������������ʵ�֡�
	Library* lb = new Application();
	lb->Run();
	delete lb;
#elif
	//û��ʹ��Template Method
	//û��ʹ��Template Method��Runʵ����Application�У���Ӧ�ò���ÿ⺯�����ʵ��
	Application a;
	a.Run();
#endif
}