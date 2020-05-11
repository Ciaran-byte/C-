#include<iostream>
using namespace std;

//01 递归的引入-自己调用自己
void 老奶奶讲故事()
{
	cout << "从前有座山，山里有座庙。庙里有个小和尚在讲故事：" << endl;
	老奶奶讲故事();
}

//02 阶乘
int 阶乘(int val)
{
	if (val == 0)
		return 1;
	else
		return val * 阶乘(val - 1);
}
int main()
{
	//01 递归的引入 自己调用自己
	//老奶奶讲故事();

	//02 阶乘
	cout << 阶乘(5) << endl;

	//递归的优点：便于理解
	//递归的缺点： 占用大量内容
	return 0;
}

