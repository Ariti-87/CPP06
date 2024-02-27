#ifndef DEF_SCALARCONVERTER
#define DEF_SCALARCONVERTER

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define VIOLET "\033[35m"
#define GREEN "\033[32m"
#define LGREEN "\033[92m"
#define BLUE "\033[34m"
#define WHITE "\033[37m"
#define BLACK "\033[30m"
#define CYAN "\033[36m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cstdlib>

class ScalarConverter
{
public:
	static void convert(std::string const input);

private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const& src);
	~ScalarConverter();
	ScalarConverter &operator=(ScalarConverter const& src);

	static bool _isInt(std::string const input);
	static bool _isFloat(std::string const input);
	static bool _isDouble(std::string const input);
	static bool _floatPseudoLiterals(std::string const input);
	static bool _doublePseudoLiterals(std::string const input);
	static std::string _inputType(std::string const input);

	static void _convertChar(std::string const input);
	static void _convertInt(std::string const input);
	static void _convertFloat(std::string const input);
	static void _convertDouble(std::string const input);
	static void _displayChar(char const c);
	static void _displayInt(int const n);
	static void _displayFloat(float const f);
	static void _displayDouble(double const d);

};

#endif

