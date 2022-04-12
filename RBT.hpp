#pragma once
#include <iostream>



template<typename Pair>
struct Node {
	Pair 		element; // key
	Node 		*parent;
	Node 		*left;
	Node 		*right;
	bool 		color; // 1 is red 0 is black
};


template <class T, class Pair, typename Compare = std::less<T> >
struct RBTree {
		Node<Pair> *root;
		int elements;
	public:
		RBTree():root(NULL)
		{
			elements = 0;
		}
		~RBTree()
		{
		}
		

		int depth(Node<Pair> *node)
		{
			if(node == NULL)
			{
				return 0;
			}
			int left = depth(node->left);
			int right = depth(node->right);
			return (left > right ? left : right) + 1;
		}


		void insert(T key, Pair value)
		{
			Node<Pair> *newNode = new Node<Pair>;
			newNode->element = value;
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
			Node<Pair> *current = root;
			while (current != NULL)
			{
				if (!Compare()(value.first , current->element.first) && !Compare()(current->element.first, value.first))
				{
					current->element = value;
					return;
				}
				if (Compare()(value.first, current->element.first))
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

		Node<Pair> *getNode(T key)
		{
			Node<Pair> *current = root;
			while (current != NULL)
			{
				if (!Compare()(key, current->element.first) && !Compare()(current->element.first, key))
				{
					return current;
				}
				if (Compare()(key, current->element.first))
				{
					current = current->left;
				}
				else
				{
					current = current->right;
				}
			}
			return NULL;
		}

		void delete_fixup(Node<Pair> *node)
		{
			Node<Pair> *sibling;
			while (node != root && node->color == 0)
			{
				if (node == node->parent->left)
				{
					sibling = node->parent->right;
					if (sibling && sibling->color == 1)
					{
						sibling->color = 0;
						node->parent->color = 1;
						left_rotate(node->parent);
						sibling = node->parent->right;
					}
					if (sibling && sibling->left->color == 0 && sibling->right->color == 0)
					{
						sibling->color = 1;
						node = node->parent;
					}
					else
					{
						if (sibling->right->color == 0)
						{
							sibling->left->color = 0;
							sibling->color = 1;
							right_rotate(sibling);
							sibling = node->parent->right;
						}
						sibling->color = node->parent->color;
						node->parent->color = 0;
						sibling->right->color = 0;
						left_rotate(node->parent);
						node = root;
					}
				}
				else
				{
					sibling = node->parent->left;
					if (sibling->color == 1)
					{
						sibling->color = 0;
						node->parent->color = 1;
						right_rotate(node->parent);
						sibling = node->parent->left;
					}
					if (sibling->right->color == 0 && sibling->left->color == 0)
					{
						sibling->color = 1;
						node = node->parent;
					}
					else
					{
						if (sibling->left->color == 0)
						{
							sibling->right->color = 0;
							sibling->color = 1;
							left_rotate(sibling);
							sibling = node->parent->left;
						}
						sibling->color = node->parent->color;
						node->parent->color = 0;
						sibling->left->color = 0;
						right_rotate(node->parent);
						node = root;
					}
				}
			}
			node->color = 0;
		}


		Node<Pair> *successor(Node<Pair> *node)
		{
			if (node->right != NULL)
			{
				Node<Pair> *current = node->right;
				while (current->left != NULL)
				{
					current = current->left;
				}
				return current;
			}
			else
			{
				Node<Pair> *current = node->parent;
				Node<Pair> *child = node;
				while (current != NULL && child == current->right)
				{
					child = current;
					current = current->parent;
				}
				return current;
			}
		}
		void deleteNode(Node<Pair> *node)
		{
			Node<Pair> *temp;
			if (node->left == NULL || node->right == NULL)
			{
				temp = node;
			}
			else
			{
				temp = successor(node);
			}
			Node<Pair> *child;
			if (temp->left != NULL)
			{
				child = temp->left;
			}
			else
			{
				child = temp->right;
			}
			if (child != NULL)
			{
				child->parent = temp->parent;
			}
			if (temp->parent == NULL)
			{
				root = child;
			}
			else
			{
				if (temp == temp->parent->left)
				{
					temp->parent->left = child;
				}
				else
				{
					temp->parent->right = child;
				}
			}
			if (temp != node)
			{
				node->element = temp->element;
			}
			if (temp->color == 0)
			{
				delete_fixup(child);
			}
			delete temp;
			elements--;
		}
		void insert_fixup(Node<Pair> *node)
		{
			while (node->parent && node->parent->color == 1)
			{
				if (node->parent == node->parent->parent->left)
				{
					Node<Pair> *uncle = node->parent->parent->right;
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
					Node<Pair> *uncle = node->parent->parent->left;
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
		void left_rotate(Node<Pair> *node)
		{
			Node<Pair> *temp = node->right;
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
		void right_rotate(Node<Pair> *node)
		{
			Node<Pair> *temp = node->left;
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
		void printNodes(Node<Pair> *node)
		{
			if (node == NULL)
			{
				return;
			}
			printNodes(node->left);
			std::cout << node->element.first << " " << node->element.second << " " << node->color << "\n";
			printNodes(node->right);
		}
		void clear(Node<Pair> *node)
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