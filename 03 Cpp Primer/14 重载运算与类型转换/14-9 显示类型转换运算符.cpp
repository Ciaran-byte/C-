#include<iostream>
using namespace std;
class mycls
{
public:
	 explicit mycls(int a) :_a(a) { cout << "���캯����" << endl; }
	explicit operator int()const
	{
		return _a;
	}
	mycls& operator=(const mycls& cms)
	{
		cout << "�������ƺ�����" << endl;
		_a = cms._a;
	}
	mycls(const mycls& cls)
	{
		cout << "�������죡" << endl;
		_a = cls._a;
	}
	~mycls()
	{
		cout << "����!" << endl;
	}
private:
	int _a;
};

int main()
{
	
	mycls b = static_cast<mycls>(5);
	mycls c = mycls(5);

	int a = static_cast<int>(b);

	//�����캯��������ת����������Ϊexplict�󣬽�����ͨ����������������ʽ��ת��������Ҫ������ת������������ʾת��
	
	
	return 0;
}

