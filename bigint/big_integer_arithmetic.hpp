#ifndef BIGINTEGERARITHMETIC_HPP
#define BIGINTEGERARITHMETIC_hPP
#include "arithmetic_expression.hpp"

class BigIntegerArithmetic
{
	private:
		ArithmeticExpression* ae;
		Stack s1;
		Stack s2;
		Stack s3;
	public:
	BigIntegerArithmetic(ArithmeticExpression* a);
	void subtract();
	bool op1IsBigger(std::string o1, std::string o2);	
	void setUp();
	void add();

	std::string showResults();
};
#endif
