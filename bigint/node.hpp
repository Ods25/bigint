#ifndef NODE_HPP
#define NODE_HPP
class Node
{
	private:
		int data;
		Node* next;
	public:
		Node (int data,Node* next = nullptr);
		int getValue ();
		Node* getNext();
		void setNext (Node* next);
};
#endif
