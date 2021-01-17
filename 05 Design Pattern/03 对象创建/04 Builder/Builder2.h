#pragma once


//������ģʽ
//�Խ��췿��Ϊ�������������ݶ����š����ȣ����̴�����ͬ
//�����š��ݶ�������Щ�����ֲ���ȫ��ͬ��
//��Ҫ������̴�����ͬ�����Ǹ������費��ȫ��ͬ������
//��Ϊ��Ƚϸ��ӣ��Ͳ��Ϊ���ݺͽ�����������

//----------���ӵ�����--------------
class House
{
	
public:

protected:
	//������window��door�ȵȾ���Ķ���
	
};

class StoneHouse : public House
{
protected:


};

//-------------------���ӵĹ���------------------
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

//HouseDirector���ȶ���״̬����Ҫ��д��ʱ�����дHouseBuilder
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