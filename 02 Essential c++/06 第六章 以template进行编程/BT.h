#include<iostream>
using namespace std;
#pragma once

#ifndef _BT_H
#define _BT_H

//01前置声明
template <typename valType>
class BinaryTree;

template <typename valType>
class BTnode;


//02类的声明
//BTnode用来创建每一个结点，而BinaryTree则用来保存根节点
template <typename valType>
class BTnode
{
public:
	friend class BinaryTree<valType>; 
	
	//构造函数
	BTnode(const valType& val);
	
	//插入函数
	void insert_value (const valType& val);

	//删除函数
	void remove_value(const valType& val, BTnode*& prev);
	//把左结点移到右边
	static void lchild_leaf(BTnode* leaf, BTnode* subtree); 
private:
	valType _val; //保存数据
	int _cnt;   //如果数据被第二次加入树中，不添加新结点，而是原来结点数量+1
	BTnode* _lchild; //左边结点
	BTnode* _rchild;  //右边结点
};

template <typename elemType>
class BinaryTree
{
public:
	 BinaryTree(); //构造函数
	//BinaryTree(const BinaryTree&); //拷贝构造函数
	~BinaryTree(); //析构函数

	BinaryTree& operator=(const BinaryTree&); //赋值符号重载

	void insert(const elemType& elem); //插入新结点

	void remove(const elemType& elem); //删除结点

	void remove_root();

	bool empty() { return _root == 0; } //判断函数是否为空

	void clear()
	{
		if (_root)
		{
			clear(_root);
			_root = 0;
		}
	}
	void preorder( BTnode<elemType>* pt);
	  BTnode<elemType>* root() { return _root; }
private:
	BTnode<elemType> * _root;
	//void copy(BTnode<elemType>* tar, BTnode<elemType>* src); //把src的子树复制到tar的子树
	void clear(BTnode<elemType>*);
};

//03 inline函数的定义

//03-1 BinaryTree

//(1) BinaryTree构造函数
template<typename elemType>
BinaryTree<elemType>::BinaryTree() :_root(0) {}

//(2) BinaryTree拷贝构造函数
//template<typename elemType>
//BinaryTree<elemType>::BinaryTree(const BinaryTree& ths)
//{
//	copy(_root, rhs._root);
//}

//(3) BinaryTree析构函数
template<typename elemType>
BinaryTree<elemType>::~BinaryTree()
{
	clear();
}

//(4)赋值运算符重载
template<typename elemType>
BinaryTree<elemType>& 
BinaryTree<elemType>::
operator=(const BinaryTree& rhs)
{
	if (this != rhs)
	{
		clear();
		copy(_root, rhs._root);
		return *this;
	}
}

//(5) 插入运算

template<typename elemType>
void BinaryTree<elemType>::insert(const elemType& elem)
{
	if (!_root)
	{
		_root = new BTnode<elemType>(elem);
	}
	else
	{
		_root->insert_value(elem);
	}
}

//(6) 删除操作
template<typename elemType>
void BinaryTree<elemType>::remove(const elemType& elem)
{
	if (_root)
	{
		if (_root->_val == elem)
		{
			remove_root();
		}
		else
		{
			_root->remove_value(elem, _root);
		}
	}
}

//(7) 删除根节点
template<typename elemType>
void BinaryTree<elemType>::remove_root()
{
	if (!_root)return;
	BTnode<elemType>* tmp = _root;

	if (_root->_rchild)
	{
		_root = _root->_rchild;

		BTnode<elemType>* lc = tmp->_lchild;
		BTnode<elemType>* newlc = _root->_lchild;
		if (!newlc)_root->_lchild = lc;
		else
		{
			BTnode<elemType>::lchild_leaf(lc, newlc);
		}
	}
	else _root = _root->_lchild;
	delete tmp;
}

//(8)删除整棵树
template<typename elemType>
void BinaryTree<elemType>::clear(BTnode<elemType>* pt)
{
	if (pt)
	{
		clear(pt->_lchild);
		clear(pt->_rchild);
		delete this;
	}
}
template<typename elemType>
void BinaryTree<elemType>::preorder(BTnode<elemType> *pt)
{
	if (pt)
	{
		cout << pt->_val<<endl;
		preorder(pt->_lchild);
		preorder(pt->_rchild);
	}
}
//03-2 BTnode

//(1)构造函数
template<typename valType>
BTnode<valType>::
BTnode(const valType& val):_val(val)
{
	_cnt = 1;
	_lchild = 0;
	_rchild = 0;
}


//(2)插入新结点
template<typename valType>
void  BTnode<valType>::insert_value(const valType& val)
{
	if (_val == val)_cnt++;
	if (val < _val)
	{
		if (!_lchild)
		{
			_lchild = new BTnode(val);
		}
		else
		{
			_lchild->insert_value(val);
		}
	}
	else
	{
		if (!_rchild)
		{
			_rchild = new BTnode(val);
		}
		else
		{
			_rchild->insert_value(val);
		}
	}
}

//（3）移到左结点
template<typename valType>
void  BTnode<valType>::lchild_leaf(BTnode* leaf, BTnode* subtree)
{
	while (subtree->_lchild)
	{
		subtree = subtree->_lchild;
	 }
	subtree->_lchild = leaf;
}

//(4) 删除结点
template<typename valType>
void  BTnode<valType>::remove_value(const valType& val, BTnode*& prev)
{
	if (val < _val)
	{
		if (!_lchild)return;
		else
		{
			_lchild->remove_value(val, _lchild);
		}
	}
	else if (val > _val)
	{
		if (!_rchild)return;
		else _rchild->remove_value(val, _rchild);
	}
	else
	{
		if (_rchild)
		{
			prev = _rchild;
			if (_lchild)
			{
				if (!prev->_lchild)
					prev->_lchild = _lchild;
				else BTnode<valType>::lchild_leaf(_lchild, prev->_lchild);
			}
			else prev = _lchild;
			delete this;
		}
	}
}
;
#endif

