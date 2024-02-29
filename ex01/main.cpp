#include "Serializer.hpp"

int main() {
	Data data;
	data.nb = 42;

	uintptr_t serializedData = Serializer::serialize(&data);
	std::cout << "Data sérialisée : " << serializedData << std::endl;

	Data* deserializedData = Serializer::deserialize(serializedData);
	std::cout << "Data désérialisée : " << deserializedData->nb << std::endl;

	if (deserializedData == &data)
		std::cout << "Les pointeurs sont égaux." << std::endl;
	else
		std::cout << "Les pointeurs ne sont pas égaux." << std::endl;
	return 0;
}
