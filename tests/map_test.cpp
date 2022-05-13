#ifndef MAP_TEST_CPP
# define MAP_TEST_CPP

#include "../map.hpp"
# include "utils.cpp"

void        map_test(void)
{
	{
		print_banner("Constructors");
		ft::map<char,int>::iterator it;
		ft::map<char,int> first;

		first['a']=10;
		first['d']=70;
		first['b']=30;
		first['c']=50;

		std::cout << "first map contains:\n";
		for (it=first.begin(); it!=first.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "second map contains:\n";
		ft::map<char,int> second (first.begin(),first.end());
		for (it=second.begin(); it!=second.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "third map contains:\n";
		ft::map<char,int> third (second);
		for (it=third.begin(); it!=third.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	{
		print_banner("operator[] and operator=");
		ft::map<char,int> mymap;

		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;

		std::cout << "mymap map contains:\n";
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		ft::map<char,int> othermap;
		othermap = mymap;
		std::cout << "othermap map contains:\n";
		for (ft::map<char,int>::iterator it=othermap.begin(); it!=othermap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	{
		print_banner("function insert and iterators");
		ft::map<char,int>       mymap;
		ft::map<char,int>::iterator it;

		// first insert function version (single parameter):
		mymap.insert ( ft::pair<char,int>('a',100) );
		mymap.insert ( ft::pair<char,int>('z',200) );

		ft::pair<ft::map<char,int>::iterator, bool> ret;
		ret = mymap.insert ( ft::pair<char,int>('z',500) );
		if (ret.second == false)
		{
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << ret.first->second << '\n';
		}
		std::cout << "mymap contains:" << std::endl;
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << std::endl;

		it = mymap.begin();
		mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
		std::cout << "add 'b' to mymap:" << std::endl;
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << std::endl;

		it = mymap.begin();
		mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting
		std::cout << "add 'c' to mymap:" << std::endl;
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << std::endl;

		// third insert function version (range insertion):
		ft::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c'));

		// showing contents:
		std::cout << "anothermap contains: " << std::endl;
		for (it=anothermap.begin(); it!=anothermap.end(); ++it)
			std::cout << it->first << " => " << it->second << std::endl;
	}
	{
		print_banner("Erase and empty function");
		ft::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		while (!mymap.empty())
		{
			std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
			mymap.erase(mymap.begin());
		}
	}
	{
		print_banner("Size and max_size function");
		ft::map<char,int> mymap;
		mymap['g']=702;
		mymap['a']=101;
		mymap['b']=202;
		mymap['e']=502;
		mymap['c']=302;
		mymap['d']=402;
		mymap['f']=602;

		std::cout << "mymap.size() is " << mymap.size() << '\n';
		std::cout << "mymap.max_size() is " << mymap.max_size() << '\n';
	}
	{
		print_banner("count function");
		ft::map<char,int> mymap;
		char c;

		mymap ['a']= 101;
		mymap ['c']= 202;
		mymap ['f']= 303;

		for (c = 'a'; c < 'h'; c++)
		{
			std::cout << c;
			if (mymap.count(c) > 0)
				std::cout << " is an element of mymap.\n";
			else 
				std::cout << " is not an element of mymap.\n";
		}
	}
	{
		print_banner("rbegin and rend iterators");
		ft::map<char,int> mymap;

		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;

		// show content:
		ft::map<char,int>::reverse_iterator rit;
		for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
			std::cout << rit->first << " => " << rit->second << '\n';
	}
	{
		print_banner("lower_bound and upper_bound functions");
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		itlow=mymap.lower_bound ('b');  // itlow points to b
		itup=mymap.upper_bound ('d');   // itup points to e (not d!)
		mymap.erase(itlow,itup);        // erases [itlow,itup)

		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	{
		print_banner("equal_range function");
		ft::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
		ret = mymap.equal_range('b');

		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';
	}
	{
		print_banner("swap function");
		ft::map<char,int> foo,bar;

		foo['x']=100;
		foo['y']=200;

		bar['a']=11;
		bar['b']=22;
		bar['c']=33;

		foo.swap(bar);

		std::cout << "foo contains:\n";
		for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		std::cout << "foo size " << foo.size() << std::endl;

		std::cout << "bar contains:\n";
		for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		std::cout << "bar size " << bar.size() << std::endl;
	}
	{
		print_banner("find function");
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator it;

		mymap['a'] = 50;
		mymap['b'] = 100;
		mymap['c'] = 150;
		mymap['d'] = 200;

		it = mymap.find('b');
		if (it != mymap.end())
			mymap.erase (it);
		std::cout << "elements in mymap:" << '\n';
		std::cout << "a => " << mymap.find('a')->second << '\n';
		std::cout << "c => " << mymap.find('c')->second << '\n';
		std::cout << "d => " << mymap.find('d')->second << '\n';
	}
	{
		print_banner( "clear function");
		ft::map<char,int> mymap;

		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;

		std::cout << "mymap contains:\n";
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		mymap.clear();
		mymap['a'] = 1101;
		mymap['b'] = 2202;

		std::cout << "mymap contains:\n";
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	{
		print_banner( "key_comp function");
		ft::map<char,int> mymap;
		ft::map<char,int>::key_compare mycomp = mymap.key_comp();

		mymap['a'] = 100;
		mymap['b'] = 200;
		mymap['c'] = 300;

		std::cout << "mymap contains:\n";

		char highest = mymap.rbegin()->first;     // key value of last element

		std::cout << "char -> " << highest << std::endl;

		ft::map<char,int>::iterator it = mymap.begin();
		do
		{
			std::cout << it->first << " => " << it->second << '\n';
		} while (mycomp((*it++).first, highest));
	}
	{
		print_banner("value_comp function");
		ft::map<char,int> mymap;

		mymap['x'] = 1001;
		mymap['y'] = 2002;
		mymap['z'] = 3003;

		std::cout << "mymap contains:\n";

		ft::pair<char,int> highest = *mymap.rbegin();          // last element

		ft::map<char,int>::iterator it = mymap.begin();
		do
		{
			std::cout << it->first << " => " << it->second << '\n';
		} while (mymap.value_comp()(*it++, highest));
	}
	{
		print_banner("comparaision operators");
		ft::map<int, int> map1;
		map1.insert(ft::make_pair(10, 57758));
		map1.insert(ft::make_pair(1, 80));
		map1.insert(ft::make_pair(100, 34));

		ft::map<int, int> map2;
		map2.insert(ft::make_pair(10, 57758));
		map2.insert(ft::make_pair(1, 80));
		map2.insert(ft::make_pair(100, 34));

		if (map1 == map2)
			std::cout << "map1 is equal to map2" << std::endl;
		if (map1 < map2)
			std::cout << "map1 is smaller than map2" << std::endl;
		if (map1 <= map2)
			std::cout << "map1 is smaller than or equal to map2" << std::endl;
		if (map1 > map2)
			std::cout << "map1 is larger than map2" << std::endl;
		if (map1 >= map2)
			std::cout << "map1 is larger than or equal to map2" << std::endl;
		map1.insert(ft::make_pair(20, 123));
		if (map1 == map2)
			std::cout << "map1 is equal to map2" << std::endl;
		if (map1 < map2)
			std::cout << "map1 is smaller than map2" << std::endl;
		if (map1 <= map2)
			std::cout << "map1 is smaller than or equal to map2" << std::endl;
		if (map1 > map2)
			std::cout << "map1 is larger than map2" << std::endl;
		if (map1 >= map2)
			std::cout << "map1 is larger than or equal to map2" << std::endl;
	}
}
#endif
