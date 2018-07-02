#ifndef ARRAY_HPP

# define ARRAY_HPP

# include <iostream>

template<typename T> class Array
{
public:
	Array<T>(): _numberElements(0)
	{
		_array = nullptr;
	}

	Array<T>(unsigned int n): _numberElements(n)
	{
		_array = new T[n]();
	}

	Array<T>(Array<T> const &obj)
	{
		*this = obj;
	}

	Array<T>& operator=(Array<T> const &obj)
	{
		_numberElements = obj._numberElements;
		_array = new T[_numberElements]();
		for (unsigned int i = 0; i <_numberElements; i++)
			_array[i] = obj[i];
		return (*this);
	}

	T &operator[](unsigned int index) const
	{
		if (index >= _numberElements)
			throw std::exception();
		return (_array[index]);
	}

	unsigned int size()const
	{
		return (_numberElements);
	}

private:
	T				*_array;
	unsigned int	_numberElements;
};

#endif