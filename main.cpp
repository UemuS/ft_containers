#include "vector.hpp"

template<typename T>
void    printvec(ft::vector<T> &a)
{
    std::cout << "size : " << a.size()<< '\n';
    for(size_t i = 0; i < a.size(); i++)
        std::cout << "| " << a[i] << " |";
    std::cout << "\n\n";
}

int main()
{
  ft::vector<int> a(5,9);
  ft::vector<int> b(9,15);
  a.swap(b);
  std::cout << a.size() << " " << a.capacity() << '\n';
  std::cout << b.size() << " " << b.capacity() << '\n';
  printvec(a);
  printvec(b);
  return 0;
}