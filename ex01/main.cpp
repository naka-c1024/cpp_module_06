#include "Data.hpp"
#include <iostream>

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t row)
{
	return reinterpret_cast<Data*>(row);
}

int	main(void)
{
	Data	before = {'a', 42, 'c'};
	std::cout << "before ptr: " <<  &before << std::endl;
	std::cout << "data info: " << before.a << " " << before.b << " " << before.c << std::endl;

	uintptr_t	num;
	num = serialize(&before);
	std::cout << "serialize num: " << num << std::endl;

	Data	*after = deserialize(num);
	std::cout << "deserialize ptr: " << after << std::endl;
	std::cout << after->a << " " << after->b << " " << after->c << std::endl;
	return 0;
}
