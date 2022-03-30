#include "vector.hpp"
#include "tools.hpp"

template<typename T>
void    printvec(std::vector<T> &a)
{
    std::cout << "size : " << a.size() << " capacity : " << a.capacity()<< '\n';
    for(size_t i = 0; i < a.size(); i++)
        std::cout << "| " << a[i] << " |";
    std::cout << "\n\n";
}

void do_stuff(int t, std::string b)
{
  (void)b;
  std::cout << "integral  " << &t << '\n';
}

template<class T>
void do_stuff(T t, B b, typename ft::enable_if<!ft::is_integral<T>::value>::type* = 0)
{
  std::cout << "not integral  " << &t << '\n';
}



class a
{
public:
    a(int i) : i(i) {}
    int i;
};

int main ()
{
  a b(42);
  do_stuff(42, "Ada");
}