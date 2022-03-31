#include "vector.hpp"
#include "tools.hpp"
#include <typeinfo> 

template<typename T>
void    printvec(ft::vector<T> &a)
{
    std::cout << "ft size : " << a.size() << " capacity : " << a.capacity()<< '\n';
    for(size_t i = 0; i < a.size(); i++)
        std::cout << "| " << a[i] << " |";
    std::cout << "\n\n";
}

template<typename T>
void    printvec(std::vector<T> &a)
{
    std::cout << "std size : " << a.size() << " capacity : " << a.capacity()<< '\n';
    for(size_t i = 0; i < a.size(); i++)
        std::cout << "| " << a[i] << " |";
    std::cout << "\n\n";
}

void do_stuff(int t)
{
  std::cout << "integral  " << &t << '\n';
}

template<class T>
void do_stuff(T t, typename ft::enable_if<!ft::is_integral<T>::value>::type* = 0)
{
  std::cout << "not integral  " << &t << '\n';
}



class a
{
public:
    a(int i) : i(i) {}
    int i;
};

int main () {
  ft::vector<int> a;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  a.push_back(4);
  a.push_back(5);
  std::cout << *(a.rend() - 1) << '\n';
}