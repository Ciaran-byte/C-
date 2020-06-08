#include<iostream>
using std::cout;
using std::endl;
enum COLOR { Red, Green, Brown, White, Black, Browno };
class Animal
{
public:
	Animal(int age) :itsAge(age) { cout << "Animal ���죡" << endl; }
	virtual ~Animal() { cout << "Animal������" << endl; }
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
		cout << "horse���죡" << endl;
	}
	virtual ~Horse(){
		cout << "horse������" << endl;
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
		cout << "bird ���죡" << endl;
	}
	virtual void Chirp()const { cout << "chirp!" << endl; }
	virtual ~Bird() { cout << "Bird������" << endl; }
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
		cout << "Pegasus���죡" << endl;
	}
	virtual ~Pegasus() { cout << "pegasus����!" << endl; }
	virtual long GetNumberBelievers()const
	{
		return itsNumberBelievers;
	}

private:
	long itsNumberBelievers;

};
int main()
{
	//bird��house�̳�animal��pegasus�̳���bird��house
	
	//��Ϊbird��house�̳���animal��age��صĶ�������pegasus�ִ�bird��house���̳�����Щ����֪���õ���˭����

	//Ϊ�˽�����μ̳в����Ķ����ԣ������������

	Pegasus* p = new Pegasus(5, true, 100, Red, 2);
	

	return 0;

}

