#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <iostream>
#include <vector>

namespace ft
{
    // template <typename _T, typename _Alloc = std::allocator<_T> >
    // class vector_case
    // {

    // };

    template <typename _T, typename _Alloc = std::allocator<_T> >
    class vector
    {
    private:
        typedef _T value_type;
        std::allocator<_T> myAllocator;
        _T *_elements;
        unsigned int _size;
        unsigned int _capacity;
        _T *_begin;
        _T *_end;
        _T *_endOfCapacity;
        typedef _Alloc allocator_type;

    public:
        vector() : _size(0), _capacity(0)
        {
            _begin = NULL;
            _end = NULL;
            _endOfCapacity = NULL;
            _elements = NULL;
        }
        vector(unsigned int size) : _size(size), _capacity(size)
        {

            _elements = myAllocator.allocate(_size);
            _begin = _elements;
            _end = _elements + _size;
            _endOfCapacity = _elements + _capacity;
            _T *it = _begin;
            while (it < _end)
            {
                myAllocator.construct(it, _T());
                it++;
            }
        }
        vector(vector const &a) : _capacity(0)
        {
            std::cout << "Copy called\n";
            *this = a;
        }
        vector(unsigned int size, _T initialValue) : _size(size), _capacity(size)
        {

            _elements = myAllocator.allocate(_size);
            _begin = _elements;
            _end = _elements + _size;
            _endOfCapacity = _elements + _capacity;
            _T *it = _begin;
            while (it < _end)
            {
                myAllocator.construct(it, initialValue);
                it++;
            }
        }
        class OutOfRange : public std::exception
        {
            virtual const char *what() const throw()
            {
                return ("OutOfRange.");
            }
        };
        _T &operator[](int i)
        {
            if (i < 0 || i >= static_cast<int>(this->_size))
            {
                throw(OutOfRange());
            }
            else
                return (*(_elements + i));
        }
        ~vector()
        {
            if (_capacity)
            {
                for (int i = 0; i < _size; i++)
                {
                    myAllocator.destroy(&_elements[i]);
                }
                myAllocator.deallocate(_elements, _size);
            }
        }
        _T *begin() const { return (_begin); }
        _T *end() const { return (_end); }
        unsigned int size() const { return (this->_size); }
        _T *getT(void) const { return _elements; }
        vector &operator=(vector const &cp)
        {
            if (this->_capacity)
            {
                for (int i = 0; i < _size; i++)
                {
                    myAllocator.destroy(_elements + i);
                }
                myAllocator.deallocate(_elements, _size);
            }
            this->_size = cp.size();
            this->_capacity = cp._capacity;
            _elements = myAllocator.allocate(cp._size);
            _begin = _elements;
            _end = _elements + _size;
            _endOfCapacity = _elements + _capacity;
            _T *cpT = cp.begin();
            _T *it = this->begin();
            while (cpT < cp.end())
            {
                myAllocator.construct(it, *cpT);
                it++;
                cpT++;
            }
            return *this;
        }
    };
}

// template< typename _T >
// std::ostream & operator<<(std::ostream & o, ft::vector<_T> const & ref)
// {
// 		o << (ref.getT())[i];
// 	return (o);
// }

#endif