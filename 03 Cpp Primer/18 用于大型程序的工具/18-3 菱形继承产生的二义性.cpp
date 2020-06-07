#include<iostream>
using std::cout;
using std::endl;
enum COLOR { Red, Green, Brown, White, Black, Browno };
class Animal
{
public:
	Animal(int age) :itsAge(age) { cout << "Animal 构造！" << endl; }
	virtual ~Animal() { cout << "Animal析构！" << endl; }
	virtual int GetAge() { return itsAge; }
	virtual void SetAge(int age) { itsAge = age; }
private:
	int itsAge;
};
class Horse:public Animal
{
public:
	Horse(int height, COLOR color,int age) :Animal(age),itsHeight(height), color(color)
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
class Bird :public Animal
{
public:
	Bird(bool migration, COLOR color,int age) :Animal(age),itsMigration(migration), color(color) {
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
	Pegasus(int length, bool migration, long beliver, COLOR color,int age) :Bird(migration, color,age), Horse(length, color,age), itsNumberBelievers(beliver)
	{
		cout << "Pegasus构造！" << endl;
	}
	virtual ~Pegasus() { cout << "pegasus析构!" << endl; }
	virtual long GetNumberBelievers()const
	{
		return itsNumberBelievers;
	}

private:
	long itsNumberBelievers;

};
int main()
{
	//bird和house继承animal，pegasus继承了bird和house
	
	//因为bird和house继承了animal与age相关的东西，而pegasus又从bird和house处继承了这些，不知道该调用谁的了

	//为了解决菱形继承产生的二义性，出现了虚基类

	Pegasus* p = new Pegasus(5, true, 100, Red, 2);
	

	return 0;

}

