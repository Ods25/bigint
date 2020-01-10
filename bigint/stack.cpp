#include "stack.hpp"
Stack::Stack()
{
	this->head = nullptr; //initialize head to null
	this->tail = nullptr; // initialize tail to null
}
void Stack::push(int num)
{
	Node* n = new Node(num);//new node is created, num is data
	if(this->isEmpty()) //if stack is empty
	{
		this->head = n;
		this->tail = n; // then both the head and the tail are the new node
	}
	else //else then stack is not empty
	{
		n->setNext(this->head); //node's next pointer is set to the head
		this->head= n; //stack's head pointer is set to the node
	}
}
int Stack::pop()
{
	Node *nTemp = this->head; //create temp pointer to node set to be popped
	int data = nTemp->getValue(); //get value of node
	if(this->head == this->tail) //if the head is the tail as well
		this->tail = nullptr; // make the tail nullptr
	this->head = this->head->getNext(); //the head is now the next element
	nTemp->~Node(); //explicit destructor call to make sure node is destroyed.
	return data; // data is returned.
}

bool Stack::isEmpty()
{
	if(this->head == nullptr and this->tail == nullptr) //if stack is empty
		return true;
	else
		return false;
}
