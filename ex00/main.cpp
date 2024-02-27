#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "this program take 1 argument" << std::endl;
		return 1;
	}
	else
	{
		std::string str(argv[1]);
		ScalarConverter::convert(str);
	}
	return 0;
}
