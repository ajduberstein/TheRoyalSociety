#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Resources.h"

using namespace ci;
using namespace ci::app;
using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int x) : data(x), next(NULL){}
};

class LinkedList {
	public:
		LinkedList() : root_(NULL) {}
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

/*Credit to 
 *http://codereview.stackexchange.com/questions/4628/circular-linked-list-c
 *for circular linked list destructor and the insertion method 
 */
LinkedList::~LinkedList(){
	if (root_){
		Node* tmp = root_;
		while (tmp->next!=root_){
			Node* t = tmp;
			tmp = tmp->next;
			delete(t);
		}
		delete tmp;
		root_ = NULL;
	}
}

void LinkedList::addNode(int info){
	Node* t = new Node(info);
	if (root_ == NULL){
		t->next = t;
		root_ = t;
		return;
	}
	Node* tmp = root_;
	while(tmp->next != root_){
		tmp = tmp->next;
	}
	tmp->next = t;
	t->next = root_;
}

void LinkedList::reverse(){


}

Node* at(int index){


}
