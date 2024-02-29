#include "ScalarConverter.hpp"

bool ScalarConverter::_isInt(std::string const input)
{
	int n = 0;
	long ln;

	if (input[n] == '-' || input[n] == '+')
			n++;
	while (input[n])
	{
			if (input[n] < '0' || input[n] > '9')
					return (false);
			n++;
	}
	ln = strtol(input.c_str(), NULL, 10);
	if (!input[n] && ln < std::numeric_limits<int>::max() && ln > std::numeric_limits<int>::min())
			return (true);
	return (false);
}

bool ScalarConverter::_isFloat(std::string const input)
{
	int n = 0;
	int point = 0;
	double f;

	if (input[n] == '-' || input[n] == '+')
		n++;
	while (input[n] && input[n] != 'f')
	{
		if (input[n] < '0' || input[n] > '9')
		{
			if (input[n] == '.' && input[n + 1])
				point++;
			else
				return (false);
		}
		n++;
	}
	if (input[n] == 'f' && !input[n + 1] && point == 1)
	{
		f = strtod(input.c_str(), NULL);
		if (f > -std::numeric_limits<float>::max() && f < std::numeric_limits<float>::max())
			return (true);
	}
	return (false);
}

bool ScalarConverter::_isDouble(std::string const input)
{
	int n = 0;
	int point = 0;

	if (input[n] == '-' || input[n] == '+')
			n++;
	while (input[n])
	{
		if (input[n] < '0' || input[n] > '9')
		{
			if (input[n] == '.' && input[n + 1])
				point++;
			else
				return (false);
		}
		n++;
	}
	if (!input[n] && n <= 327 && point == 1)
		return (true);
	return (false);
}

bool ScalarConverter::_floatPseudoLiterals(std::string const input)
{
	return (input == "+inff" || input == "-inff" || input == "nanf");
}

bool ScalarConverter::_doublePseudoLiterals(std::string const input)
{
	return (input == "+inf" || input == "-inf" || input == "nan");
}

std::string ScalarConverter::_inputType(std::string const input)
{
	if (input.empty())
		return "empty";
	if (input.length() == 1 && std::isalpha(input[0]))
		return ("char");
	if (_floatPseudoLiterals(input) || (!_doublePseudoLiterals(input) && _isFloat(input)))
		return ("float");
	if (_doublePseudoLiterals(input) || _isDouble(input))
		return ("double");
	if (_isInt(input))
		return ("int");
	return ("unknown");
}

void ScalarConverter::_displayChar(char const c)
{
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::_displayInt(int const n)
{
	std::cout << "int: " << n << std::endl;
}

void ScalarConverter::_displayFloat(float const f)
{
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << 'f' << std::endl;
}

void ScalarConverter::_displayDouble(double const d)
{
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::_convertChar(std::string const input)
{
	char c;
	c = input[0];
	_displayChar(c);
	_displayInt(static_cast<int>(c));
	_displayFloat(static_cast<float>(c));
	_displayDouble(static_cast<double>(c));
}

void ScalarConverter::_convertInt(std::string const input)
{
	int n;
	n = std::atoi(input.c_str());
	if (n < 0 || n > 127)
		std::cout << "char : impossible" << std::endl;
	else
		_displayChar(static_cast<char>(n));
	_displayInt(n);
	_displayFloat(static_cast<float>(n));
	_displayDouble(static_cast<double>(n));
}

void ScalarConverter::_convertFloat(std::string const input)
{
	float f;
	f = std::strtof(input.c_str(), NULL);
	if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max() || _floatPseudoLiterals(input))
		std::cout << "char: impossible" << std::endl;
	else
		_displayChar(static_cast<char>(f));
	if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max() || _floatPseudoLiterals(input))
		std::cout << "Int: impossible" << std::endl;
	else
		_displayInt(static_cast<int>(f));
	_displayFloat(f);
	_displayDouble(static_cast<double>(f));
}

void ScalarConverter::_convertDouble(std::string const input)
{
	double d;
	d = std::strtod(input.c_str(), NULL);
	if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max() || _doublePseudoLiterals(input))
		std::cout << "char: impossible" << std::endl;
	else
		_displayChar(static_cast<char>(d));
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max() || _doublePseudoLiterals(input))
		std::cout << "Int: impossible" << std::endl;
	else
		_displayInt(static_cast<int>(d));
	_displayFloat(static_cast<float>(d));
	_displayDouble(d);
}

void ScalarConverter::convert(std::string const input)
{
	std::string type;

	type = _inputType(input);
	if (type == "char")
		_convertChar(input);
	else if (type == "int")
		_convertInt(input);
	else if (type == "float")
		_convertFloat(input);
	else if (type == "double")
		_convertDouble(input);
	else if (type == "empty")
		std::cout << "Empty input has no type" << std::endl;
	else
		std::cout << "Type is unknown" << std::endl;
}

ScalarConverter::ScalarConverter()
{
	std::cout << GREEN << "Default ScalarConverter" << RESET << " has been created" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const& src)
{
	(void)src;
	std::cout << GREEN << "Copy ScalarConverter " << RESET << " has been created" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << GREEN << "ScalarConverter " << RESET << " has been destroyed" << std::endl;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const& src)
{
	(void)src;
	return *this;
}

