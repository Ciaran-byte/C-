#pragma once
/**
* @file Strategy1.h
*  @brief �ô���ģ���˲�ͬ���ҽ�˰������һ����һ������
* 
* */

enum TaxBase
{
	CN_Tax, /**< CN 0  */
	US_Tax,/**< US 1  */
	DE_Tax /**< DE 2  */

};

/**
* @brief ˰�մ�����
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

