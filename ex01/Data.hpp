#ifndef DATA_HPP
#define DATA_HPP

#include <cstdint>

typedef struct{
	char	a;
	int		b;
	char	c;
}Data;

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif /* DATA_HPP */
