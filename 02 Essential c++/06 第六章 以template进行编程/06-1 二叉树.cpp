#include<iostream>
#include "BT.h"
using namespace std;

int main()
{
	BinaryTree<string> bt;

	bt.insert("piglet");
	bt.insert("eeyore");
	bt.insert("roo");
	bt.insert("tigger");
	bt.insert("chris");
	bt.insert("pooh");
	bt.insert("kanga");

	cout << "preorder tranversal" << endl;
	bt.preorder(bt.root());

	bt.remove("piglet");
	cout << endl << endl;
	cout << "preorder tranversal" << endl;
	bt.preorder(bt.root());


	cout << endl << endl;
	bt.remove("eeyore");
		cout << "preorder tranversal" << endl;
		bt.preorder(bt.root());

	return 0;
}

