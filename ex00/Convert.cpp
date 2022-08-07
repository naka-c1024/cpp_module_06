#include "Convert.hpp"
#include <iostream>
#include <iomanip>
#include <math.h>

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
}

void	Convert::run()
{
	exePseudoLiteral();
	ensurePossible();
	executeChar();
	executeInt();
	executeFloat();
	executeDouble();
}

void	Convert::exePseudoLiteral()
{
	if (this->_str == "nan" || this->_str == "+nan" || this->_str == "nanf" || this->_str == "+nanf")
		displayResult(IP, IP, "nanf", "nan");
	else if (this->_str == "-nan" || this->_str == "-nanf")
		displayResult(IP, IP, "-nanf", "-nan");
	else if (this->_str == "inf" || this->_str == "+inf" || this->_str == "inff" || this->_str == "+inff")
		displayResult(IP, IP, "inff", "inf");
	else if (this->_str == "-inf" || this->_str == "-inff")
		displayResult(IP, IP, "-inff", "-inf");
}

void	Convert::displayResult(std::string c, std::string i, std::string f, std::string d)
{
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << d << std::endl;
	std::exit(EXIT_SUCCESS);
}

std::size_t	Convert::cntDot(std::string str)
{
	const char	*tmp = str.c_str();
	size_t	i = 0;
	while (*tmp || i > 2)
	{
		if (*tmp == '.')
			i++;
		tmp++;
	}
	return i;
}

void	Convert::ensurePossible()
{
	if (this->_str.length() == 0)
	{
		displayResult(IP, IP, IP, IP);
		std::exit(EXIT_FAILURE);
	}
	if (std::isalpha(this->_str[0]) == 1 && this->_str[1] != '\0')
	{
		displayResult(IP, IP, IP, IP);
		std::exit(EXIT_FAILURE);
	}
	if (cntDot(this->_str) > 1)
	{
		displayResult(IP, IP, IP, IP);
		std::exit(EXIT_FAILURE);
	}
}

void	Convert::executeChar()
{
	if (this->_str.length() == 1 && std::isdigit(this->_str[0]) == 0) // アルファベットなどの場合
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
		std::cout << "float: " << this->_float;
		if (fmodf(this->_float, 1.0f) == 0)
			std::cout << ".0f" << std::endl;
		else
			std::cout << std::endl;
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
		if (fmod(this->_double, 1.0) == 0)
		{
			std::cout << std::fixed;
			std::cout << "double: " << std::setprecision(1) << this->_double << std::endl;
		}
		else
			std::cout << "double: " << this->_double << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "double: impossible" << std::endl;
	}
}