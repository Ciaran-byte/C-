# include"Template1_Lib.h"
//应用开发人员


//应用开发人员
//使用设计模式技巧前

class Application
{

public:
	bool step2() { return true; }
	
	void step4(){}

	void Run()
	{
		//假设有如下的按顺序执行的程序
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