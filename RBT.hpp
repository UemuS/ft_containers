#pragma once
#include <iostream>



template<typename A, typename B>
struct Key{
	A 			key;
	B 			value;
};

template<typename A,typename B>
struct Node {
	Key<A,B> 	element; // key
	Node 		*parent;
	Node 		*left;
	Node 		*right;
	bool 		color; // 1 is red 0 is black
};

template <class T, class V>
struct RBTree {
		Node<T,V> *root;
		int elements;
	public:
		RBTree():root(NULL)
		{
			elements = 0;
		}
		~RBTree()
		{
		}
		Node<T,V>* getNode(T key)
		{
			Node<T,V> *current = root;
			while (current != NULL)
			{
				if (key == current->element.key)
					return current;
				else if (key < current->element.key)
					current = current->left;
				else
					current = current->right;
			}
			return NULL;
		}
		void erase(Node<T,V> *node)
		{
			if(node->left == NULL && node->right == NULL)
			{
				if(node->parent->left == node)
				{
					node->parent->left = NULL;
				}
				else
				{
					node->parent->right = NULL;
				}
				delete node;
			}
			else if(node->left == NULL)
			{
				if(node->parent->left == node)
				{
					node->parent->left = node->right;
					node->right->parent = node->parent;
				}
				else
				{
					node->parent->right = node->right;
					node->right->parent = node->parent;
				}
				delete node;
			}
			else if(node->right == NULL)
			{
				if(node->parent->left == node)
				{
					node->parent->left = node->left;
					node->left->parent = node->parent;
				}
				else
				{
					node->parent->right = node->left;
					node->left->parent = node->parent;
				}
				delete node;
			}
			else
			{
				Node<T,V> *temp = node->right;
				while(temp->left != NULL)
				{
					temp = temp->left;
				}
				node->element.key = temp->element.key;
				node->element.value = temp->element.value;
				erase(temp);
			}
		}
		void insert(T key, V value)
		{
			Node<T,V> *newNode = new Node<T,V>;
			newNode->element.key = key;
			newNode->element.value = value;
			newNode->parent = NULL;
			newNode->left = NULL;
			newNode->right = NULL;
			newNode->color = 1;
			if (root == NULL)
			{
				root = newNode;
				root->color = 0;
				return;
			}
			Node<T,V> *current = root;
			while (current != NULL)
			{
				if (current->element.key == key)
				{
					current->element.value = value;
					return;
				}
				if (current->element.key > key)
				{
					if (current->left == NULL)
					{
						current->left = newNode;
						newNode->parent = current;
						break;
					}
					current = current->left;
				}
				else
				{
					if (current->right == NULL)
					{
						current->right = newNode;
						newNode->parent = current;
						break;
					}
					current = current->right;
				}
			}
			insert_fixup(newNode);
			elements++;
		}

		void insert_fixup(Node<T,V> *node)
		{
			while (node->parent && node->parent->color == 1)
			{
				if (node->parent == node->parent->parent->left)
				{
					Node<T,V> *uncle = node->parent->parent->right;
					if (uncle && uncle->color == 1)
					{
						node->parent->color = 0;
						uncle->color = 0;
						node->parent->parent->color = 1;
						node = node->parent->parent;
					}
					else
					{
						if (node == node->parent->right)
						{
							node = node->parent;
							left_rotate(node);
						}
						node->parent->color = 0;
						node->parent->parent->color = 1;
						right_rotate(node->parent->parent);
					}
					
				}
				else
				{
					Node<T,V> *uncle = node->parent->parent->left;
					if (uncle && uncle->color == 1)
					{
						node->parent->color = 0;
						uncle->color = 0;
						node->parent->parent->color = 1;
						node = node->parent->parent;
					}
					else
					{
						if (node == node->parent->left)
						{
							node = node->parent;
							right_rotate(node);
						}
						node->parent->color = 0;
						node->parent->parent->color = 1;
						left_rotate(node->parent->parent);
					}
				}
			
			}
			root->color = 0;
		}
		void left_rotate(Node<T,V> *node)
		{
			Node<T,V> *temp = node->right;
			node->right = temp->left;
			if (temp->left != NULL)
			{
				temp->left->parent = node;
			}
			temp->parent = node->parent;
			if (node->parent == NULL)
			{
				root = temp;
			}
			else
			{
				if (node == node->parent->left)
				{
					node->parent->left = temp;
				}
				else
				{
					node->parent->right = temp;
				}
			}
			temp->left = node;
			node->parent = temp;
		}
		void right_rotate(Node<T,V> *node)
		{
			Node<T,V> *temp = node->left;
			node->left = temp->right;
			if (temp->right != NULL)
			{
				temp->right->parent = node;
			}
			temp->parent = node->parent;
			if (node->parent == NULL)
			{
				root = temp;
			}
			else
			{
				if (node == node->parent->left)
				{
					node->parent->left = temp;
				}
				else
				{
					node->parent->right = temp;
				}
			}
			temp->right = node;
			node->parent = temp;
		}	
		void printNodes(Node<T,V> *node)
		{
			if (node == NULL)
			{
				return;
			}
			printNodes(node->left);
			std::cout << node->element.key << " " << node->element.value << " " << node->color << "\n";
			printNodes(node->right);
		}
		void clear(Node<T,V> *node)
		{
			if (node == NULL)
			{
				return;
			}
			clear(node->left);
			clear(node->right);
			delete node;
		}
		void clearTree()
		{
			clear(root);
			root = NULL;
			elements = 0;
		}
};