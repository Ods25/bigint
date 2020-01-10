#ifndef OPERAND_HPP
#define OPERAND_HPP
#include "stack.hpp"
#include <string>
class Operand
{
	private:
		std::string val;
	public:
		Operand(std::string str);
		bool isNegative();
		std::string getValue();
		int getLengthOfString();
		void pad(int num);
		void setValue(std::string str);

};
#endif
