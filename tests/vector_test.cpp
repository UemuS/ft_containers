#ifndef VECTOR_TEST_CPP
# define VECTOR_TEST_CPP
# include "utils.cpp"
# include "../vector.hpp"

void	vector_test(void)
{
    {
        print_banner("Constructors");
       // constructors used in the same order as described above:
        ft::vector<int> first;                                // empty vector of ints
        ft::vector<int> second (4,100);                       // four ints with value 100
        ft::vector<int> third (second.begin(),second.end());  // iterating through second
        ft::vector<int> fourth (third);                       // a copy of third

        // the iterator constructor can also be used to construct from arrays:
        int myints[] = {16,2,77,29};
        ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

        std::cout << "The contents of fifth are:";
        for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }
    {
        print_banner("operator=");
        ft::vector<int> foo (3,0);
        ft::vector<int> bar (5,0);

        bar = foo;
        foo = ft::vector<int>();

        std::cout << "Size of foo: " << int(foo.size()) << '\n';
        std::cout << "Size of bar: " << int(bar.size()) << '\n';
    }
    {
        print_banner("Iterators: begin, end, rbegin and rend");
        ft::vector<int> myvector (5);  // 5 default-constructed ints

        int i=0;

        ft::vector<int>::reverse_iterator rit = myvector.rbegin();
        for (; rit!= myvector.rend(); ++rit)
            *rit = ++i;

        std::cout << "myvector contains:";
        for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }
    {
        print_banner("Capacity functions : size, max_size and capacity");
        ft::vector<int> myvector;

        // set some content in the vector:
        for (int i = 0; i < 100; i++) myvector.push_back(i);

        std::cout << "size: " << myvector.size() << '\n';
        std::cout << "capacity: " << myvector.capacity() << '\n';
        std::cout << "max_size: " << myvector.max_size() << '\n';
    }
    {
        print_banner("Capacity functions : resize");
        ft::vector<int> myvector;

        // set some initial content:
        for (int i=1;i<10;i++) myvector.push_back(i);

        myvector.resize(5);
        myvector.resize(8,100);
        myvector.resize(12);

        std::cout << "myvector contains:";
        for (size_t i=0;i<myvector.size();i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }
    {
        print_banner("Capacity functions : reserve");
        ft::vector<int>::size_type sz;

        ft::vector<int> foo;
        sz = foo.capacity();
        std::cout << "making foo grow:\n";
        for (int i=0; i<100; ++i)
        {
            foo.push_back(i);
            if (sz!=foo.capacity())
            {
                sz = foo.capacity();
                std::cout << "capacity changed: " << sz << '\n';
            }
        }

        ft::vector<int> bar;
        sz = bar.capacity();
        bar.reserve(100);   // this is the only difference with foo above
        std::cout << "making bar grow:\n";
        for (int i=0; i<100; ++i)
        {
            bar.push_back(i);
            if (sz!=bar.capacity())
            {
                sz = bar.capacity();
                std::cout << "capacity changed: " << sz << '\n';
            }
        }
    }
    {
        print_banner("Modifiers Functions: Assign");
        ft::vector<int> first;
        ft::vector<int> second;
        ft::vector<int> third;

        first.assign (7, 100);             // 7 ints with a value of 100

        ft::vector<int>::iterator it;
        it = first.begin() + 1;

        second.assign (it, first.end() - 1); // the 5 central values of first

        int myints[] = {1776, 7, 4};
        third.assign (myints, myints + 3);   // assigning from array.

        std::cout << "first vector [100 100 100 100 100 100 100] = ";
        for (it = first.begin(); it != first.end(); it++) std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "second vector [100 100 100 100 100] = ";
        for (it = second.begin(); it != second.end(); it++) std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "third vector [1776 7 4] = ";
        for (it = third.begin(); it != third.end(); it++) std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "Size of first: " << int (first.size()) << std::endl;
        std::cout << "Size of second: " << int (second.size()) << std::endl;
        std::cout << "Size of third: " << int (third.size()) << std::endl;
    }
    {
        print_banner("Element access: operator[]");
        ft::vector<int> myvector (10);   // 10 zero-initialized elements

        ft::vector<int>::size_type sz = myvector.size();

        // assign some values:
        for (unsigned i=0; i<sz; i++) myvector[i]=i;

        // reverse vector using operator[]:
        for (unsigned i=0; i<sz/2; i++)
        {
            int temp;
            temp = myvector[sz-1-i];
            myvector[sz-1-i]=myvector[i];
            myvector[i]=temp;
        }

        std::cout << "myvector contains:";
        for (unsigned i=0; i<sz; i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }
    {
        print_banner("Element access: at");
        ft::vector<int> myvector (10);   // 10 zero-initialized ints

        // assign some values:
        std::cout << "myvector contains at initialization construct:";
        for (size_t i = 0; i < myvector.size(); i++) std::cout << ' ' << myvector.at(i);
        for (size_t i = 0; i < myvector.size(); i++) myvector.at(i) = i;
        std::cout << std::endl << "myvector contains after assign new values:";
        for (size_t i = 0; i < myvector.size(); i++) std::cout << ' ' << myvector.at(i);
        std::cout << std::endl;
    }
    {
        print_banner("Element access: front");
        ft::vector<int> myvector;
        myvector.push_back(78);
        myvector.push_back(16);
        // now front equals 78, and back 16
        myvector.front() -= myvector.back();
        std::cout << "myvector.front() is now " << myvector.front() << '\n';
    }
    {
        print_banner("Element access: back");
        ft::vector<int> myvector;

        myvector.push_back(10);
        while (myvector.back() != 0) myvector.push_back (myvector.back() - 1);
        std::cout << "myvector contains:";
        for (size_t i = 0; i < myvector.size(); i++) std::cout << ' ' << myvector[i];
        std::cout << std::endl;
    }
    {
        print_banner("Element access: at");
        std::cout << "begin function:" << std::endl;
        ft::vector<int> myvector;
        for (int i = 1; i <= 5; i++) myvector.push_back(i);

        std::cout << "myvector contains:";
        for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << std::endl;
    }
    {
        print_banner("Modifiers functions: clear");
        ft::vector<int> myvector;
        myvector.push_back (100);
        myvector.push_back (200);
        myvector.push_back (300);

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); i++) std::cout << ' ' << myvector[i];
        std::cout << std::endl;

        std::cout << myvector.capacity() << std::endl;
        myvector.clear();
        std::cout << myvector.capacity() << std::endl;
        myvector.push_back (1101);
        myvector.push_back (2202);

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); i++) std::cout << ' ' << myvector[i];
        std::cout << std::endl;
        std::cout << myvector.capacity() << std::endl;
    }
    {
        print_banner("Modifiers functions: push_back, pop_back");
        ft::vector<int> myvector;
        int sum (0);

        for (int i = 1; i <= 10; i++) myvector.push_back(i);

        while (!myvector.empty())
        {
            sum += myvector.back();
            myvector.pop_back();
        }
        std::cout << "total: " << sum << '\n';
    }
    {
        print_banner("Modifiers functions: erase");
        std::cout << "erase function:" << std::endl;
        ft::vector<int> myvector;

        // set some values (from 1 to 10)
        for (int i = 1; i <= 10; i++) myvector.push_back(i);
        std::cout << "myvector contains:";
        for (unsigned i = 0; i < myvector.size(); ++i) std::cout << ' ' << myvector[i];
        std::cout << '\n';
        // erase the 6th element
        myvector.erase (myvector.begin() + 5);
        std::cout << "myvector contains:";
        for (unsigned i = 0; i < myvector.size(); ++i) std::cout << ' ' << myvector[i];
        std::cout << '\n';

        // erase the first 3 elements:
        myvector.erase (myvector.begin(), myvector.begin() + 3);
        std::cout << "myvector contains:";
        for (unsigned i = 0; i < myvector.size(); ++i) std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }
    {
        print_banner("Modifiers functions: insert");
        ft::vector<int> myvector (3, 100);
        ft::vector<int>::iterator it;

        it = myvector.begin();
        it = myvector.insert(it, 200);

        myvector.insert(it, 2, 300);

        // "it" no longer valid, get a new one:
        it = myvector.begin();

        ft::vector<int> anothervector (2, 400);
        myvector.insert (it + 2, anothervector.begin(), anothervector.end());

        int myarray [] = { 501,502,503 };
        myvector.insert (myvector.begin(), myarray, myarray + 3);

        std::cout << "myvector contains:";
        for (it = myvector.begin(); it < myvector.end(); it++) std::cout << ' ' << *it;
        std::cout << '\n';
    }
    {
        print_banner("Modifiers functions: Swap");
        ft::vector<int> foo (3,100);   // three ints with a value of 100
        ft::vector<int> bar (5,200);   // five ints with a value of 200

        foo.swap(bar);

        std::cout << "foo contains:";
        for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';

        std::cout << "bar contains:";
        for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }
    {
        print_banner("relational operators");
		ft::vector<int> vec;
		vec.push_back(5);
		vec.push_back(42);
			assert(vec.size() == 2);

		ft::vector<int> vec2;
		vec2.push_back(5);
		vec2.push_back(42);
			assert(vec2.size() == 2);

		ft::vector<int> vec3;
		vec3.push_back(5);
		vec3.push_back(42);
		vec3.push_back(43);
			assert(vec3.size() == 3);

		ft::vector<int> vec4;
		vec4.push_back(99);
		vec4.push_back(42);
		vec4.push_back(43);
			assert(vec4.size() == 3);

		std::cout << "same vector:" << '\n'
			<< "comparison == " << (vec == vec2) << '\n'
			<< "comparison != " << (vec != vec2) << '\n'
			<< "comparison <  " << (vec < vec2) << '\n'
			<< "comparison >  " << (vec > vec2) << '\n'
			<< "comparison <= " << (vec <= vec2) << '\n'
			<< "comparison >= " << (vec >= vec2) << '\n';
		assert(vec == vec2);
		assert(!(vec != vec2));
		assert(!(vec < vec2));
		assert(!(vec > vec2));
		assert(vec <= vec2);
		assert(vec >= vec2);

		std::cout << "lesser vector:" << '\n'
			<< "comparison == " << (vec == vec3) << '\n'
			<< "comparison != " << (vec != vec3) << '\n'
			<< "comparison <  " << (vec < vec3) << '\n'
			<< "comparison >  " << (vec > vec3) << '\n'
			<< "comparison <= " << (vec <= vec3) << '\n'
			<< "comparison >= " << (vec >= vec3) << '\n';
		assert(!(vec == vec3));
		assert(vec != vec3);
		assert(vec < vec3);
		assert(!(vec > vec3));
		assert(vec <= vec3);
		assert(!(vec >= vec3));

		std::cout << "upper vector:" << '\n'
			<< "comparison == " << (vec4 == vec) << '\n'
			<< "comparison != " << (vec4 != vec) << '\n'
			<< "comparison <  " << (vec4 < vec) << '\n'
			<< "comparison >  " << (vec4 > vec) << '\n'
			<< "comparison <= " << (vec4 <= vec) << '\n'
			<< "comparison >= " << (vec4 >= vec) << '\n';
		assert(!(vec4 == vec));
		assert(vec4 != vec);
		assert(!(vec4 < vec));
		assert(vec4 > vec);
		assert(!(vec4 <= vec));
		assert(vec4 >= vec);
	}
	{
        print_banner("swap");
		ft::vector<int> vec;
		vec.push_back(5);
		vec.push_back(42);
		vec.push_back(43);
			assert(vec.size() == 3);

		ft::vector<int> vec2;
		vec2.push_back(12);
		vec2.push_back(30);
		vec2.push_back(60);
			assert(vec2.size() == 3);

		display_container("vec [5, 42, 43]:", vec);
            assert(vec[0] == 5);
            assert(vec[1] == 42);
            assert(vec[2] == 43);
            assert(vec.size() == 3);
		display_container("vec2 [12, 30, 60]:", vec2);
            assert(vec2[0] == 12);
            assert(vec2[1] == 30);
            assert(vec2[2] == 60);
            assert(vec2.size() == 3);
        std::swap(vec, vec2);
		std::cout << "---swapped\n";
		display_container("vec [12, 30, 60]:", vec);
            assert(vec[0] == 12);
            assert(vec[1] == 30);
            assert(vec[2] == 60);
            assert(vec.size() == 3);
		display_container("vec2 [5, 42, 43]:", vec2);
            assert(vec2[0] == 5);
            assert(vec2[1] == 42);
            assert(vec2[2] == 43);
            assert(vec2.size() == 3);
		std::swap(vec, vec2);
		std::cout << "---swapped\n";
		display_container("vec [5, 42, 43]:", vec);
            assert(vec[0] == 5);
            assert(vec[1] == 42);
            assert(vec[2] == 43);
            assert(vec.size() == 3);
		display_container("vec2 [12, 30, 60]:", vec2);
            assert(vec2[0] == 12);
            assert(vec2[1] == 30);
            assert(vec2[2] == 60);
            assert(vec2.size() == 3);
	}
}

#endif
