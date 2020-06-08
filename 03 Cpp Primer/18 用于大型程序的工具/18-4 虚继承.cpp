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
class Horse :virtual public Animal
{
public:
	Horse(int height, COLOR color, int age) :Animal(age), itsHeight(height), color(color)
	{
		cout << "horse构造！" << endl;
	}
	virtual ~Horse() {
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
class Bird :virtual public Animal
{
public:
	Bird(bool migration, COLOR color, int age) :Animal(age), itsMigration(migration), color(color) {
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
	Pegasus(int length, bool migration, long beliver, COLOR color, int age) 
		:Bird(migration, color, age), 
		Horse(length, color, age), 
		Animal(age),
		itsNumberBelievers(beliver)
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
	

	Pegasus* p = new Pegasus(5, true, 100, Red, 2);

	//虚继承必须要通过孙子构建爷爷。因为爸爸和妈妈就不去构造爷爷了
	p->GetAge();
	//虚继承中，由最后的派生类，去构造最初的虚基类
	return 0;

}

