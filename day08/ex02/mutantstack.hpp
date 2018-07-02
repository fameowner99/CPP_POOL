#include <stack>
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

template <typename T>
class MutantStack : public std::stack<T>
{

public:
	MutantStack(void) {}
	~MutantStack(void) {}
	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin()
	{
		return std::stack<T>::c.begin();
	}
	iterator end()
	{
		return std::stack<T>::c.end() ;
	}
};

#endif