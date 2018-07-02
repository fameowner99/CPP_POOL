#include "Span.hpp"

Span::~Span()
{
	std::cout << "Destructor" << std::endl;
}

Span::Span(): _n(0) {}

Span::Span(unsigned int n): _n(n){}

Span::Span(const Span &obj)
{
	*this = obj;
}

Span& Span::operator=(const Span &obj)
{
	_n = obj._n;
	_container = obj._container;
	return (*this);
}

void	Span::addNumber(int number)
{
	if (+_container.size() + 1 > _n)
		throw(std::overflow_error("Container is FULL!"));
	_container.push_back(number);
}

int Span::longestSpan()
{
	if (_container.size() <= 1)
		throw(std::logic_error("It is one or zero elements in the container"));
	return (*std::max_element(_container.begin(), _container.end()) - *std::min_element(_container.begin(), _container.end()));

}

int 	Span::shortestSpan()
{
	std::vector<int> myvect = _container;

	std::sort(myvect.begin(), myvect.end());
	return (*std::min_element(myvect.begin() + 1, myvect.end()) - myvect[0]);
}