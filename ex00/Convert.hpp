#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <string>

#define ND "Non displayable"
#define IP "impossible"

class Convert
{
public:
	Convert();
	~Convert();
	Convert(Convert const &other);
	Convert &operator=(Convert const &other);

	Convert(std::string str);
	void	run();

	void	exePseudoLiteral();
	void	displayResult(std::string c, std::string i, std::string f, std::string d);
	void	ensurePossible();
	std::size_t	cntDot(std::string str);

	void	executeChar();
	void	executeInt();
	void	executeFloat();
	void	executeDouble();

private:
	std::string	_str;
	char		_char;
	int			_int;
	float		_float;
	double		_double;
};

#endif /* CONVERT_HPP */
