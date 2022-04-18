#include "vector.hpp"
#include "tools.hpp"
#include "stack.hpp"
#include <typeinfo>
#include "map.hpp"
#include "RBT.hpp"

#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
template <typename T>
void printvec(ft::vector<T> &a)
{
  std::cout << "ft size : " << a.size() << " capacity : " << a.capacity() << '\n';
  for (size_t i = 0; i < a.size(); i++)
    std::cout << "| " << a[i] << " |";
  std::cout << "\n\n";
}

template <typename T>
void printvec(std::vector<T> &a)
{
  std::cout << "std size : " << a.size() << " capacity : " << a.capacity() << '\n';
  for (size_t i = 0; i < a.size(); i++)
    std::cout << "| " << a[i] << " |";
  std::cout << "\n\n";
}

void do_stuff(int t)
{
  std::cout << "integral  " << &t << '\n';
}

template <class T>
void do_stuff(T t, typename ft::enable_if<!ft::is_integral<T>::value>::type * = 0)
{
  std::cout << "not integral  " << &t << '\n';
}

class a
{
public:
  a(int i) : i(i) {}
  int i;
};


class B {
public:
	char *l;
	int i;
	B():l(nullptr), i(1) {};
	B(const int &ex) {
		this->i = ex;
		this->l = new char('a');
	};
	virtual ~B() {
		delete this->l;
		this->l = nullptr;
	};
};

class A : public B {
public:
	A():B(){};
	A(const B* ex){
		this->l = new char(*(ex->l));
		this->i = ex->i;
		if (ex->i == -1) throw "n";
	}
	~A() {
		delete this->l;
		this->l = nullptr;
	};
};


#include <set>
int main()
{
    // ft::vector<int> a(5);
    // ft::vector<int> b(5);
    // ft::vector<int>::iterator ite = a.begin();
    // ft::vector<int>::const_iterator it = b.end();
    // std::cout << ite - it << '\n';

    ft::pair <int,int> a;
	ft::pair <int,int> b;
	a.first = 1;
	a.second = 2;
	RBTree<int, ft::pair<int,int> > c;
	// c.insert(1, ft::make_pair(1,5));
	// c.insert(a.first, a);
	// c.insert(2,ft::make_pair(2,9));
	// c.insert(3,ft::make_pair(3,7));
	// c.insert(4,ft::make_pair(4,8));
	// c.insert(0, ft::make_pair(0,0));
	// c.insert(5,ft::make_pair(5,6));
	// c.insert(6,ft::make_pair(6,4));

	srand(0);
	for (int i = 0; i < 10; i++)
	{
		c.insert(i, ft::make_pair(i,rand()));
	}
	std::cout << c.root->element.first << '\n';
	for (int i = 3; i < 9;i++)
	{
		c.deleteNode(i);
		std::cout << "*************************\n";
		std::cout << c.root->element.first << '\n';
	}
	c.print(c.root);
	std::cout << c.depth(c.root) << '\n';

}