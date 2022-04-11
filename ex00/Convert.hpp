#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <string>

class Convert
{
public:
	Convert();
	~Convert();
	Convert(Convert const &other);
	Convert &operator=(Convert const &other);

	Convert(std::string str);
	void	run();

	void	ensurePossible();

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
