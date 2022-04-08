#include "Convert.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "You can enter only one parameter." << std::endl;
		return 0;
	}
	try
	{
		std::string line = argv[1];
		std::cout << "char: " << line << std::endl;
		std::cout << "int: " << std::stoi(line) << std::endl;
		std::cout << "float: " << std::stof(line) << std::endl;
		std::cout << "double: " << std::stod(line) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << "wtf" << std::endl;
	}
	return 0;
}
