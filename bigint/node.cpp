#include "node.hpp"

Node::Node (int data, Node* next)
{
	this->data = data;
	this->next = next;
}

int Node::getValue ()
{
	return this->data;
}

Node* Node::getNext ()
{
	return this->next;
}

void Node::setNext (Node* next)
{
	this->next = next;
}
