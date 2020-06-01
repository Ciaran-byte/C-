#include<iostream>
using namespace std;

class shape  //
{
public:
	shape(){}
	virtual ~shape(){}
	virtual void square() = 0;
	virtual void draw() = 0;
};

class test :public shape
{
	test(){}
	virtual ~test(){}
};
class circle :public shape
{
public:
	circle(double radius):_radius(radius){}
	virtual~circle(){}
	virtual void square() { cout << 3.14 * _radius * _radius; }
	virtual void draw() { cout << "draw a circle" << endl; }
private:
	double _radius;
};

class rectangle :public shape
{
public:
	rectangle(double x,double y):_x(x),_y(y){}
	virtual ~rectangle(){}
	virtual void square() { cout << _x * _y << endl; }
	virtual void draw() {
		for (int i = 0; i < _x; i++)
		{
			for (int j = 0; j < _y; j++)
			{
				cout << "x" << ends;
			}
			cout << endl;
		}
		
	}
protected:
	double _x;
	double _y;
};
class sqr :public rectangle
{
public:
	sqr(double x):rectangle(x,x){}
	virtual ~sqr() {}
	//virtual void square() { rectangle::square(); }
	//virtual void draw() { rectangle::draw(); }
private:
	
	
};

int main()
{
	//01 ���麯�������麯��=0�ĺ��������д��麯��������������࣬�����಻�ܱ�ʵ����
	//shape a; //���ܱ��ɹ�����

	//02 ������ļ̳��߱����ȫ�����麯�����ǵ������򣬼̳���Ҳ���д��麯����Ҳ�ǳ�����
	//Ҳ���ܱ�ʵ����
	//test s;  //����ʹ��
	

	//03 ����һ��
	
	int a;
	
	bool go = true;
	while (go)
	{
		shape* p=nullptr;
		cout << "1 circle  2 rectangle  3 square" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
			p = new circle(5);
			p->draw();
			break;
		case 2:
			p = new rectangle(3, 5);
			p->draw();
			break;
		case 3:
			p = new sqr(5);
			p->draw();
			break;
		default:
			go = false;
			break;
		}
		delete p;
		cout << endl;
	}
	
	//04 ���麯��Ҳ���Խ���ʵ�֣��������һЩ�������ϵ�й��еĶ�������Ҫ������Ʒ�����������ʹ��
	
	return 0;
}

