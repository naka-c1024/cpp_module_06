#include "Convert.hpp"
#include <iostream>

Convert::Convert()
{
}
Convert::~Convert()
{
}
Convert::Convert(const Convert &other)
{
	*this = other;
}
Convert &Convert::operator=(const Convert &other)
{
	if (this != &other)
	{
	}
	return *this;
}

Convert::Convert(std::string str): _str(str)
{
	// 4つ関数を作成する, try catchでやってみる
}

void	Convert::run()
{
	ensurePossible();
	executeChar();
	executeInt();
	executeFloat();
	executeDouble();
}

void	Convert::ensurePossible()
{
	if (this->_str.length() == 0)
	{
		std::cerr << "char: impossible" << std::endl;
		std::cerr << "int: impossible" << std::endl;
		std::cerr << "float: impossible" << std::endl;
		std::cerr << "double: impossible" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	if (std::isalpha(this->_str[0]) == 1 && this->_str[1] != '\0')
	{
		std::cerr << "char: impossible" << std::endl;
		std::cerr << "int: impossible" << std::endl;
		std::cerr << "float: impossible" << std::endl;
		std::cerr << "double: impossible" << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

void	Convert::executeChar()
{
	if (this->_str.length() > 3)
	{
		std::cout << "char: impossible" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	if (this->_str.length() == 1) // アルファベットなどの場合
	{
		this->_str = std::to_string(this->_str[0]);
	}
	int	tmp = std::atoi(_str.c_str());
	if (std::isprint(tmp))
	{
		this->_char = static_cast<char>(tmp);
		std::cout << "char: \'" << this->_char << "\'" << std::endl;
	}
	else
	{
		std::cout << "char: Non displayable" << std::endl;
	}
}
void	Convert::executeInt()
{
	try
	{
		this->_int = static_cast<int>(std::stoi(this->_str));
		std::cout << "int: " << this->_int << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "int: impossible" << std::endl;
	}
}
void	Convert::executeFloat()
{
	try
	{
		this->_float = static_cast<float>(std::stof(this->_str));
		std::cout << "float: " << this->_float << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "float: impossible" << std::endl;
	}
}
void	Convert::executeDouble()
{
	try
	{
		this->_double = static_cast<double>(std::stod(this->_str));
		std::cout << "double: " << this->_double << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "double: impossible" << std::endl;
	}
}