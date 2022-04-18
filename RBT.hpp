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
		Node<Pair> *Null;
		Node<Pair> *root;
		int elements;
	public:
		RBTree()
		{
			elements = 0;
			Null = new Node<Pair>;
			Null->color = 0;
			Null->left = NULL;
			Null->right = NULL;
			root= Null;
		}
		~RBTree()
		{
		}
		

		int depth(Node<Pair> *node)
		{
			if(node == Null)
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
			newNode->parent = Null;
			newNode->left = Null;
			newNode->right = Null;
			newNode->color = 1;
			if (root == Null)
			{
				root = newNode;
				root->color = 0;
				return;
			}
			Node<Pair> *current = root;
			while (current != Null)
			{
				if (!Compare()(value.first , current->element.first) && !Compare()(current->element.first, value.first))
				{
					current->element = value;
					return;
				}
				if (Compare()(value.first, current->element.first))
				{
					if (current->left == Null)
					{
						current->left = newNode;
						newNode->parent = current;
						break;
					}
					current = current->left;
				}
				else
				{
					if (current->right == Null)
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
			while (current != Null)
			{
				if (Compare()(key, current->element.first))
				{
					current = current->left;
				}
				else if (Compare()(current->element.first, key))
				{
					current = current->right;
				}
				else
				{
					return current;
				}
			}
			return Null;
		}

		Node<Pair> *succesor(Node<Pair> *node)
		{
			if (node->right != Null)
			{
				node = node->right;
				while (node->left != Null)
				{
					node = node->left;
				}
				return node;
			}
			else
			{
				Node<Pair> *current = node;
				while (current->parent != Null && current->parent->right == current)
				{
					current = current->parent;
				}
				return current->parent;
			}
		}
		
		void transplant(Node<Pair> *u, Node<Pair> *v)
		{
			if (!u->parent)
			{
				root = v;
			}
			else if (u == u->parent->left)
			{
				u->parent->left = v;
			}
			else
			{
				u->parent->right = v;
			}
			v->parent = u->parent;
		}
		void deleteFix(Node<Pair> *node)
		{
			std::cout << node->element.first << std::endl;
			Node<Pair> *sibling;
			while (node != root && node->color == 0)
			{
				if (node == node->parent->left)
				{
					sibling = node->parent->right;
					if (sibling->color == 1)
					{
						sibling->color = 0;
						node->parent->color = 1;
						left_rotate(node->parent);
						sibling = node->parent->right;
					}
					if (sibling->left->color == 0 && sibling->right->color == 0)
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
	


		Node<Pair> *minimum(Node<Pair> *node)
		{
			while (node->left != Null)
			{
				node = node->left;
			}
			return node;
		}

		void deleteNode(T key)
		{
			Node<Pair> *z = getNode(key);
    		Node<Pair> *x;
			Node<Pair> *y;
			
			if (z == Null)
			{
				return;
			}
			y = z;
			int y_original_color = y->color;
			if (z->left == Null)
			{
				x = z->right;
				transplant(z, z->right);
			}
			else if (z->right == Null)
			{
				x = z->left;
				transplant(z, z->left);
			}
			else
			{
				y = minimum(z->right);
				y_original_color = y->color;
				x = y->right;
				if (y->parent == z)
				{
					x->parent = y;
				}
				else
				{
					transplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}
				transplant(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			}
			if (y_original_color == 0)
			{
				deleteFix(x);
			}
		}
		




		Node<Pair> *predecessor(Node<Pair> *node)
		{
			if (node->left != Null)
			{
				node = node->left;
				while (node->right != Null)
				{
					node = node->right;
				}
				return node;
			}
			else
			{
				Node<Pair> *current = node;
				while (current->parent != Null && current->parent->left == current)
				{
					current = current->parent;
				}
				return current->parent;
			}
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
			if (temp->left != Null)
			{
				temp->left->parent = node;
			}
			temp->parent = node->parent;
			if (node->parent == Null)
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
			if (temp->right != Null)
			{
				temp->right->parent = node;
			}
			temp->parent = node->parent;
			if (node->parent == Null)
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
		
		void print(Node<Pair> *node)
		{
			if (node != Null)
			{
				print(node->left);
				std::cout << node->element.first << " " << node->element.second << std::endl;
				print(node->right);
			}
		}
		void clear(Node<Pair> *node)
		{
			if (node == Null)
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
			root = Null;
			elements = 0;
		}
};