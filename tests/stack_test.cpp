#ifndef STACK_TEST_HPP
# define STACK_TEST_HPP

# include "utils.cpp"
# include "../stack.hpp"
# include <deque>
# include <vector>

void	stack_test(void)
{
	{
		print_banner("Constructors");
		std::deque<int> mydeque (3,100);          // deque with 3 elements
		std::vector<int> myvector (2,200);        // vector with 2 elements

		ft::stack<int> first;                    // empty stack
		ft::stack<int, std::deque<int> > second (mydeque);         // stack initialized to copy of deque

		ft::stack<int,std::vector<int> > third;  // empty stack using vector
		ft::stack<int,std::vector<int> > fourth (myvector);

		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
		std::cout << "size of fourth: " << fourth.size() << '\n';
	}
	{
		print_banner("Push, empty, top and pop functions");
		ft::stack<int> mystack;
		int sum (0);

		for (int i=1;i<=10;i++) mystack.push(i);

		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}

		std::cout << "total: " << sum << '\n';
	}
	{
		print_banner("Size, top and pop functions extends");
		ft::stack<int> stk;
		std::cout << "[] (size: " << stk.size() << ")\n";
			assert(stk.size() == 0);
		stk.push(5);
		std::cout << "[5].top() = " << stk.top() << " (size: " << stk.size() << ", empty? " << stk.empty() << ")\n";
			assert(stk.top() == 5);
			assert(stk.size() == 1);
		stk.push(42);
		std::cout << "[5, 42].top() = " << stk.top() << " (size: " << stk.size() << ")\n";
			assert(stk.top() == 42);

		std::cout << "stack [5, 42].size() = " << stk.size() << '\n';
			assert(stk.size() == 2);

		stk.top() = 99;
		std::cout << "[5, 99].top() = " << stk.top() << " (size: " << stk.size() << ")\n";
			assert(stk.top() == 99);
			assert(stk.size() == 2);
		stk.pop();
		std::cout << "[5].top() = " << stk.top() << " (size: " << stk.size() << ")\n";
			assert(stk.top() == 5);
			assert(stk.size() == 1);
		stk.pop();
		std::cout << "[] (size: " << stk.size() << ")\n";
			assert(stk.size() == 0);
	}

	{
		std::cout << "\n---with deque container\n\n";
		std::deque<int> ctn;
		ctn.push_back(5);
		ctn.push_back(42);
		ctn.push_back(43);
		ctn.push_back(99);
		display_container("[5, 42, 43, 99] {List or Deque}:", ctn);
			assert(ctn.size() == 4);

		ft::stack<int, std::deque<int> > stk(ctn);
		std::cout << "stack empty? " << stk.empty() << '\n';
		std::cout << "stack size = " << stk.size() << '\n';
			assert(!stk.empty());
			assert(stk.size() == 4);

		std::cout << "[5, 42, 43, 99].top() = " << stk.top() << " (size: " << stk.size() << ")\n";
			assert(stk.top() == 99);
			assert(stk.size() == 4);
		stk.pop();
		std::cout << "[5, 42, 43].top() = " << stk.top() << " (size: " << stk.size() << ")\n";
			assert(stk.top() == 43);
			assert(stk.size() == 3);
		stk.pop();
		std::cout << "[5, 42].top() = " << stk.top() << " (size: " << stk.size() << ")\n";
			assert(stk.top() == 42);
			assert(stk.size() == 2);
		stk.pop();
		std::cout << "[5].top() = " << stk.top() << " (size: " << stk.size() << ")\n";
			assert(stk.top() == 5);
			assert(stk.size() == 1);
		stk.pop();
		std::cout << "[] (size: " << stk.size() << ")\n";
			assert(stk.size() == 0);

		display_container("[5, 42, 43, 99] {List after, no change}:", ctn);
	}

	{
		print_banner("Relational operators");
		ft::stack<int> stk;
		stk.push(5);
		stk.push(42);
		assert(stk.size() == 2);

		ft::stack<int> stk2;
		stk2.push(5);
		stk2.push(42);
		assert(stk2.size() == 2);

		ft::stack<int> stk3;
		stk3.push(5);
		stk3.push(42);
		stk3.push(43);
		assert(stk3.size() == 3);

		ft::stack<int> stk4;
		stk4.push(99);
		stk4.push(5);
		stk4.push(42);
		assert(stk4.size() == 3);

		std::cout << "same stack:\n"
			<< "comparison == " << (stk == stk2) << '\n'
			<< "comparison != " << (stk != stk2) << '\n'
			<< "comparison <  " << (stk < stk2) << '\n'
			<< "comparison >  " << (stk > stk2) << '\n'
			<< "comparison <= " << (stk <= stk2) << '\n'
			<< "comparison >= " << (stk >= stk2) << '\n';
		assert(stk == stk2);
		assert(!(stk != stk2));
		assert(!(stk < stk2));
		assert(!(stk > stk2));
		assert(stk <= stk2);
		assert(stk >= stk2);

		std::cout << "lesser stack:\n"
			<< "comparison == " << (stk == stk3) << '\n'
			<< "comparison != " << (stk != stk3) << '\n'
			<< "comparison <  " << (stk < stk3) << '\n'
			<< "comparison >  " << (stk > stk3) << '\n'
			<< "comparison <= " << (stk <= stk3) << '\n'
			<< "comparison >= " << (stk >= stk3) << '\n';
		assert(!(stk == stk3));
		assert(stk != stk3);
		assert(stk < stk3);
		assert(!(stk > stk3));
		assert(stk <= stk3);
		assert(!(stk >= stk3));

		std::cout << "upper stack:\n"
			<< "comparison == " << (stk4 == stk) << '\n'
			<< "comparison != " << (stk4 != stk) << '\n'
			<< "comparison <  " << (stk4 < stk) << '\n'
			<< "comparison >  " << (stk4 > stk) << '\n'
			<< "comparison <= " << (stk4 <= stk) << '\n'
			<< "comparison >= " << (stk4 >= stk) << '\n';
		assert(!(stk4 == stk));
		assert(stk4 != stk);
		assert(!(stk4 < stk));
		assert(stk4 > stk);
		assert(!(stk4 <= stk));
		assert(stk4 >= stk);
		std::cout << '\n';
	}
}

#endif
