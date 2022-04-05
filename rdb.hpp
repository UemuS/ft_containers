#pragma once
#include <iostream>

template<class Key_type, class Value_type>
struct Node {
	Key_type key; // key
	Node *parent;
	Node *left;
	Node *right;
	Value_type value;
	int color; // 1 is red 0 is black
};

template <class T>
class RBTree {
	public:
		typedef Node* pointer;
	private:
		pointer root;
		pointer isNull;

		void initNullNode()
		{
			isNull = new Node<T, T>;
			isNull->parent = isNull;
			isNull->left = NULL;
			isNull->right = NULL;
			isNull->color = 0;
		}
};