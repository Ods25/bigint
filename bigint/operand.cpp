#include "operand.hpp"
Operand::Operand(std::string str)
{
	this->val = str;
}
bool Operand::isNegative()
{

	if(this->val[0] == '-')
		return true;	
	return false;
}
std::string Operand::getValue()
{
	return this->val;
}
int Operand::getLengthOfString()
{
	return this->val.length();
}
void Operand::pad(int num)
{
	this->val.insert(this->val.begin(),num,'0');
}
void Operand::setValue(std::string str)
{
	this->val = str;
}
