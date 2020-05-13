#include<iostream>
using namespace std;
class screen
{
	typedef size_t pos;
public:
	screen() = default; //��Ϊ����Ĭ��ֵ������ʹ��һ��Ĭ�Ϲ��캯��
	screen(pos x,pos y,char c=' '):_x(x),_y(y),_contents(x*y,c){}
	
	inline char get()
	{
		return _contents[_cursor];
	}
	inline char get(pos x, pos y)
	{
		return _contents[(x-1)*_y+y-1];
	}
	inline screen& move(pos x, pos y)
	{
		_cursor = (x - 1) * _y + y - 1;
		return *this;
	}
	inline screen& set(pos x, pos y, char c)
	{
		_contents[(x - 1) * _y + y - 1] = c;
		return *this;
	}
	inline screen& set(char c)
	{
		_contents[_cursor] = c;
		return *this;
	}


	const screen& print(ostream& os)const
	{
		myprint(os);
		return *this;
	}
	screen& print(ostream& os)
	{
		myprint(os);
		return *this;
	}
private:
	pos _x=0;
	pos _y=0;
	pos _cursor = 0;
	string _contents;
	void myprint(ostream& os)const
	{
		os << _contents<<endl;
	}
};

int main()
{
	//01 ʹ��thisʵ��ָ����������
	//��ʱ�����ǿ���ϣ�������ʵ���������ú��������ʱ��ʹ�÷����౾������þʹ�������
	//���籾���У�������move��set��������������ʵ�ְѱ�־���Ƶ�ĳ��λ�ã�Ȼ�������ַ������滻
	screen sc(5, 6, '1');
	sc.move(1, 1).set('3');


	//02 const����ķ���
	//��ʱ���������������������У����ܻ����ĳһ������������const���󣬱���print������һ�������ֲ���Ҫ����
	//���ڶ���ĺ������ܿ������Ϊconst��

	//���ʱ����Զ�const��print�����������أ�����һ����const���÷���ֵ�ġ�

	//���Ǽ�ס���������ر���Ҫ�ں����const��ǣ������޷�������������

	sc.print(cout).move(5, 6).set('3').print(cout);
	//03 С����
	//���黹��Ҫʹ��myprint����С������
	//��Ϊ�ܹ����ٱ������ظ�ʹ�ã���ʱ�������������ˣ�ֻ��Ҫ��һ������;���һ��������������Ϣ

	return 0;
}


