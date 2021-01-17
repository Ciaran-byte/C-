#pragma once


//构建器模式
//以建造房子为例，建房子有屋顶、门、窗等，流程大致相同
//但是门、屋顶、窗这些东西又不完全相同。
//需要解决流程大致相同，但是各个步骤不完全相同的问题
//因为类比较复杂，就拆分为内容和建造两个部分

//----------房子的内容--------------
class House
{
	
public:

protected:
	//里面有window、door等等具体的东西
	
};

class StoneHouse : public House
{
protected:


};

//-------------------房子的构建------------------
class HouseBuilder
{
	friend class HouseDirector;
public:
	
	House* GetResult()
	{
		return pHouse;
	}
	virtual ~HouseBuilder() {}
protected:
	House* pHouse;
	virtual void BuildPart1() = 0;
	virtual void BuildPart2() = 0;
	virtual bool BuildPart3() = 0;
	virtual void BuildPart4() = 0;
	virtual void BuildPart5() = 0;
};

class StoneHouseBuilder :public HouseBuilder
{
protected:
	virtual void BuildPart1() {}
	virtual void BuildPart2() {}
	virtual bool BuildPart3() {}
	virtual void BuildPart4() {}
	virtual void BuildPart5() {}
};

//HouseDirector是稳定的状态，需要重写的时候就重写HouseBuilder
class HouseDirector
{
public:
	HouseDirector(HouseBuilder* pHouseBuilder):pHouseBuilder(pHouseBuilder){}
	HouseBuilder* pHouseBuilder;

	House* Construct()
	{
		pHouseBuilder->BuildPart1();
		for (int i = 0; i < 4; i++)
		{
			pHouseBuilder->BuildPart2();
		}

		bool flag = pHouseBuilder->BuildPart3();

		if (flag)
		{
			pHouseBuilder->BuildPart4();
		}

		pHouseBuilder->BuildPart5();

		return pHouseBuilder->GetResult();
	}
};
void process()
{
	HouseBuilder *h = new StoneHouseBuilder();
	HouseDirector d(h);
	d.Construct();


}