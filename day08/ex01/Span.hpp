#ifndef SPAN_HPP

# define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>

class Span
{
	public:
		~Span();
		Span();
		Span(const Span&);
		Span(unsigned int n);
		Span &operator=(const Span&);
		void addNumber(int number);
		int shortestSpan();
		int longestSpan();
	private:
		unsigned int _n;
		std::vector<int> _container;

};

#endif