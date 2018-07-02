#ifndef EASYFIND_HPP

# define EASYFIND_HPP

template<typename T> int	&easyfind(T &cont, int to_find)
{
	typename T::iterator it;

	it = find(cont.begin(), cont.end(), to_find);
	if (it == cont.end())
		throw std::logic_error("Container does not contain this value");
	return (*it);
}

#endif