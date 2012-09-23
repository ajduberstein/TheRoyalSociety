#ifndef LINKEDLIST_H

#define LINKEDLIST_H

struct Node{
	int data;
	Node* next;
	Node(int x, Node* y) : data(x), next(y){}
};

class TheRoyalSocietyApp;

class LinkedList {
	private:
		Node *root_;
		int num_items_;
	public:
		LinkedList() : root_() {}
		~LinkedList();
		void addNode(int info);
		Node* at(int index);
		void bump();
		void reverse();
		void setLength(int length);
		int length();
};

#endif
