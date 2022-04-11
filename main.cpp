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

    ft::pair<int,int> p(ft::make_pair(1,2));
	RBTree<int,int> rb;
	rb.insert(5,6);
	rb.insert(3,4);
	rb.insert(1,4);
	rb.insert(9,4);
	rb.insert(0,4);
	rb.insert(10,4);
	rb.insert(50,4);
	rb.printNodes(rb.root);
	std::cout << "**************** << '\n";
	rb.erase(rb.root);
	std::cout << rb.getNode(10)->element.value << '\n';
}