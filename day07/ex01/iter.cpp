#include <iostream>

void it(int &v)
{
	std::cout << v << std::endl;
}

void it(char &v)
{
	std::cout << v << std::endl;
}


void it(float &v)
{
	std::cout << v << std::endl;
}

template <typename T> void	iter(T *arr, int n, void (*it)(T &v))
{
	for (int i = 0; i < n; ++i)
	{
		it(arr[i]);
	}
}

int	main()
{
	int  a[5] = {1,2,3,4,5};
	char b[5] = {'a','b','c','d', 'e'};
	float c[5] = {1.0, 2.5, 3.6, 8.6, 1.2};
	iter<int>(a, 5, it);
	iter<char>(b, 5, it);
	iter<float>(c, 5, it);
	return (0);
}