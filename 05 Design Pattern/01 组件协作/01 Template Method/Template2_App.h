#pragma once
#include "Template2_Lib.h"
//应用开发人员
//使用了 Template method

class Application:public Library
{
protected:
	virtual bool step2() { return true; }
	virtual void step4(){}
	

};