#ifndef DATA_HPP
#define DATA_HPP

#include <cstdint>

typedef struct{
	char	a; // 1byte
	int		b; // 4byte
	char	c; // 1byte
}Data;

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif /* DATA_HPP */
