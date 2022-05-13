#pragma once
#include "tools.hpp"
#include "RBT.hpp"
#include "treeiterator.hpp"

namespace ft
{
	template <typename Key, typename Pair, typename Compare>
	class Comp_set
	{
	public:
		Compare cmp;
		Comp_set() : cmp(Compare()) {}
		Comp_set(Compare Cmp) : cmp(Cmp) {}

		
		bool operator()(const Key &a, const Key &b) const
		{
			return (cmp(a, b));
		}
	};
	template <class _Key, class _Compare = std::less<_Key>,
			  class _Alloc = std::allocator<_Key > >
	class set
	{
	public:
		typedef _Key key_type;
		typedef _Key value_type;
		typedef _Compare key_compare;
		typedef _Alloc allocator_type;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;

	private:
		typedef typename _Alloc::value_type                   			_Alloc_value_type;
		typedef RBTree<key_type, value_type, Comp_set<key_type, value_type, key_compare>, _Alloc> _Rep_type;
		key_compare _M_comp;
		allocator_type _M_alloc;
		_Rep_type _M_t;
	public:
	
		typedef typename _Rep_type::iterator iterator;
		typedef typename _Rep_type::const_iterator const_iterator;
		typedef typename _Rep_type::reverse_iterator reverse_iterator;
		typedef typename _Rep_type::const_reverse_iterator const_reverse_iterator;
		
		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class set<_Key, _Compare, _Alloc>;

			protected:
				_Compare comp;

				value_compare(_Compare __c)
					: comp(__c) {}

			public:
				bool operator()(const value_type &__x, const value_type &__y) const
				{
					return comp(__x, __y);
				}
		};
		key_compare key_comp() const
		{
			return _M_comp;
		}
		value_compare value_comp() const
		{
			return value_compare(_M_comp);
		}
		explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _M_t(comp, alloc) {
			(void)comp;
			(void)alloc;
		}
		set(const set& __x): _M_t(__x._M_t) { }
		template <class InputIterator>
  		set (InputIterator first, InputIterator last,const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type())
		{
			(void)comp;
			(void)alloc;
			while(first != last)
			{
				_M_t.insert(*first);
				++first;
			}
		}
		~set() {}
		iterator begin()
		{
			return _M_t.begin();
		}
		iterator end()
		{
			return _M_t.end();
		}
		const_iterator begin() const
		{
			return _M_t.begin();
		}
		const_iterator end() const
		{
			return _M_t.end();
		}
		reverse_iterator rbegin()
		{
			return _M_t.rbegin();
		}
		reverse_iterator rend()
		{
			return _M_t.rend();
		}

		const_reverse_iterator rbegin() const
		{
			return _M_t.rbegin();
		}
		const_reverse_iterator rend() const
		{
			return _M_t.rend();
		}

		bool empty() const
		{
			return _M_t.empty();
		}
		size_type size() const
		{
			return _M_t.size();
		}

		size_type max_size() const
		{
			return _M_t.max_size();
		}

		value_type& operator[] (const key_type& k)
		{
			(void)(*((this->insert(ft::make_pair(k,value_type()))).first));
			return _M_t.getNode(k)->element;
		}
		ft::pair<iterator,bool> insert (const value_type& val)
		{
				return _M_t.insert(val);
		}
		iterator insert (iterator position, const value_type& val)
		{
			(void)position;
			return _M_t.insert(val).first;
		}
		template <class InputIterator>
  		void insert (InputIterator first, InputIterator last)
		{
			while(first != last)
			{
				_M_t.insert(*first);
				++first;
			}
		}

		void erase (iterator position)
		{
			_M_t.deleteNode(*position);
		}
		size_type erase (const key_type& k)
		{
			return _M_t.deleteNode(k);
		}
		void erase (iterator first, iterator last)
		{
			while(first != last)
			{
				_M_t.deleteNode(*(first++));
			}
		}
		void swap (set& x)
		{
			_M_t.swap(x._M_t);
		}
		void clear()
		{
			_M_t.clearTree();
			
		}
		iterator find (const key_type& k)
		{
			return _M_t.getNode(k);
		}
		const_iterator find (const key_type& k) const
		{
			return _M_t.getNode(k);
		}
		size_type count (const key_type& k) const
		{
			return _M_t.getNode(k)->is_null != 1;
		}
		iterator lower_bound (const key_type& k) const
		{
			return _M_t.lower_bound(k);
		}
		iterator upper_bound (const key_type& k) const
		{
			return _M_t.upper_bound(k);
		}
		ft::pair<iterator,iterator> equal_range (const key_type& k) const
		{
			return _M_t.equal_range(k);
		}
		allocator_type get_allocator() const
		{
			return _M_t.get_allocator();
		}
		template< class K1,  class Compare1, class Alloc1 >
		friend bool operator==( const set<K1,Compare1,Alloc1>& lhs, const set<K1,Compare1,Alloc1>& rhs );
		template< class K1,  class Compare1, class Alloc1 >
		friend bool operator<( const set<K1,Compare1,Alloc1>& lhs, const set<K1,Compare1,Alloc1>& rhs );
	};
	template< class Key,  class Compare, class Alloc >
	bool operator==( const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs )
	{
		return lhs._M_t == rhs._M_t;
	}

	template< class Key,  class Compare, class Alloc >
	bool operator!=( const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs )
	{
		return !(lhs == rhs);
	}

	template< class Key, class Compare, class Alloc >
	bool operator<( const set<Key,Compare,Alloc>& lhs,const set<Key,Compare,Alloc>& rhs )
	{
		return lhs._M_t < rhs._M_t;
	}
	template< class Key, class Compare, class Alloc >
	bool operator<=( const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs )
	{
		return lhs < rhs || lhs == rhs;
	}
	template< class Key, class Compare, class Alloc >
	bool operator>( const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs )
	{
		return !(lhs <= rhs);
	}
	template< class Key, class Compare, class Alloc >
	bool operator>=( const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs )
	{
		return !(lhs < rhs);
	}

}

