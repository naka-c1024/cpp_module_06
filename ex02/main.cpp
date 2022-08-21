#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base * generate(void)
{
	std::srand(time(nullptr));
	int	random_num = rand() % 3;
	Base	*rtn;
	switch (random_num)
	{
	case 0:
		rtn = new A();
		break;
	case 1:
		rtn = new B();
		break;
	case 2:
		rtn = new C();
		break;
	}
	std::cout << "generate class num: " << random_num << std::endl;
	return rtn;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "class name is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "class name is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "class name is C" << std::endl;
	else
		std::cout << "class name is unknown" << std::endl;
}

void identify(Base& p)
{
	int	class_num;
	try
	{
		A class_type = dynamic_cast<A&>(p);
		class_num = 0;
	}
	catch(const std::bad_cast& e){}
	try
	{
		B class_type = dynamic_cast<B&>(p);
		class_num = 1;
	}
	catch(const std::bad_cast& e){}
	try
	{
		C class_type = dynamic_cast<C&>(p);
		class_num = 2;
	}
	catch(const std::bad_cast& e){}

	switch (class_num)
	{
	case 0:
		std::cout << "class name is A" << std::endl;
		break;
	case 1:
		std::cout << "class name is B" << std::endl;
		break;
	case 2:
		std::cout << "class name is C" << std::endl;
		break;
	default:
		std::cout << "class name is unknown" << std::endl;
	}
}

int	main(void)
{
	Base	*rdm = generate();
	identify(rdm);
	identify(*rdm);
	delete rdm;
	return 0;
}
