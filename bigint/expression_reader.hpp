#ifndef EXPRESSIONREADER_HPP
#define EXPRESSIONREADER_HPP
#include <iostream>
#include <fstream>
class ExpressionReader
{
	private:
		std::ifstream* file;
		std::string expressions;
	public:
		void readExpressions(std::string fn);
		std::string toString();
		friend std::ostream& operator << (std::ostream& ostr, const ExpressionReader &e);
};
#endif
