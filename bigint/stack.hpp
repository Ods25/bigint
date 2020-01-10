#ifndef STACK_HPP
#define STACK_HPP
#include "node.hpp"
class Stack
{
	private:
		Node* head;
		Node* tail;
	public:
		Stack();
		void push(int num);
		int pop();
		bool isEmpty();

};



#endif
