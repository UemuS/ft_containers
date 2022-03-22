#include "vector.hpp"

template<typename T>
void    printvec(ft::Vector<T> &a)
{
    std::cout << "size : " << a.size()<< '\n';
    for(size_t i = 0; i < a.size(); i++)
        std::cout << "| " << a[i] << " |";
    std::cout << "\n\n";
}

int main()
{
    ft::Vector<int> a(5, 8);
    std::cout << a.capacity() << " " << a.size() << '\n';
    printvec(a);
    a.reserve(15);
    std::cout << a.capacity() << " " << a.size() << '\n';
    printvec(a);
    //system("leaks a.out");
    // std::Vector<int> a(5);
    // a.resize(9);
    // std::Vector<int> b(4);
    // b = a;
    // std::cout << a.capacity() << " " << b.capacity() << '\n';
}