#pragma 1

#include <iostream>
#include <vector>

namespace ft
{
    template <typename _T, typename _Alloc = std::allocator<_T> >
    class vector
    {
        

        
        public:
			typedef size_t                  size_type;
			typedef _T                      value_type;
			typedef _Alloc                  allocator_type;
			typedef _T&                     reference;
			typedef _T*                     pointer;
			typedef const _T&				const_reference;
			typedef const _T*               const_pointer;
            explicit	vector(const allocator_type& alloc = allocator_type()) : myAllocator(alloc)
            {
                _begin = NULL;
                _end = NULL;
                _endOfCapacity = NULL;
            }

            vector(size_type size, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):  myAllocator(alloc)
            {
				if (max_size() < size)
					this->__throw_length_error();
                _begin = myAllocator.allocate(size);
                _end = _begin + size;
                _endOfCapacity = _begin + size;
                pointer it = _begin;
                while (it < _end)
                {
                    myAllocator.construct(it, val);
                    it++;
                }
            }
            vector(vector const &a) : myAllocator(a.myAllocator)
            {
                _begin = myAllocator.allocate(a.size());
                _end = _begin + a.size();
                _endOfCapacity = _end;
                _T *cpT = a._begin;
                _T *it = this->_begin;
                while (cpT < a._end)
                {
                    myAllocator.construct(it, *cpT);
                    it++;
                    cpT++;
                }
            }
            ~vector()
            {
                if (_endOfCapacity != _begin)
                {
					pointer it = _begin;
                    while(it < _end)
                    {
                        myAllocator.destroy(it);
						it++;
                    }
                    myAllocator.deallocate(_begin, capacity());
                }
            }
            
            vector 		&operator=(vector const &cp)
            {
                if (this != &cp)
				{
                    destruct_at_end(_begin);
					if (capacity())
						myAllocator.deallocate(_begin, capacity());
                    _begin = myAllocator.allocate(cp.size());
                    _end = _begin + cp.size();
                    _endOfCapacity = _end;
                    pointer cpT = cp._begin;
                    pointer it = this->_begin;
					pointer cpE = cp._end;
                    while (cpT < cpE)
                    {
                        myAllocator.construct(it, *cpT);
                        it++;
                        cpT++;
                    }
                }
                return *this;
            }

			// ************* CAPACITY ****************//

            size_type 	size() const { return( _end - _begin); }
			size_type	max_size() const {	return myAllocator.max_size(); }
			size_type 	capacity() const {return _endOfCapacity - _begin;}
			bool 		empty() const{return (size() == 0);}

			void reserve (size_type n)
			{
				if (n <= capacity())
					return ;
				if (n > max_size())
					this->__throw_length_error();
				vector<_T>	cp(*this);
				destruct_at_end(_begin);
				myAllocator.deallocate(_begin, capacity());
				_begin = myAllocator.allocate(n);
				pointer it = _begin;
				pointer	cit = cp._begin;
				while(cit < cp._end)
				{
					myAllocator.construct(it, *cit);
					it++;
					cit++;
				}
				_endOfCapacity = _begin + n;
				_end = it;
			}

			void resize (size_type n, value_type val = value_type())
			{
				size_type oldsize = size();
				if (n <= capacity())
				{
					pointer it = this->_begin + n;
					if (n < oldsize)
						destruct_at_end(it);
					else if (n > oldsize)
						construct_at_end(n - oldsize);
				}
				else
				{
					vector<_T>	cp(*this);
					destruct_at_end(_begin);
					myAllocator.deallocate(_begin, capacity());
					size_type rec = recommend(n);
					_begin = myAllocator.allocate(rec);
					pointer it = _begin;
					pointer	cit = cp._begin;
					while(cit < cp._end)
					{
						myAllocator.construct(it, *cit);
						it++;
						cit++;
					}
					_end = it;
					construct_at_end(n - oldsize, val);
					_endOfCapacity = _begin + rec;
				}
			}

			// **********TOOLS********** //

			size_type	recommend(size_type __new_size) const
			{
				const size_type __ms = max_size();
				if (__new_size > __ms)
					this->__throw_length_error();
				const size_type __cap = capacity();
				if (__cap >= __ms / 2)
					return __ms;
				return _VSTD::max<size_type>(2*__cap, __new_size);
			}

			void destruct_at_end(pointer __new_last)
			{
				pointer __soon_to_be_end = _end;
				while (__new_last != __soon_to_be_end)
					myAllocator.destroy(--__soon_to_be_end);
				_end = __new_last;
			}

			void construct_at_end(size_type __n)
			{
				allocator_type& __a = this->myAllocator;
				do
				{
					__a.construct(_end);
					++this->_end;
					--__n;
				} while (__n > 0);
			}

			void construct_at_end(size_type __n, const_reference __x)
			{
				allocator_type& __a = this->myAllocator;
				do
				{
					__a.construct(_end, __x);
					++this->_end;
					--__n;
				} while (__n > 0);
			}

			std::allocator<_T> getAllocator() const
            {
                return (this->myAllocator);
            }

			//  ELEMENT ACCESS //


			reference at (size_type n)
			{
				std::cout << n << " " << size() << '\n';
				if (n >= size())
					 __throw_out_of_range();
				return *(_begin + n);
			}

			const_reference at (size_type n) const
			{
				if (n >= size())
					__throw_out_of_range();
				return *(_begin + n);
			}

			reference operator[](size_type n)
            {
                return *(_begin + n);
            }

			const_reference operator[](size_type n) const
            {
                return (*(_begin + n));
            }

			reference front()
			{
				return (*_begin);
			}
			const_reference front() const
			{
				return (*_begin);
			}
			reference back()
			{
				return (*(_end - 1));
			}
			const_reference back() const
			{
				return (*(_end - 1));	
			}


			// MODIFIERS //
			void assign (size_type n, const value_type& val)
			{
				if (n < capacity())
				{
					destruct_at_end(_begin);
					construct_at_end(n, val);
				}
				else
				{
					destruct_at_end(_begin);
					if(capacity())
						myAllocator.deallocate(_begin, capacity());
					_begin = myAllocator.allocate(n);
					_endOfCapacity = _begin + n;
					_end = _begin;
					construct_at_end(n, val);
				}
			}

			// EXCEPTIONS //
			void	__throw_out_of_range() const
			{
				std::__throw_out_of_range("vector");
			}
			void	__throw_length_error() const
			{
				std::__throw_length_error("vector");
			}
            
            allocator_type              myAllocator;
            value_type                  *_begin;
            value_type                  *_end;
            value_type                  *_endOfCapacity;
        


    };
}

// template< typename _T >
// std::ostream & operator<<(std::ostream & o, ft::vector<_T> const & ref)
// {
// 		o << (ref.getT())[i];
// 	return (o);
// }
