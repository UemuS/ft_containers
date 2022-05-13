#ifndef SET_TEST_CPP
# define SET_TEST_CPP
# include "../set.hpp"
# include "utils.cpp"

void        set_test(void)
{
	{
		print_banner("Constructors");
		ft::set<int> first;
		ft::set<int>::iterator it;

		first.insert(70);
		first.insert(30);
		first.insert(50);
		first.insert(20);

		std::cout << "first map contains:\n";
		for (it=first.begin(); it!=first.end(); ++it)
			std::cout << *it << '\n';

		std::cout << "second map contains:\n";
		ft::set<int> second (first.begin(),first.end());
		for (it=second.begin(); it!=second.end(); ++it)
			std::cout << *it<< '\n';

		std::cout << "third map contains:\n";
		ft::set<int> third (second);
		for (it=third.begin(); it!=third.end(); ++it)
			std::cout << *it<< '\n';
	}
	{
		print_banner("operator=");
		int myints[]={ 12,82,37,64,15 };
		ft::set<int> first (myints,myints+5);   // set with 5 ints
		ft::set<int> second;                    // empty set

		second = first;                          // now second contains the 5 ints
		first = ft::set<int>();                 // and first is empty

		std::cout << "Size of first: " << int (first.size()) << '\n';
		std::cout << "Size of second: " << int (second.size()) << '\n';
	}
	{
		print_banner("rbegin and rend iterators");
		int myints[] = {21,64,17,78,49};
		ft::set<int> myset (myints,myints+5);

		ft::set<int>::reverse_iterator rit;

		std::cout << "myset contains:";
		for (rit=myset.rbegin(); rit != myset.rend(); ++rit)
			std::cout << ' ' << *rit;

		std::cout << '\n';
	}
	{
		print_banner("empty and erase function");
		ft::set<int> myset;

		myset.insert(20);
		myset.insert(30);
		myset.insert(10);

		std::cout << "myset contains:";
		while (!myset.empty())
		{
			std::cout << ' ' << *myset.begin();
			myset.erase(myset.begin());
		}
		std::cout << '\n';
	}
	{
		print_banner("size and max_size function");
		ft::set<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<10; ++i) myints.insert(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.insert (100);
		std::cout << "2. size: " << myints.size() << '\n';

		myints.erase(5);
		std::cout << "3. size: " << myints.size() << '\n';
		std::cout << "max_size: " << myints.max_size() << '\n';
	}
	{
		print_banner("Insert function");
		ft::set<int> myset;
		ft::set<int>::iterator it;
		ft::pair<ft::set<int>::iterator,bool> ret;

		// set some initial values:
		for (int i=1; i<=5; ++i) myset.insert(i*10);    // set: 10 20 30 40 50

		ret = myset.insert(20);               // no new element inserted

		if (ret.second==false) it=ret.first;  // "it" now points to element 20

		myset.insert (it,25);                 // max efficiency inserting
		myset.insert (it,24);                 // max efficiency inserting
		myset.insert (it,26);                 // no max efficiency inserting

		int myints[]= {5,10,15};              // 10 already in set, not inserted
		myset.insert (myints,myints+3);

		std::cout << "myset contains:";
		for (it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	{
		print_banner("swap function");
		int myints[]={12,75,10,32,20,25};
		ft::set<int> first (myints,myints+3);     // 10,12,75
		ft::set<int> second (myints+3,myints+6);  // 20,25,32

		first.swap(second);

		std::cout << "first contains:";
		for (ft::set<int>::iterator it=first.begin(); it!=first.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "second contains:";
		for (ft::set<int>::iterator it=second.begin(); it!=second.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	{
		print_banner("clear function");
		ft::set<int> myset;

		myset.insert (100);
		myset.insert (200);
		myset.insert (300);

		std::cout << "myset contains:";
		for (ft::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		myset.clear();
		myset.insert (1101);
		myset.insert (2202);

		std::cout << "myset contains:";
		for (ft::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	{
		print_banner("key_comp function");
		ft::set<int> myset;
		int highest;

		ft::set<int>::key_compare mycomp = myset.key_comp();

		for (int i=0; i<=5; i++) myset.insert(i);

		std::cout << "myset contains:";

		highest=*myset.rbegin();
		ft::set<int>::iterator it=myset.begin();
		do
		{
			std::cout << ' ' << *it;
		} while (mycomp(*(++it),highest));

		std::cout << '\n';
	}
	{
		print_banner("value_comp function");
		ft::set<int> myset;

		ft::set<int>::value_compare mycomp = myset.value_comp();

		for (int i=0; i<=5; i++) myset.insert(i);

		std::cout << "myset contains:";

		int highest=*myset.rbegin();
		ft::set<int>::iterator it=myset.begin();
		do
		{
			std::cout << ' ' << *it;
		} while (mycomp(*(++it),highest));

		std::cout << '\n';
	}
	{
		print_banner("Find function");
		ft::set<int> myset;
		ft::set<int>::iterator it;

		// set some initial values:
		for (int i=1; i<=5; i++) myset.insert(i*10);    // set: 10 20 30 40 50

		it=myset.find(20);
		myset.erase (it);
		myset.erase (myset.find(40));

		std::cout << "myset contains:";
		for (it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	{
		print_banner("count function");
		ft::set<int> myset;

		// set some initial values:
		for (int i=1; i<5; ++i) myset.insert(i*3);    // set: 3 6 9 12

		for (int i=0; i<10; ++i)
		{
			std::cout << i;
			if (myset.count(i)!=0)
			std::cout << " is an element of myset.\n";
			else
			std::cout << " is not an element of myset.\n";
		}
	}
	{
		print_banner("lower_bound and upper_bound function");
		ft::set<int> myset;
		ft::set<int>::iterator itlow,itup;

		for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90

		itlow=myset.lower_bound (30);                //       ^
		itup=myset.upper_bound (60);                 //                   ^

		myset.erase(itlow,itup);                     // 10 20 70 80 90

		std::cout << "myset contains:";
		for (ft::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	{
		print_banner("equal_range function:");
		ft::set<int> myset;

		for (int i=1; i<=5; i++) myset.insert(i*10);   // myset: 10 20 30 40 50

		ft::pair<ft::set<int>::iterator,ft::set<int>::iterator> ret;
		ret = myset.equal_range(30);

		std::cout << "the lower bound points to: " << *ret.first << '\n';
		std::cout << "the upper bound points to: " << *ret.second << '\n';
	}
	{
		print_banner("comparaision operators");
		ft::set<int> set1;
		set1.insert(10);
		set1.insert(1);
		set1.insert(100);

		ft::set<int> set2;
		set2.insert(10);
		set2.insert(1);
		set2.insert(100);

		if (set1 == set2)
			std::cout << "set1 is equal to set2" << std::endl;
		if (set1 < set2)
			std::cout << "set1 is smaller than set2" << std::endl;
		if (set1 <= set2)
			std::cout << "set1 is smaller than or equal to set2" << std::endl;
		if (set1 > set2)
			std::cout << "set1 is larger than set2" << std::endl;
		if (set1 >= set2)
			std::cout << "set1 is larger than or equal to set2" << std::endl;
		set1.insert(20);
		if (set1 == set2)
			std::cout << "set1 is equal to set2" << std::endl;
		if (set1 < set2)
			std::cout << "set1 is smaller than set2" << std::endl;
		if (set1 <= set2)
			std::cout << "set1 is smaller than or equal to set2" << std::endl;
		if (set1 > set2)
			std::cout << "set1 is larger than set2" << std::endl;
		if (set1 >= set2)
			std::cout << "set1 is larger than or equal to set2" << std::endl;
	}
}
#endif
