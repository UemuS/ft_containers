#pragma once
#include "tools.hpp"
#include "RBT.hpp"

namespace ft
{
	template <typename Key, typename Pair, typename Compare>
	class Comp_map
	{
	public:
		Compare cmp;
		Comp_map() : cmp(Compare()) {}
		Comp_map(Compare Cmp) : cmp(Cmp) {}

		bool operator()(const Pair &a, const Pair &b)
		{
			return (cmp(a.first, b.first));
		}
		bool operator()(const Key &a, const Key &b)
		{
			return (cmp(a, b));
		}
		bool operator()(const Key &a, const Pair &b)
		{
			return (cmp(a, b.first));
		}
		bool operator()(const Pair &a, const Key &b)
		{
			return (cmp(a.first, b));
		}
	};
	template <class _Key, class _Tp, class _Compare = std::less<_Key>,
			  class _Alloc = std::allocator<ft::pair<const _Key, _Tp> > >
	class map
	{
	public:
		typedef _Key key_type;
		typedef _Tp mapped_type;
		typedef pair<const key_type, mapped_type> value_type;
		typedef _Compare key_compare;
		typedef _Alloc allocator_type;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class map<_Key, _Tp, _Compare, _Alloc>;

			protected:
				_Compare comp;

				value_compare(_Compare __c)
					: comp(__c) {}

			public:
				bool operator()(const value_type &__x, const value_type &__y) const
				{
					return comp(__x.first, __y.first);
				}
		};
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _M_t(comp, alloc) {}
		map(const map& __x): _M_t(__x._M_t) { }
		


	private:
		 typedef typename _Alloc::template rebind<value_type>::other 	_Pair_alloc_type;
		 typedef typename _Alloc::value_type                   			_Alloc_value_type;
		 typedef RBTree<key_type, value_type, Comp_map<key_type, mapped_type, key_compare>, _Pair_alloc_type> _Rep_type;
		 _Rep_type _M_t;
		 key_compare _M_comp;
		 allocator_type _M_alloc;

	};

}