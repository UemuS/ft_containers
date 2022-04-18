#pragma once
#include "tools.hpp"
#include "RBT.hpp"

namespace ft
{
	template <class _Key, class _Tp, class _Compare = std::less<_Key>,
          class _Allocator = std::allocator<ft::pair<const _Key, _Tp> > >
	class  map
	{
	public:
		typedef _Key                                     key_type;
		typedef _Tp                                      mapped_type;
		typedef pair<const key_type, mapped_type>        value_type;
		typedef _Compare                                 key_compare;
		typedef _Allocator                               allocator_type;
		typedef value_type&                              reference;
		typedef const value_type&                        const_reference;
		
		private:
			RBTree<key_type, value_type, key_compare> *_RBTree;
			key_compare comp;
			allocator_type alloc;
			Node<value_type> *root;
			int elements;
	};
	

}