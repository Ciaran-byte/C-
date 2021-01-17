#pragma once


//构建器模式
//以建造房子为例，建房子有屋顶、门、窗等，流程大致相同
//但是门、屋顶、窗这些东西又不完全相同。
//需要解决流程大致相同，但是各个步骤不完全相同的问题
class House
{
//有个问题需要注意一下，c++如果在构造函数中调用虚函数，是不会访问子类的虚函数的。
	//因为在构造的时候，子类还没有被构造
public:
	void Init()
	{
		this->BuildPart1();
		for (int i = 0; i < 4; i++)
		{
			this->BuildPart2();
		}

		bool flag = this->BuildPart3();

		if (flag)
		{
			this->BuildPart4();
		}

		this->BuildPart5();
	}
	virtual ~House(){}
protected:
	virtual void BuildPart1() = 0;
	virtual void BuildPart2() = 0;
	virtual bool BuildPart3() = 0;
	virtual void BuildPart4() = 0;
	virtual void BuildPart5() = 0;
};

class StoneHouse : public House
{
protected:
	virtual void BuildPart1()
	{

	}
	virtual void BuildPart2()
	{

	}
	virtual bool BuildPart3()
	{

	}
	virtual void BuildPart4()
	{

	}
	virtual void BuildPart5()
	{

	}

};

void process()
{
	House* pHouse = new StoneHouse();
	pHouse->Init();
}