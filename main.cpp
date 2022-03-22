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
    ft::vector<int> myvector(2);

  myvector[0] = 78;
  myvector[1] = 16;

  // now front equals 78, and back 16

  myvector.front() -= myvector.back();

  std::cout << "myvector.front() is now " << myvector.front() << '\n';

  return 0;
}