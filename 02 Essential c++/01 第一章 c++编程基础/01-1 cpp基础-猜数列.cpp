#include<iostream>
#include<string>
#include<vector>
#include<random>
#include<time.h>
using namespace std;

int main()
{
	//01�������

	string first_name, last_name;//�����û���

	int correct_guess=0; //���˼���
	int all_guess=0;   //һ�����˼���

	int user_val; //�û����������
	
	bool next_seq=true;//Ҫ��Ҫ����һ��
	bool go_for_it=true;//����Ҫ��Ҫ����

	int select_sequence; //ѡ���ĸ�����
	

	
	
	//�����������
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
	//�������еĵ�ַ
	vector<int>* p[6] =
	{
		&Fibonacci,
		&Lucas,
		&Pell,
		&Triangular,
		&Square,
		&Pentagonal

	};
	//�������е�����
	vector<string> names =
	{
		"Fibonacci",
		"Lucas",
		"Pell",
		"Triangular",
		"Square",
		"Pentagonal"

	};
	//�����
	
	

	//����ֵ
	int seq_num = 0;
	

	//�û������Y��N���������Ƿ�������ж�
	char user_rsp;

	//�û��´��˼���
	int user_tries;

	
	
    //02 �����û���Ϣ������ʾ��ӭ
	
	cout << "please input your first name!" << endl;
	cin >> first_name;
	cout << "pleast input your last name!" << endl;
	cin >> last_name;
	cout << "hell! " << first_name << " " << last_name << endl;



		//03 ������Ϸ����
		while(next_seq)
		{ 
		   //03-1 ��ȡһ������
			
			go_for_it = true;

			srand(time(NULL));
			select_sequence = rand() % 6;
			vector<int>* q = p[select_sequence];

			//srand(select_sequence);
			seq_num = rand() % 6;
			

			cout << "����������" << endl;
			cout << (*q)[seq_num] << " " << (*q)[seq_num + 1] << endl;
			user_tries = 0;
			
			
			//03-2 ��ʼ����ÿ�����еĲ²�
			while(go_for_it)
			{
				//03-3 �û������
				cout << "��������Ĵ�" << endl;
				cin >> user_val;

				all_guess++;//������Ϸ�Ĳ²��������

				//03-4�¶��˾���Ҫ��Ҫ�ٲ�һ��
				if(user_val== (*q)[seq_num + 2])
				{ 
					 correct_guess++;
					 cout << "yes!you're right!" << endl;
					 cout << "this is " << names[select_sequence] << endl;
					

				go_for_it = false;
							
								
						
				}
				//03-5 �´��˾���Ҫ��Ҫ����һ�Σ�����ÿ�λ�Ӧ����һ������´�����й�ϵ
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
					
					
					//��ֹ����N��Y�������ĸ
					bool rst=true;
					while (rst)
					{
						cout << "another try��please keyboard Y or N" << endl;
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

			//03-6 �¶���Ҫ��Ҫ�ٲ�һ���µ�����
			bool nxt=true;
			while (nxt)
			{
				//�벻���ٲ�һ������
				cout << "do you like guess another  num ? please keyboard Y or N" << endl;
				cin >> user_rsp;

				//��ֹ��������ģ�ֻ������N��Y��������ѭ��
				if (user_rsp == 'n' || user_rsp == 'N' || user_rsp == 'y' || user_rsp == 'Y')
				{
					nxt = false;


					//����ͽ���
					if (user_rsp == 'n' || user_rsp == 'N')
					{
						next_seq = false;


					}
					else
					{
						//����������¼�3
						seq_num += 3;
					}

					
				}
			}
		}

		//04 ���������Ϸ�Ľ��
		
		cout << endl << endl;
		cout << first_name << " " << last_name << " the results are:" << endl;
		cout << "all_guess " << all_guess<<endl;
		cout << "correct_guess " << correct_guess << endl;
	return 0;
}


