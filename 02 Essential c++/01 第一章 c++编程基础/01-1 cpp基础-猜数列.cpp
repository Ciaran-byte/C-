#include<iostream>
#include<string>
#include<vector>
#include<random>
#include<time.h>
using namespace std;

int main()
{
	//01定义变量

	string first_name, last_name;//输入用户名

	int correct_guess=0; //对了几次
	int all_guess=0;   //一共猜了几次

	int user_val; //用户输入的数字
	
	bool next_seq=true;//要不要再来一个
	bool go_for_it=true;//错了要不要继续

	int select_sequence; //选择哪个序列
	

	
	
	//定义各个序列
	vector<int> Fibonacci =
	{
		1,1,2,3,5,8,13,21
	};
	vector<int> Lucas =
	{
		1,3,4,7,11,18,29,47
	};
	vector<int> Pell =
	{
		1,2,5,12,29,70,169,408
	};
	vector<int> Triangular
	{
		1,3,6,10,15,21,28,36
	};
	vector<int> Square =
	{
		1,4,9,16,25,36,49,64
	};
	vector<int> Pentagonal =
	{
		1,5,12,22,35,51,70,92
	};
	//各个序列的地址
	vector<int>* p[6] =
	{
		&Fibonacci,
		&Lucas,
		&Pell,
		&Triangular,
		&Square,
		&Pentagonal

	};
	//各个序列的名字
	vector<string> names =
	{
		"Fibonacci",
		"Lucas",
		"Pell",
		"Triangular",
		"Square",
		"Pentagonal"

	};
	//随机数
	
	

	//索引值
	int seq_num = 0;
	

	//用户输入的Y和N，用来做是否继续的判断
	char user_rsp;

	//用户猜错了几次
	int user_tries;

	
	
    //02 输入用户信息，并表示欢迎
	
	cout << "please input your first name!" << endl;
	cin >> first_name;
	cout << "pleast input your last name!" << endl;
	cin >> last_name;
	cout << "hell! " << first_name << " " << last_name << endl;



		//03 进入游戏环节
		while(next_seq)
		{ 
		   //03-1 读取一组数列
			
			go_for_it = true;

			srand(time(NULL));
			select_sequence = rand() % 6;
			vector<int>* q = p[select_sequence];

			//srand(select_sequence);
			seq_num = rand() % 6;
			

			cout << "下面是数列" << endl;
			cout << (*q)[seq_num] << " " << (*q)[seq_num + 1] << endl;
			user_tries = 0;
			
			
			//03-2 开始进入每组数列的猜测
			while(go_for_it)
			{
				//03-3 用户输入答案
				cout << "请输入你的答案" << endl;
				cin >> user_val;

				all_guess++;//整个游戏的猜测的总数量

				//03-4猜对了就问要不要再猜一个
				if(user_val== (*q)[seq_num + 2])
				{ 
					 correct_guess++;
					 cout << "yes!you're right!" << endl;
					 cout << "this is " << names[select_sequence] << endl;
					

				go_for_it = false;
							
								
						
				}
				//03-5 猜错了就问要不要再试一次，并且每次回应都不一样，与猜错次数有关系
				else  
				{ 
					user_tries++;
					switch (user_tries)
					{
					case 1:
						cout << "oh,no!wrong!" << endl;
						break;
					case 2:
						cout << " wrong a second time" << endl;
						break;
					case 3:
						cout << "this is harder than it looks,isn't it?" << endl;
						break;
					default:
						cout << "you must be frustrated,come on!" << endl;
						break;
					
					}
					
					
					//防止输入N和Y以外的字母
					bool rst=true;
					while (rst)
					{
						cout << "another try？please keyboard Y or N" << endl;
						cin >> user_rsp;
						if (user_rsp == 'n' || user_rsp == 'N' || user_rsp == 'y' || user_rsp == 'Y')
						{
							rst = false;
						}
						if (user_rsp == 'n' || user_rsp == 'N')
						{

							go_for_it = false;

						}
					}
					
					

				}
					
			}

			//03-6 猜对了要不要再猜一组新的数据
			bool nxt=true;
			while (nxt)
			{
				//想不想再猜一个数组
				cout << "do you like guess another  num ? please keyboard Y or N" << endl;
				cin >> user_rsp;

				//防止错误输入的，只有输入N或Y才能跳出循环
				if (user_rsp == 'n' || user_rsp == 'N' || user_rsp == 'y' || user_rsp == 'Y')
				{
					nxt = false;


					//不想就结束
					if (user_rsp == 'n' || user_rsp == 'N')
					{
						next_seq = false;


					}
					else
					{
						//数量序号往下加3
						seq_num += 3;
					}

					
				}
			}
		}

		//04 输出整个游戏的结果
		
		cout << endl << endl;
		cout << first_name << " " << last_name << " the results are:" << endl;
		cout << "all_guess " << all_guess<<endl;
		cout << "correct_guess " << correct_guess << endl;
	return 0;
}


