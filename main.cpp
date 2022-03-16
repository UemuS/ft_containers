#include "ft_vector.hpp"


int main()
{
    ft::vector<int> a(10,5);
    ft::vector< ft::vector<int> > b(1, a);
    std::cout << b[0][0] << '\n';
    b[0] = a;
    // for(unsigned int i = 0; i < b.size(); i++)
    std::cout << b[0][0] << '\n';
    //system("leaks a.out");
}