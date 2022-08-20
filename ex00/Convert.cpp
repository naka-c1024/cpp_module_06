#include "Convert.hpp"
#include <iostream>
#include <iomanip>
#include <math.h>

Convert::Convert(): str_("invalid")
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
		this->str_ = other.str_;
		this->char_ = other.char_;
		this->int_ = other.int_;
		this->float_ = other.float_;
		this->double_ = other.double_;
	}
	return *this;
}

Convert::Convert(std::string str): str_(str)
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
	if (this->str_ == "nan" || this->str_ == "+nan" || this->str_ == "nanf" || this->str_ == "+nanf")
		displayResult(IP, IP, "nanf", "nan");
	else if (this->str_ == "-nan" || this->str_ == "-nanf")
		displayResult(IP, IP, "-nanf", "-nan");
	else if (this->str_ == "inf" || this->str_ == "+inf" || this->str_ == "inff" || this->str_ == "+inff")
		displayResult(IP, IP, "inff", "inf");
	else if (this->str_ == "-inf" || this->str_ == "-inff")
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
	if (this->str_.length() == 0)
	{
		displayResult(IP, IP, IP, IP);
		std::exit(EXIT_FAILURE);
	}
	if (std::isalpha(this->str_[0]) == 1 && this->str_[1] != '\0')
	{
		displayResult(IP, IP, IP, IP);
		std::exit(EXIT_FAILURE);
	}
	if (cntDot(this->str_) > 1)
	{
		displayResult(IP, IP, IP, IP);
		std::exit(EXIT_FAILURE);
	}
}

void	Convert::executeChar()
{
	if (this->str_.length() == 1 && std::isdigit(this->str_[0]) == 0) // アルファベットなどの場合
	{
		this->str_ = std::to_string(this->str_[0]);
	}
	int	tmp = std::atoi(str_.c_str());
	if (std::isprint(tmp))
	{
		this->char_ = static_cast<char>(tmp);
		std::cout << "char: \'" << this->char_ << "\'" << std::endl;
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
		this->int_ = std::stoi(this->str_);
		std::cout << "int: " << this->int_ << std::endl;
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
		this->float_ = std::stof(this->str_);
		std::cout << "float: " << this->float_;
		if (fmodf(this->float_, 1.0f) == 0)
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
		this->double_ = std::stod(this->str_);
		if (fmod(this->double_, 1.0) == 0)
		{
			std::cout << std::fixed;
			std::cout << "double: " << std::setprecision(1) << this->double_ << std::endl;
		}
		else
			std::cout << "double: " << this->double_ << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "double: impossible" << std::endl;
	}
}
