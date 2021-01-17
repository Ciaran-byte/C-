#pragma once

//库开发人员
//使用了 Template method
class Library
{
public:
	virtual ~Library(){}
	void Run()
	{
		step1();
		if (step2())
		{
			step3();
		}

		step4();
		step5();
	}


protected:
	void step1(){}
	void step3(){}
	void step5(){}

	virtual bool step2() = 0;
	virtual void step4() = 0;

};