#ifndef LINKEDLIST_H

#define LINKEDLIST_H

struct Node{
	int data;
	Node* next;
	Node(int x, Node* y) : data(x), next(y){}
};

class TheRoyalSocietyApp;

class LinkedList {
	public:
		//TODO Implement constructor
		LinkedList() : root_() {}
		~LinkedList();
		void addNode(int info);
		void remove(int info);
		Node* at(int index);
		void reverse();
	private:
		Node *root_;
		Node *tail_;
		int num_items_;
		int front_index_;
};

#endif
