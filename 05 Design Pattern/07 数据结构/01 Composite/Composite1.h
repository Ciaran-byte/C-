#pragma once
#include<iostream>
#include<list>
#include<string>
#include<algorithm>
using namespace std;

class Component
{
public:
	virtual void process() = 0;
	virtual ~Component(){}
};

//树结点
class Composite :public Component
{
	string name;
	list<Component*> elements;
public:
	Composite(const string& s):name(s){}

	void add(Component* element)
	{
		elements.push_back(element);
	}
	void remove(Component* element)
	{
		elements.remove(element);
	}

	void process()
	{
		for (auto& e : elements)
		{
			e->process(); //递归调用
		}
	}
};


//叶结点
class Leaf :public Component
{
	string name;
public:
	Leaf(string s):name(s){}
	void process(){}
};


void Invoke(Component& c)
{
	c.process();
}

void process()
{
	Composite root("root");
	Composite treeNode1("treeNode1");
	Composite treeNode2("treeNode2");
	Composite treeNode3("treeNode3");
	Composite treeNode4("treeNode4");

	Leaf Leat1("left1");
	Leaf Leat2("left2");

	root.add(&treeNode1);
	treeNode1.add(&treeNode2);
	treeNode2.add(&Leat1);

	root.add(&treeNode3);
	treeNode3.add(&treeNode4);
	treeNode4.add(&Leat2);

	Invoke(root);
}