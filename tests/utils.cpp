#ifndef UTILS_CPP
# define UTILS_CPP

# include <iostream>

void		print_banner(std::string title)
{
	std::cout << "<<<<<<<<<<<<<<< " << title << " >>>>>>>>>>>>>>> " << std::endl;
}

template<typename Container>
void display_container(std::string const &header, Container const &ctn)
{
	typename Container::const_iterator it = ctn.begin();
	typename Container::const_iterator ite = ctn.end();
	std::cout << header;
	if (it == ite)
		std::cout << " empty !";
	std::cout << '\n';
	while (it != ite)
	{
		std::cout << *it;
		if (++it == ite)
			std::cout << '\n';
		else
			std::cout <<  ", ";
	}
}

template<typename Container>
void display_container(Container const &ctn)
{
	typename Container::const_iterator it = ctn.begin();
	typename Container::const_iterator ite = ctn.end();
	if (it == ite)
		std::cout << " empty !" << std::endl;
	while (it != ite)
	{
		std::cout << *it;
		if (++it == ite)
			std::cout << '\n';
		else
			std::cout <<  ", ";
	}
}


template<typename T>
bool less_than_99(T const &nbr) {
	return (nbr < 99);
}

template<typename T>
bool less_than_43(T const &nbr) {
	return (nbr < 43);
}

template<typename T>
bool less_than_1(T const &nbr) {
	return (nbr < 1);
}

template<typename T>
bool lesser_than_rhs(T const &nbr1, T const &nbr2) {
	return (nbr1 <= nbr2);
}

template<typename T>
bool sort_desc(T const &nbr1, T const &nbr2) {
	return (nbr1 > nbr2);
}

bool same_integral_part(double first, double second) {
	return (int(first) == int(second));
}

template<typename T>
bool equal_plus_one(T first, T second) {
	return (second == (first + 1));
}

#endif
