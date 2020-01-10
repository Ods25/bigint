#include "expression_reader.hpp"

void ExpressionReader::readExpressions(std::string fn)
{
	std::string ln;
	//
	this->file = new std::ifstream(fn);
	if(this->file->is_open())
	{
		while(getline(*this->file,ln))
		{

			this->expressions.append(ln);
			this->expressions.append("\n");
		}

		this->file->close();
	}
	else
	{
		std::cout << "ERROR" << std::endl;
	}

	

	//std::cout << "THIS IS LN[0]" << this->expressions[0] << std::endl;

	
}


std::string ExpressionReader::toString()
{
	return this->expressions;
}

std::ostream& operator << (std::ostream& ostr, const ExpressionReader &e)
{
	ostr << e.expressions;
	return ostr;
}

