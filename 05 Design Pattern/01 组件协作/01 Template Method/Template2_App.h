#pragma once
#include "Template2_Lib.h"
//Ӧ�ÿ�����Ա
//ʹ���� Template method

class Application:public Library
{
protected:
	virtual bool step2() { return true; }
	virtual void step4(){}
	

};