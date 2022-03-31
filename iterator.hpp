#pragma once
#include<iostream>
#include <iterator>
#include <cstddef>
#include "iterator_traits.hpp"
namespace ft
{
	template<class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&> 
	struct iterator
	{
		typedef T         					value_type;
		typedef Distance  					difference_type;
		typedef Pointer   					pointer;
		typedef Reference 					reference;
		typedef Category  					iterator_category;
	};
	template<typename T>
	class random_access_it
	{
	public:
		typedef iterator_traits<iterator<std::random_access_iterator_tag, T> > 	myIt;
		typedef typename myIt::value_type										value_type;
		typedef typename myIt::difference_type									difference_type;
		typedef typename myIt::pointer											pointer;
		typedef typename myIt::reference										reference;
		typedef typename myIt::iterator_category								iterator_category;
		
		
		random_access_it():_it(NULL){}
		random_access_it(pointer ptr):_it(ptr){}
		random_access_it	&operator++()
		{
			++_it;
			return *this;
		}
		random_access_it operator++(int)
		{
			random_access_it tmp = _it;
			++_it;
			return tmp;
		}
		random_access_it	&operator--()
		{
			--_it;
			return *this;
		}
		random_access_it operator--(int)
		{
			random_access_it tmp = _it;
			--_it;
			return tmp;
		}
		random_access_it operator+(difference_type n) const
		{
			return random_access_it(_it + n);
		}
		random_access_it operator-(difference_type n) const
		{
			return random_access_it(_it - n);
		}

		difference_type operator-(random_access_it const &cit)
		{
			return (_it - cit._it);
		}
		bool	operator<(random_access_it const &cit) const
		{
			return (_it < cit._it);
		}
		bool operator>(random_access_it const &cit) const
		{
			return (_it > cit._it);
		}
		bool	operator==(random_access_it const &cit) const
		{
			return (_it == cit._it);
		}
		bool operator!=(random_access_it const &cit) const
		{
			return (_it != cit._it);
		}
		bool operator>=(random_access_it const &cit) const
		{
			return (_it >= cit._it);
		}
		bool operator<=(random_access_it const &cit) const
		{
			return (_it <= cit._it);
		}
		value_type	operator[](difference_type i) const
		{
			return *(_it + i);
		}
		reference operator*() const
		{
			return *(_it);
		}
		
		pointer operator->() const
		{
			return (_it);
		}
		pointer base() const
		{
			return _it;
		}
		~random_access_it()
		{
			_it = NULL;
		}
	private:
		pointer	_it;
	};
	template <class Iter>
	class reverse_iterator
	{
		public:
			typedef Iter										iterator_type;
			typedef typename iterator_traits<Iter>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iter>::value_type			value_type;
			typedef typename iterator_traits<Iter>::difference_type		difference_type;
			typedef typename iterator_traits<Iter>::pointer				pointer;
			typedef typename iterator_traits<Iter>::reference			reference;

			reverse_iterator() : _it(NULL) {}
			explicit reverse_iterator(iterator_type it) : _it(it) {}
			template <class iter>
  			reverse_iterator (const reverse_iterator<iter>& rev_it) : _it(rev_it.base()) {}
			iterator_type base() const { return _it; }
			reference operator*() const { return *(_it - 1); }
			pointer operator->() const { return (_it - 1); }
			reverse_iterator& operator++() { --_it; return *this; }
			reverse_iterator operator++(int) { reverse_iterator tmp = *this; --_it; return tmp; }
			reverse_iterator& operator--() { ++_it; return *this; }
			reverse_iterator operator--(int) { reverse_iterator tmp = *this; ++_it; return tmp; }
			reverse_iterator operator+(difference_type n) const { return reverse_iterator(_it - n); }
			reverse_iterator operator-(difference_type n) const { return reverse_iterator(_it + n); }
			reverse_iterator& operator+=(difference_type n) { _it -= n; return *this; }
			reverse_iterator& operator-=(difference_type n) { _it += n; return *this; }
			reference operator[](difference_type n) const { return *(_it - 1 - n); }
			bool operator<(const reverse_iterator& it) const { return _it > it._it; }
			bool operator>(const reverse_iterator& it) const { return _it < it._it; }
			bool operator==(const reverse_iterator& it) const { return _it == it._it; }
			bool operator!=(const reverse_iterator& it) const { return _it != it._it; }
			bool operator<=(const reverse_iterator& it) const { return _it >= it._it; }
			bool operator>=(const reverse_iterator& it) const { return _it <= it._it; }
			~reverse_iterator() {}
		private:
			iterator_type _it;
	};
}
