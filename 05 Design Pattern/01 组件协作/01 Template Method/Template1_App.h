# include"Template1_Lib.h"
//Ӧ�ÿ�����Ա


//Ӧ�ÿ�����Ա
//ʹ�����ģʽ����ǰ

class Application
{

public:
	bool step2() { return true; }
	
	void step4(){}

	void Run()
	{
		//���������µİ�˳��ִ�еĳ���
		Library a;
		

		a.step1();

		if (this->step2())
		{
			a.step3();
		}

		this->step4();
		a.step5();

	}
};