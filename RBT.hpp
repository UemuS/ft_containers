#pragma once
#include <iostream>
#include "treeiterator.hpp"
#include "iterator.hpp"
namespace ft
{
	
template<typename Pair>
struct Node {
	Pair 		element; // pair
	Node 		*parent;
	Node 		*left;
	Node 		*right;
	bool 		color; // 1 is red 0 is black
	bool 		is_null;

	Node(Pair a = Pair()) : element(a) {}
};


template<typename value_type>
Node<value_type> *maximum(Node<value_type>  *node)
{
	while (node->right && node->right->is_null == false)
	{
		node = node->right;
	}
	return node;
}

template<typename value_type>
Node<value_type> *minimum(Node<value_type> *node)
{
	while (node->left  && node->left->is_null == false)
	{
		node = node->left;
	}
	return node;
}

template<typename Node_T>
Node_T*predecessor(Node_T *node)
{
	if (node && node->is_null)
	{
		return (maximum(node->left));
	}
	if (node->left && node->left->is_null == false)
	{
		node = node->left;
		while (node->right && node->right->is_null == false)
		{
			node = node->right;
		}
		return node;
	}
	else
	{
		Node_T *current = node;
		while (current->parent && current->parent->is_null == false && current->parent->left == current)
		{
			current = current->parent;
		}
		return current->parent;
	}
}

template<typename Node_T>
Node_T *succesor(Node_T *node)
{
	if (node->right && node->right->is_null == false)
	{
		node = node->right;
		while (node->left && node->left->is_null == false)
		{
			node = node->left;
		}
		return node;
	}
	else
	{
		Node_T *current = node;
		while (current->parent && current->parent->is_null == false && current->parent->right == current)
		{
			current = current->parent;
		}
		return current->parent;
	}
}

template <class T, class Pair, typename Compare, typename _Alloc >
struct RBTree {
		Node<Pair> *Null;
		Node<Pair> *root;
		size_t elements;
		Compare comp;
		typedef typename _Alloc::template rebind<Node<Pair> >::other 	alloc;
		alloc allocator;
		typedef ft::bin_iterator<Pair> iterator;
		typedef ft::const_bin_iterator<Pair> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
	public:
		RBTree()
		{
			comp = Compare();
			elements = 0;
			Null = allocator.allocate(1);
			allocator.construct(Null, Pair());
			Null->color = 0;
			Null->left = NULL;
			Null->right = NULL;
			Null->is_null = 1;
			root= Null;
		}
		RBTree(Compare cm, alloc al)
		{
			comp = cm;
			allocator = al;
			elements = 0;
			Null = allocator.allocate(1);
			allocator.construct(Null, Pair());
			Null->color = 0;
			Null->left = NULL;
			Null->right = NULL;
			Null->is_null = 1;
			root = Null;
		}
		RBTree(const RBTree &other)
		{
			comp = other.comp;
			Null = allocator.allocate(1);
			allocator.construct(Null, Pair());
			Null->color = 0;
			Null->left = NULL;
			Null->right = NULL;
			Null->is_null = 1;
			root = deepCopy(other.root, Null);
			elements = other.elements;
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


		ft::pair<Node<Pair>*, bool> insert(Pair value)
		{
			Node<Pair> *newNode;
			newNode = allocator.allocate(1);
			allocator.construct(newNode, value);
			newNode->parent = Null;
			newNode->left = Null;
			newNode->right = Null;
			newNode->is_null = 0;
			newNode->color = 1;
			if (root == Null)
			{
				root = newNode;
				root->color = 0;
				Null->left = root;
				elements++;
				return ft::make_pair(root, true);
			}
			Node<Pair> *current = root;
			while (current != Null)
			{
				if (!comp(value , current->element) && !comp(current->element, value))
				{
					return (ft::make_pair(current, false));
				}
				if (comp(value, current->element))
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

			return (ft::make_pair(newNode, true));
		}

		Node<Pair> *getNode(T key)
		{
			Node<Pair> *current = root;
			while (current != Null)
			{
				if (comp(key, current->element))
				{
					current = current->left;
				}
				else if (comp(current->element, key))
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

		
		void transplant(Node<Pair> *u, Node<Pair> *v)
		{
			if (u->parent == Null)
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
			Null->left = root;
			root->parent = Null;
			node->color = 0;
		}
	
		iterator begin()
		{
			return iterator(minimum<Pair >(root));
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(maximum<Pair >(root));
		}
		reverse_iterator rend()
		{
			return reverse_iterator(Null);
		}
		iterator end()
		{
			return iterator(Null);
		}
		const_iterator begin() const
		{
			return const_iterator(minimum<Pair >(root));
		}

		const_iterator rbegin() const
		{
			return reverse_iterator(maximum<const Pair >(root));
		}
		const_iterator rend() const
		{
			return reverse_iterator(Null);
		}
		const_iterator end() const
		{
			return iterator(Null);
		}
		iterator lower_bound(T key) const
		{
			Node<Pair> *current = root;
			Node<Pair> *ret = Null;
			while (current != Null)
			{
				if (!comp(current->element, key))
				{
					ret = current;
					current = current->left;
				}
				else
				{
					current = current->right;
				}
			}
			return iterator(ret);
		}
		iterator upper_bound(T key) const
		{
			Node<Pair> *current = root;
			Node<Pair> *ret = Null;
			while (current != Null)
			{
				if (comp(key, current->element))
				{
					ret = current;
					current = current->left;
				}
				else
				{
					current = current->right;
				}
			}
			return iterator(ret);
		}
		ft::pair<iterator, iterator> equal_range(T key) const
		{
			iterator first = lower_bound(key);
			iterator last = upper_bound(key);
			return ft::pair<iterator, iterator>(first, last);
		}
		void deleteHelper(Node<Pair> *node, T key)
		{
			Node<Pair> *z = Null;
			Node<Pair> *y;
			Node<Pair> *x;
			while(node != Null)
			{
				if (!comp(key, node->element) && !comp(node->element, key))
				{
					z = node;
				}
				if(comp(key, node->element))
				{
					node = node->left;
				}
				else
				{
					node = node->right;
				}
				
			}
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
				y = minimum<Pair >(z->right);
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
			// delete z;
			elements--;
			if (y_original_color == 0)
			{
				deleteFix(x);
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
			Null->left = root;
			root->parent = Null;
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

		size_t deleteNode(T key)
		{
			size_t ret = elements;
			deleteHelper(root, key);
			if (ret != elements)
				return (1);
			else
				return (0);

		}
		
		void printHelper(Node<Pair> *root, std::string indent, bool last)
		{
			if (root != Null)
			{
				std::cout << indent;
				if (last)
				{
					std::cout << "\\-";
					indent += "  ";
				}
				else
				{
					std::cout << "|-";
					indent += "| ";
				}
				std::cout << root->element.first << " " << root->element.second << std::endl;
				printHelper(root->left, indent, false);
				printHelper(root->right, indent, true);
			}
		}
		void print()
		{
			if (root)
			{
				printHelper(this->root, "", true);
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
			allocator.destroy(node);
			allocator.deallocate(node, 1);
		}
		void clearTree()
		{
			clear(root);
			root = Null;
			elements = 0;
		}
		size_t size() const
		{
			return elements;
		}

		Node<Pair> *deepCopy(Node<Pair> *node, Node<Pair> *parent)
		{
			if (node && node->is_null)
				return Null;

			Node<Pair> *newNode = allocator.allocate(1);
			allocator.construct(newNode, node->element);
			if (node->parent == Null)
				newNode->parent = Null;
			else
				newNode->parent = parent;
			newNode->left = deepCopy(node->left, newNode);
			newNode->right = deepCopy(node->right, newNode);
			newNode->color = node->color;
			newNode->is_null = node->is_null;
			return newNode;
		}
		RBTree &operator=(const RBTree &other)
		{
			if (this != &other)
			{
				clearTree();
				root = deepCopy(other.root, Null);
				elements = other.elements;
			}
			return *this;
		}
		bool empty() const
		{
			return elements == 0;
		}

		size_t max_size() const
		{
			return allocator.max_size();
		}
		
};

template<class T, class Pair, typename Compare, typename alloc>
bool operator==(const RBTree<T, Pair, Compare, alloc> &lhs, const RBTree<T, Pair, Compare, alloc> &rhs)
{
	return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template<class T, class Pair, typename Compare, typename alloc>
bool operator!=(const RBTree<T, Pair, Compare, alloc> &lhs, const RBTree<T, Pair, Compare, alloc> &rhs)
{
	return !(lhs == rhs);
}

template<class T, class Pair, typename Compare, typename alloc>
bool operator<(const RBTree<T, Pair, Compare, alloc> &lhs, const RBTree<T, Pair, Compare, alloc> &rhs)
{

	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}
template<class T, class Pair, typename Compare, typename alloc>
bool operator>(const RBTree<T, Pair, Compare, alloc> &lhs, const RBTree<T, Pair, Compare, alloc> &rhs)
{
	return rhs < lhs;
}
template<class T, class Pair, typename Compare, typename alloc>
bool operator<=(const RBTree<T, Pair, Compare, alloc> &lhs, const RBTree<T, Pair, Compare, alloc> &rhs)
{
	return !(lhs > rhs);
}
template<class T, class Pair, typename Compare, typename alloc>
bool operator>=(const RBTree<T, Pair, Compare, alloc> &lhs, const RBTree<T, Pair, Compare, alloc> &rhs)
{
	return !(lhs < rhs);
}

}

