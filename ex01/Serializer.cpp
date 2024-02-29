#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

Serializer::Serializer()
{
	std::cout << GREEN << "Default Serializer" << RESET << " has been created" << std::endl;
}

Serializer::Serializer(Serializer const& src)
{
	(void)src;
	std::cout << GREEN << "Copy Serializer " << RESET << " has been created" << std::endl;
}

Serializer::~Serializer()
{
	std::cout << GREEN << "Serializer " << RESET << " has been destroyed" << std::endl;
}

Serializer & Serializer::operator=(Serializer const& src)
{
	(void)src;
	return *this;
}

