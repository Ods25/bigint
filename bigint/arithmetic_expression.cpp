#include "arithmetic_expression.hpp"

ArithmeticExpression::ArithmeticExpression(std::string str1, std::string str2, char str3)
{
	this->o1 = new Operand(str1);
	this->o2 = new Operand(str2);
	this->op = str3;
	int len1 = o1->getLengthOfString();
	int len2 = o2->getLengthOfString(); 
	int pad;
	if(len1 != len2)
	{
		if(len1 > len2)
		{	
			pad = len1 - len2;
			o2->pad(pad);
		}
		if(len2 > len1) 
		{
			pad = len2 - len1;	
			o1->pad(pad);	
		}
	}
}

Operand *ArithmeticExpression::getOp1()
{

	return this->o1;
}	

Operand *ArithmeticExpression::getOp2()
{
	return this->o2;
}

char ArithmeticExpression::getSign()
{
	return this->op;
}


std::ostream& operator << (std::ostream& ostr, const ArithmeticExpression &a)
{
	ostr << a.o1->getValue() << " " << a.o2->getValue() << " " << a.op;	
	return ostr;	
}
