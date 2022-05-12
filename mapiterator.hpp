#pragma once
#include <iostream>
#include <iterator>
#include <cstddef>
#include "iterator_traits.hpp"

namespace ft
{
	template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T *, class Reference = T &>
	struct iterator
	{
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;
	};
	template <typename T>
	struct bin_iterator
	{
		public:
			typedef iterator_traits<iterator<std::bidirectional_iterator_tag, T> > myIt;
			typedef typename myIt::pointer pointer;
			typedef typename myIt::reference reference;
			typedef typename myIt::iterator_category iterator_category;
			typedef typename myIt::value_type value_type;
			typedef typename myIt::difference_type difference_type;

			bin_iterator() : _it(NULL) {}
			random_access_it(pointer ptr) : _it(ptr) {}
			bin_iterator 
		private:
			pointer _it;
	};
}