#pragma once
#include <iostream>
#include "iterator_traits.hpp"
namespace ft
{
	template <class T, T v>
	struct integral_constant
	{
		static const T value = v;
		typedef T value_type;
		typedef integral_constant type;
	};

	template <typename T>
	struct is_integral : integral_constant<bool, false>
	{
	};

	template <>
	struct is_integral<bool> : integral_constant<bool, true>
	{
	};

	template <>
	struct is_integral<char> : integral_constant<bool, true>
	{
	};

	template <>
	struct is_integral<char16_t> : integral_constant<bool, true>
	{
	};

	template <>
	struct is_integral<char32_t> : integral_constant<bool, true>
	{
	};

	template <>
	struct is_integral<wchar_t> : integral_constant<bool, true>
	{
	};

	template <>
	struct is_integral<short> : integral_constant<bool, true>
	{
	};

	template <>
	struct is_integral<int> : integral_constant<bool, true>
	{
	};

	template <>
	struct is_integral<long> : integral_constant<bool, true>
	{
	};

	template <>
	struct is_integral<long long> : integral_constant<bool, true>
	{
	};

	template <bool, typename T = void>
	struct enable_if
	{
	};

	template <typename T>
	struct enable_if<true, T>
	{
		typedef T type;
	};
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1 && first2 != last2)
			if (*first1 < *first2)
				return true;
			else if (*first2 < *first1)
				return false;
			else
				++first1, ++first2;
		return first1 == last1 && first2 != last2;
	}
	template <class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
	{
		while (first1 != last1)
			if (*first1 != *first2)
				return false;
			else
				++first1, ++first2;
		return true;
	}
	template <class InputIt1,
			  class InputIt2,
			  class BinaryPredicate>
	bool equal(InputIt1 first1,
			   InputIt1 last1, InputIt2 first2, BinaryPredicate p)
	{
		while (first1 != last1)
			if (!p(*first1, *first2))
				return false;
			else
				++first1, ++first2;
		return true;
	}
	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1 != last1 && first2 != last2)
			if (comp(*first1, *first2))
				return true;
			else if (comp(*first2, *first1))
				return false;
			else
				++first1, ++first2;
		return first1 == last1 && first2 != last2;
	}
	template <typename T, typename B>
	class pair
	{
	public:
		T first;
		B second;
		pair() : first(T()), second(B())
		{
		}
		template <class U, class V>
		pair(const pair<U, V> &pr) : first(pr.first), second(pr.second)
		{
		}
		pair(const T &a, const B &b): first(a), second(b)
		{
		}
		pair &operator=(const pair &pr)
		{
			first = pr.first;
			second = pr.second;
			return *this;
		}
	};

	// PAIR NON MEMBER FUNCTIONS //
	template <class T1, class T2>
	bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return rhs < lhs;
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(lhs < rhs);
	}
	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}
}