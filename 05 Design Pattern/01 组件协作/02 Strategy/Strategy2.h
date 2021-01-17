#pragma once
/**
* @file Strategy2.h
*  @brief 该代码使用了策略模式，以应对可能还有很多个国家的税收政策实现
*
* */


/**
* @brief 抽象出来的税收策略
* 
* */
class TaxStrategy
{
public:
	virtual double Calculate(const contex& contex) = 0;
	virtual ~TaxStrategy(){}

};


/**
* @brief 具象化的一种税收方法
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