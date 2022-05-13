#pragma once
#include <iostream>
#include <iterator>
#include <cstddef>
#include "iterator_traits.hpp"
#include "tools.hpp"
#include "RBT.hpp"


namespace ft
{
	template<typename T>
struct Node;
template <typename T>
	struct const_bin_iterator;

	template <typename T>
	struct bin_iterator
	{
		public:
			typedef Node<T> node_type;
			typedef node_type* node_pointer;
			typedef T value_type;
			typedef T* pointer;
			typedef T& reference;
			typedef ptrdiff_t difference_type;
			typedef std::bidirectional_iterator_tag iterator_category;

			



			bin_iterator() : _it(NULL) {}
			bin_iterator(Node<T> *ptr) : _it(ptr) {}
			bin_iterator(const bin_iterator &it) : _it(it._it) {}
			
			bin_iterator &operator++()
			{
				_it = succesor(_it);
				return *this;
			}
			bin_iterator &operator--()
			{
				_it = predecessor(_it);
				return *this;
			}
			bin_iterator operator++(int)
			{
				bin_iterator tmp = *this;
				_it = succesor(_it);
				return tmp;
			}
			bin_iterator operator--(int)
			{
				bin_iterator tmp = *this;
				_it = predecessor(_it);
				return tmp;
			}
			reference operator*() const
			{
				return (_it->element);
			}
			pointer operator->() const
			{
				return &(operator*());
			}
			bool operator==(const bin_iterator &other) const
			{
				return _it == other._it;
			}
			bool operator!=(const bin_iterator &other) const
			{
				return _it != other._it;
			}
			node_pointer base() const
			{
				return _it;
			}
			~bin_iterator() {}
			
		private:
			node_pointer _it;
	};

	template <typename T>
	struct const_bin_iterator
	{
		public:
			typedef Node<T> node_type;
			typedef node_type* node_pointer;

			typedef const T value_type;
			typedef const T* pointer;
			typedef const T& reference;
			typedef ptrdiff_t difference_type;
			typedef std::bidirectional_iterator_tag iterator_category;



			const_bin_iterator() : _it(NULL) {}
			const_bin_iterator(node_pointer ptr) : _it(ptr) {}
			const_bin_iterator(const const_bin_iterator &it) : _it(it._it) {}
			const_bin_iterator(const bin_iterator<T> &it) : _it(it.base()) {}
			
			
			const_bin_iterator &operator++()
			{
				_it = succesor(_it);
				return *this;
			}
			const_bin_iterator &operator--()
			{
				_it = predecessor(_it);
				return *this;
			}
			const_bin_iterator operator++(int)
			{
				const_bin_iterator tmp = *this;
				_it = succesor(_it);
				return tmp;
			}
			const_bin_iterator operator--(int)
			{
				const_bin_iterator tmp = *this;
				_it = predecessor(_it);
				return tmp;
			}
			reference operator*() const
			{
				return (_it->element);
			}
			pointer operator->() const
			{
				return &(_it->element);
			}
			bool operator==(const const_bin_iterator &other) const
			{
				return _it == other._it;
			}
			bool operator!=(const const_bin_iterator &other) const
			{
				return _it != other._it;
			}
			node_pointer base() const
			{
				return _it;
			}
			~const_bin_iterator() {}
			
		private:
			node_pointer _it;
	};
}