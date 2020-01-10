#ifndef ARITHMETIC_EXPRESSION_HPP
#define ARITHMETIC_EXPRESSION_HPP
#include "operand.hpp"
#include <sstream>
class ArithmeticExpression
{
	private:
		//holds two operands and an operator
		Operand* o1;
		Operand* o2;
		char op;
	public:
		Operand *getOp1();
		Operand *getOp2();
		char getSign();
		ArithmeticExpression(std::string str1, std::string str2, char str3);
		friend std::ostream& operator << (std::ostream& ostr, const ArithmeticExpression &a);	
};
#endif
