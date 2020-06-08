#include<iostream>
using std::cout;
using std::endl;
enum COLOR{Red,Green,Brown,White,Black,Browno};
class Horse
{
public:
	Horse(int height,COLOR color) :itsHeight(height),color(color)
	{
		cout << "horse构造！" << endl;
	}
	virtual ~Horse(){
		cout << "horse析构！" << endl;
	}
	virtual void Whinny()const
	{
		std::cout << "Whinny" << std::endl;
	}
	virtual int GetHeight()const { return itsHeight; }
	virtual COLOR getColor() { return color; }
private:
	int itsHeight;
	COLOR color;
};
class Bird
{
public:
	Bird(bool migration, COLOR color) :itsMigration(migration),color(color) {
		cout << "bird 构造！" << endl;
	}
	virtual void Chirp()const { cout << "chirp!" << endl; }
	virtual ~Bird() { cout << "Bird析构！" << endl; }
	virtual void Fly()const
	{
		cout << "I can fly" << endl;
	}
	virtual bool GetMigration()const { return itsMigration; }
	virtual COLOR getColor() { return color; }
private:
	bool itsMigration;
	COLOR color;

};

class Pegasus :public Bird, public Horse
{
public:
	virtual void Chirp()const override
	{
		Whinny();
	}
	Pegasus(int length,bool migration,long beliver,COLOR color):Bird(migration,color),Horse(length,color),itsNumberBelievers(beliver)
	{
		cout << "Pegasus构造！" << endl;
	}
	virtual ~Pegasus() { cout << "pegasus析构!" << endl;}
	virtual long GetNumberBelievers()const
	{
		return itsNumberBelievers;
	}
	
private:
	long itsNumberBelievers;
	
};
int main()
{
	
	Pegasus* p = new Pegasus(5, true, 10,Green);
	p->Fly();
	p->Whinny();
	p->Chirp();
	cout << "有" << p->GetNumberBelievers() << "人相信世界上有飞马" << endl;
	//p->getColor() << endl; //两个父类都有该函数，产生二义性问题
	cout << p->Bird::getColor() << endl;//解决二义性问题
	delete p;
	
	return 0;

}

