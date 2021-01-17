#pragma once
/**
* @file Strategy1.h
*  @brief 该代码模拟了不同国家交税方法不一样的一个场景
* 
* */

enum TaxBase
{
	CN_Tax, /**< CN 0  */
	US_Tax,/**< US 1  */
	DE_Tax /**< DE 2  */

};

/**
* @brief 税收处理类
* 
**/
class SalesOrder
{
public:
	double CalculateTax()
	{
		if (tax == CN_Tax)
		{

		}
		else if (tax == US_Tax)
		{

		}
		else if (tax == DE_Tax)
		{

		}
	}
private:
	TaxBase tax;
};

