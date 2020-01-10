#include "big_integer_arithmetic.hpp"
#include <iostream>
#include <cstdlib>
BigIntegerArithmetic::BigIntegerArithmetic(ArithmeticExpression* a)
{
 this->ae = a;
}


void BigIntegerArithmetic::subtract()
{
	bool flip;
	bool carryflag;

	if(op1IsBigger(this->ae->getOp1()->getValue(),this->ae->getOp2()->getValue()))	
	{
		flip = false;
	}
	else
	{
		flip = true;
	}
	if(flip == false)
	{
		//if(carryflag == true and (this->s1.isEmpty() and this->s2.isEmpty()))
		carryflag = false;
		while(!this->s1.isEmpty() and !this->s2.isEmpty())
		{

			int s1Popped =this->s1.pop();
		        int s2Popped =this->s2.pop();	
			if(carryflag == true)
			{
				--s1Popped;
				carryflag = false;
			}
			if(s1Popped < s2Popped)
			{
				carryflag = true;
				s1Popped += 10;
			}
			int result = s1Popped - s2Popped;
			
			if(!this->s1.isEmpty() and !this->s2.isEmpty() and result !=0 )
				this->s3.push(result);
		}
		int topOfStack = s3.pop();
		if( topOfStack != 0)
			s3.push(topOfStack);
		//	this->s3.push(1);
	}

	if(flip == true)
	{
		carryflag = false;
		while(!this->s1.isEmpty() and !this->s2.isEmpty())
		{

			int s1Popped =this->s1.pop();
		        int s2Popped =this->s2.pop();	
			//std::cout << "s1 before: "<< s1Popped<<std::endl;
			//std::cout <<"s2 before: " << s2Popped<<std::endl;
			
			if(carryflag == true)
			{
				--s2Popped;
				carryflag = false;
			}
			if(s1Popped > s2Popped)
			{
				carryflag = true;
				s2Popped += 10;
			}
			int result = s2Popped - s1Popped;
			//std::cout << "Pushing on to stack3: "<<result << " = " << s2Popped << "-" << s1Popped<< std::endl;
			if(!this->s1.isEmpty())
				this->s3.push(result);
			else
				this->s3.push((result * -1));
		} // now since flip equalled true, the result will certainly be negative.
		int topOfStack = s3.pop();
		if(topOfStack ==0)
			topOfStack = s3.pop();
		s3.push( (abs(topOfStack) * -1 ) );
	}

}


bool BigIntegerArithmetic::op1IsBigger(std::string o1, std::string o2)
{
	std::string::size_type sz;
	if(o1.length() > o2.length())
		return true;
	else if( std::stoi(o1.substr(0,1),&sz) >= std::stoi(o2.substr(0,1),&sz) )
		return true;
	else 
		return false;
}
void BigIntegerArithmetic::setUp()
{
	for(int i =1; i<3; ++i)
	{
		std::string op;
		switch(i)
		{
			case 1:
				op = this->ae->getOp1()->getValue();	
				break;
			case 2:
				op= this->ae->getOp2()->getValue();

		}
		for(std::string::size_type j =0; j<op.size(); ++j)
		{
			std::string::size_type sz;
			int toBePushed = std::stoi(op.substr(j,1),&sz);
			switch(i)
			{
				case 1:
					this->s1.push(toBePushed);
					break;
				case 2:
					this->s2.push(toBePushed);
			}
			//std::cout <<"num : "<<i<<" : "<<toBePushed<<std::endl;
		}
		
	}
}
void BigIntegerArithmetic::add()
{
	bool carryflag = false;
	while(!this->s1.isEmpty() and !this->s2.isEmpty())
	{

		int result = this->s1.pop() + this->s2.pop();
		if(carryflag == true)
		{
			++result;
			carryflag = false;
		}
		if(result >= 10)
		{
			carryflag = true;
			result = result - 10;
		}
		this->s3.push(result);
	}
	if(carryflag == true and (this->s1.isEmpty() and this->s2.isEmpty()))
		this->s3.push(1);

}


std::string BigIntegerArithmetic::showResults()
{

	std::string resultant;
	while(!this->s3.isEmpty())
	{
		resultant += std::to_string(this->s3.pop());
	}
	return  "     "+this->ae->getOp1()->getValue() + "\n    "+this->ae->getSign() + this->ae->getOp2()->getValue()+ "\n    " + resultant+"\n\n";
}	
