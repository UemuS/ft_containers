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
	class random_access_it
	{
	public:
		typedef iterator_traits<iterator<std::random_access_iterator_tag, T> > myIt;
		typedef typename myIt::value_type value_type;
		typedef typename myIt::difference_type difference_type;
		typedef typename myIt::pointer pointer;
		typedef typename myIt::reference reference;
		typedef typename myIt::iterator_category iterator_category;

		random_access_it() : _it(NULL) {}
		random_access_it(pointer ptr) : _it(ptr) {}
		random_access_it &operator++()
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
		random_access_it &operator--()
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
		random_access_it operator+=(difference_type n)
		{
			_it += n;
			return *this;
		}
		random_access_it operator-=(difference_type n)
		{
			_it -= n;
			return *this;
		}
		bool operator<(random_access_it const &cit) const
		{
			return (_it < cit._it);
		}
		bool operator>(random_access_it const &cit) const
		{
			return (_it > cit._it);
		}
		bool operator==(random_access_it const &cit) const
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
		value_type &operator[](difference_type i) const
		{
			return *(_it + i);
		}
		reference operator*() const
		{
			return *(_it);
		}

		pointer operator->() const
		{
			return &(operator*());
		}
		pointer base() const
		{
			return _it;
		}

		~random_access_it()
		{
		}

	private:
		pointer _it;
	};
	template <typename T>
	class const_random_access_it
	{
	public:
		typedef iterator_traits<iterator<std::random_access_iterator_tag, const T> > myIt;
		typedef typename myIt::value_type value_type;
		typedef typename myIt::difference_type difference_type;
		typedef typename myIt::pointer pointer;
		typedef typename myIt::reference reference;
		typedef typename myIt::iterator_category iterator_category;

		const_random_access_it() : _it(NULL) {}
		const_random_access_it(pointer ptr) : _it(ptr) {}
		const_random_access_it(random_access_it<T> const &it) : _it(it.base()) {}
		const_random_access_it &operator++()
		{
			++_it;
			return *this;
		}
		const_random_access_it operator++(int)
		{
			const_random_access_it tmp = _it;
			++_it;
			return tmp;
		}
		const_random_access_it &operator--()
		{
			--_it;
			return *this;
		}
		const_random_access_it operator--(int)
		{
			const_random_access_it tmp = _it;
			--_it;
			return tmp;
		}
		const_random_access_it operator+(difference_type n) const
		{
			return const_random_access_it(_it + n);
		}
		const_random_access_it operator-(difference_type n) const
		{
			return const_random_access_it(_it - n);
		}
		const_random_access_it operator+=(difference_type n)
		{
			_it += n;
			return *this;
		}
		const_random_access_it operator-=(difference_type n)
		{
			_it -= n;
			return *this;
		}
		difference_type operator-(const_random_access_it const &cit) const
		{
			return (_it - cit._it);
		}
		bool operator<(const_random_access_it const &cit) const
		{
			return (_it < cit._it);
		}
		bool operator>(const_random_access_it const &cit) const
		{
			return (_it > cit._it);
		}
		bool operator==(const_random_access_it const &cit) const
		{
			return (_it == cit._it);
		}
		bool operator!=(const_random_access_it const &cit) const
		{
			return (_it != cit._it);
		}
		bool operator>=(const_random_access_it const &cit) const
		{
			return (_it >= cit._it);
		}
		bool operator<=(const_random_access_it const &cit) const
		{
			return (_it <= cit._it);
		}
		value_type &operator[](difference_type i) const
		{
			return *(_it + i);
		}
		reference operator*() const
		{
			return *(_it);
		}
		pointer operator->() const
		{
			return &(operator*());
		}
		pointer base() const
		{
			return _it;
		}
		~const_random_access_it()
		{
		}

	private:
		pointer _it;
	};
	template <class Iter>
	class reverse_iterator
	{
	public:
		typedef Iter iterator_type;
		typedef typename iterator_traits<Iter>::iterator_category iterator_category;
		typedef typename iterator_traits<Iter>::value_type value_type;
		typedef typename iterator_traits<Iter>::difference_type difference_type;
		typedef typename iterator_traits<Iter>::pointer pointer;
		typedef typename iterator_traits<Iter>::reference reference;

		reverse_iterator() : _it(NULL) {}
		reverse_iterator(iterator_type it) : _it(it) {}
		template <class iter>
		reverse_iterator(const reverse_iterator<iter> &rev_it) : _it(rev_it.base()) {}
		iterator_type base() const
		{
			return _it;
		}
		reverse_iterator<iterator_type> &operator++()
		{
			--_it;
			return *this;
		}
		reverse_iterator<iterator_type> operator++(int)
		{
			reverse_iterator<iterator_type> tmp = _it;
			--_it;
			return tmp;
		}
		reverse_iterator<iterator_type> &operator--()
		{
			++_it;
			return *this;
		}
		reverse_iterator<iterator_type> operator--(int)
		{
			reverse_iterator<iterator_type> tmp = _it;
			++_it;
			return tmp;
		}
		reverse_iterator<iterator_type> operator+(difference_type n) const
		{
			return reverse_iterator<iterator_type>(_it - n);
		}
		reverse_iterator<iterator_type> operator-(difference_type n) const
		{
			return reverse_iterator<iterator_type>(_it + n);
		}
		reverse_iterator<iterator_type> &operator+=(difference_type n)
		{
			_it -= n;
			return *this;
		}
		reverse_iterator<iterator_type> &operator-=(difference_type n)
		{
			_it += n;
			return *this;
		}
		pointer operator->() const
		{
			return &(operator*());
		}
		reference operator*() const
		{
			return *(_it - 1);
		}
		reference operator[](difference_type n) const
		{
			return base()[-n - 1];
		}
		~reverse_iterator() {}

	private:
		iterator_type _it;
	};
	template <typename T>
	random_access_it<T> operator+(std::ptrdiff_t n, random_access_it<T> const &it)
	{
		return it + n;
	}
	template <typename T>
	const_random_access_it<T> operator+(std::ptrdiff_t n, const_random_access_it<T> const &it)
	{
		return it + n;
	}
	template <typename T>
	std::ptrdiff_t operator-(random_access_it<T> const &cit, const_random_access_it<T> const &it)
	{
		return cit.base() - it.base();
	}
	template <typename T>
	bool operator==(random_access_it<T> const &it, const_random_access_it<T> const &cit)
	{
		return it.base() == cit.base();
	}
	template <typename T>
	bool operator!=(random_access_it<T> const &it, const_random_access_it<T> const &cit)
	{
		return it.base() != cit.base();
	}
	template <typename T>
	bool operator<(random_access_it<T> const &it, const_random_access_it<T> const &cit)
	{
		return it.base() < cit.base();
	}
	template <typename T>
	bool operator>(random_access_it<T> const &it, const_random_access_it<T> const &cit)
	{
		return it.base() > cit.base();
	}
	template <typename T>
	bool operator<=(random_access_it<T> const &it, const_random_access_it<T> const &cit)
	{
		return it.base() <= cit.base();
	}
	template <typename T>
	bool operator>=(random_access_it<T> const &it, const_random_access_it<T> const &cit)
	{
		return it.base() >= cit.base();
	}
	template <typename Iterator>
	bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template <typename Iterator, typename It2>
	bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<It2> &rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return !(lhs == rhs);
	}
	template <class Iterator, class It2>
	bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<It2> &rhs)
	{
		return !(lhs == rhs);
	}
	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return (rhs.base() < lhs.base());
	}
	template <class Iterator, class It2>
	bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<It2> &rhs)
	{
		return (rhs.base() < lhs.base());
	}
	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return (rhs.base() <= lhs.base());
	}
	template <class Iterator, class It2>
	bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<It2> &rhs)
	{
		return (rhs.base() <= lhs.base());
	}
	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return (rhs < lhs);
	}
	template <class Iterator, class It2>
	bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<It2> &rhs)
	{
		return (rhs < lhs);
	}
	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return (rhs <= lhs);
	}
	template <class Iterator, class It2>
	bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<It2> &rhs)
	{
		return (rhs <= lhs);
	}
	template <class Iterator>
  	typename reverse_iterator<Iterator>::difference_type operator- ( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return rhs.base() - lhs.base();
	}
	template <class Iterator, class It2>
	typename reverse_iterator<Iterator>::difference_type operator- ( const reverse_iterator<Iterator>& lhs, const reverse_iterator<It2>& rhs)
	{
		return rhs.base() - lhs.base();
	}
	template <class Iterator>
  	reverse_iterator<Iterator> operator+ ( typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	{
		return reverse_iterator<Iterator>(rev_it.base() - n);
	}

}
