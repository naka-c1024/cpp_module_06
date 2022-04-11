#include "Convert.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "You can enter only one parameter." << std::endl;
		return 0;
	}
	Convert obj(argv[1]);
	obj.run();
	return 0;
}
