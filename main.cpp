#include "vector.hpp"

template<typename T>
void    printvec(std::vector<T> &a)
{
    std::cout << "size : " << a.size() << " capacity : " << a.capacity()<< '\n';
    for(size_t i = 0; i < a.size(); i++)
        std::cout << "| " << a[i] << " |";
    std::cout << "\n\n";
}

int main ()
{
  std::vector<int> myvector (8,100);
  std::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );

  myvector.insert (it,10,300);

  // "it" no longer valid, get a new one:
  it = myvector.begin();

  // std::vector<int> anothervector (2,400);
  // myvector.insert (it+2,anothervector.begin(),anothervector.end());

  // int myarray [] = { 501,502,503 };
  // myvector.insert (myvector.begin(), myarray, myarray+3);
  std::cout << it - myvector.begin() << '\n';
  printvec(myvector);
  std::cout << '\n';
}