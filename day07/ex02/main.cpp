#include "Array.tpp"

int main()
{
	Array<int> myArr(5);

		for(int i = 0; i < myArr.size(); ++i)
			std::cout << myArr[i] << " ";
		std::cout << std::endl;

		for(int i = 0; i < myArr.size(); ++i)
			myArr[i] = i + 4;

		for(int i = 0; i < myArr.size(); ++i)
			std::cout << myArr[i] << " ";
		std::cout << std::endl;
	try
	{
		std::cout << myArr[7];
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR" << std::endl;
	}

		Array<int> a = myArr;

		for(int i = 0; i < a.size(); ++i)
			std::cout << a[i] << " ";
		std::cout << std::endl;


	for(int i = 0; i < myArr.size(); ++i)
		myArr[i] = 10;

	for(int i = 0; i < myArr.size(); ++i)
		std::cout << myArr[i] << " ";
	std::cout << std::endl;


	for(int i = 0; i < a.size(); ++i)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	a = myArr;

	for(int i = 0; i < myArr.size(); ++i)
		std::cout << myArr[i] << " ";
	std::cout << std::endl;


	for(int i = 0; i < a.size(); ++i)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	Array<std::string> s(11);


	for(int i = 0; i < s.size(); ++i)
		std::cout << s[i] << " |";
	std::cout << std::endl;

	for(int i = 0; i < s.size(); ++i)
		s[i]  = "abcd";


	for(int i = 0; i < s.size(); ++i)
		std::cout << s[i] << " |";
	std::cout << std::endl;
	return (0);
}