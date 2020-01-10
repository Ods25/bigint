#include "expression_reader.hpp"
#include "big_integer_arithmetic.hpp"
#include <string>
#include <cstring>
#include <cstdio>
#include <sstream>
int main() // 'Main will be a one-liner'
{
	std::string fn = "expressions.txt";
	ExpressionReader er;
	er.readExpressions(fn);
	std::string expressionString  = er.toString();	
		
	
	std::istringstream inp(expressionString);
	std::string op1;
	std::string sign;
	std::string op2;
	while(std::getline(inp,op1, ' '))
	{
		//std::cout <<"op1:"<< op1 << std::endl;
		while(std::getline(inp,sign, ' '))
		{
			//std::cout <<"sign: "<< sign << std::endl;	
			while(std::getline(inp,op2, '\n'))
			{
				//std::cout <<"op2: "<< op2 << std::endl;
				break;
			}
			break;
		}

		//make sign into char
		char sig = sign[0];
		ArithmeticExpression* ae = new ArithmeticExpression(op1,op2,sig);
		BigIntegerArithmetic bia(ae);
		bia.setUp();
		//execution occurs here
		if(sig=='-')
			bia.subtract();
		if(sig=='+')
			bia.add();
		std::cout << bia.showResults();

	}


	return 0;
}
