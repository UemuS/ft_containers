#pragma once
#include<iostream>
#include <iterator>
#include <cstddef>
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
		typedef iterator<std::random_access_iterator_tag, T> 	myIt;
		typedef typename myIt::value_type						value_type;
		typedef typename myIt::difference_type					difference_type;
		typedef typename myIt::pointer							pointer;
		typedef typename myIt::reference						reference;
		
		
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
}

