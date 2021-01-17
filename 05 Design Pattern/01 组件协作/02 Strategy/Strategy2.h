#pragma once
/**
* @file Strategy2.h
*  @brief �ô���ʹ���˲���ģʽ����Ӧ�Կ��ܻ��кܶ�����ҵ�˰������ʵ��
*
* */


/**
* @brief ���������˰�ղ���
* 
* */
class TaxStrategy
{
public:
	virtual double Calculate(const contex& contex) = 0;
	virtual ~TaxStrategy(){}

};


/**
* @brief ���󻯵�һ��˰�շ���
*
* */
class CNTAX :public TaxStrategy
{
public:
	virtual double Calculate(const contex& contex)
	{


	}

};

class SalesOrder
{
private:
	TaxStrategy* strategy;
public:
	SalesOrder(StrategyFactory* strategyFactory)
	{
		this->strategy = strategyFactory->NewStrategy();
	}

	~SalesOrder()
	{
		delete this->strategy;
	}

	public double CalculateTax()
	{
		Contex contex();

		double val = strategy->Calculate(contex);
	}
};