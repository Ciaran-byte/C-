#include<iostream>
using namespace std;
#pragma once

#ifndef _BT_H
#define _BT_H

//01ǰ������
template <typename valType>
class BinaryTree;

template <typename valType>
class BTnode;


//02�������
//BTnode��������ÿһ����㣬��BinaryTree������������ڵ�
template <typename valType>
class BTnode
{
public:
	friend class BinaryTree<valType>; 
	
	//���캯��
	BTnode(const valType& val);
	
	//���뺯��
	void insert_value (const valType& val);

	//ɾ������
	void remove_value(const valType& val, BTnode*& prev);
	//�������Ƶ��ұ�
	static void lchild_leaf(BTnode* leaf, BTnode* subtree); 
private:
	valType _val; //��������
	int _cnt;   //������ݱ��ڶ��μ������У�������½�㣬����ԭ���������+1
	BTnode* _lchild; //��߽��
	BTnode* _rchild;  //�ұ߽��
};

template <typename elemType>
class BinaryTree
{
public:
	 BinaryTree(); //���캯��
	//BinaryTree(const BinaryTree&); //�������캯��
	~BinaryTree(); //��������

	BinaryTree& operator=(const BinaryTree&); //��ֵ��������

	void insert(const elemType& elem); //�����½��

	void remove(const elemType& elem); //ɾ�����

	void remove_root();

	bool empty() { return _root == 0; } //�жϺ����Ƿ�Ϊ��

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
	//void copy(BTnode<elemType>* tar, BTnode<elemType>* src); //��src���������Ƶ�tar������
	void clear(BTnode<elemType>*);
};

//03 inline�����Ķ���

//03-1 BinaryTree

//(1) BinaryTree���캯��
template<typename elemType>
BinaryTree<elemType>::BinaryTree() :_root(0) {}

//(2) BinaryTree�������캯��
//template<typename elemType>
//BinaryTree<elemType>::BinaryTree(const BinaryTree& ths)
//{
//	copy(_root, rhs._root);
//}

//(3) BinaryTree��������
template<typename elemType>
BinaryTree<elemType>::~BinaryTree()
{
	clear();
}

//(4)��ֵ���������
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

//(5) ��������

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

//(6) ɾ������
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

//(7) ɾ�����ڵ�
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

//(8)ɾ��������
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

//(1)���캯��
template<typename valType>
BTnode<valType>::
BTnode(const valType& val):_val(val)
{
	_cnt = 1;
	_lchild = 0;
	_rchild = 0;
}


//(2)�����½��
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

//��3���Ƶ�����
template<typename valType>
void  BTnode<valType>::lchild_leaf(BTnode* leaf, BTnode* subtree)
{
	while (subtree->_lchild)
	{
		subtree = subtree->_lchild;
	 }
	subtree->_lchild = leaf;
}

//(4) ɾ�����
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

