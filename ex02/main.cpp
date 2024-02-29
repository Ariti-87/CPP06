#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base * generate(void)
{
	srand(time(NULL));
	int rand = std::rand() % 3;
	switch (rand)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;

}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch(const std::exception& bc)
	{
		// std::cerr << "Not A" << bc.what() << std::endl;
	}

	try
	{
		dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch(const std::exception& bc)
	{
		// std::cerr << "Not B" << bc.what() << std::endl;
	}

	try
	{
		dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch(const std::exception& bc)
	{
		// std::cerr << "Not C" << bc.what() << std::endl;
	}
	std::cout << "Unknown" << std::endl;

}

int main()
{
	Base* p = generate();
	identify(p);
	identify(*p);
	delete p;
	return 0;
}
