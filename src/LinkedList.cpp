#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Resources.h"
#include "LinkedList.h"

using namespace ci;
using namespace ci::app;
using namespace std;


/*Credit to 
 *http://codereview.stackexchange.com/questions/4628/circular-linked-list-c
 *for circular linked list destructor and the insertion method.
 *Code is slightly modified for my specific implementation of a node.
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
	if (num_items_ < 0)
		num_items_ = 0;
	num_items_++;
	Node* t = new Node(info, NULL);
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

void LinkedList::bumpForward(){
	if (root_ != NULL){
		Node* old_root = root_;
		//Traverse the list to find the last node
		Node* tmp = root_;
		Node* last;
		while (true){
			tmp = tmp->next;
			if (tmp->next == root_){
				last = tmp;
				break;
			}
		}
		//Swap the last node and the first node
		Node* temp = root_;
		root_ = last;
		last = temp;
	}
	else {
		console() << "ALERT -- Tried to bump a null list" << std::endl;
	}
}

void bumpBack(){

}

void LinkedList::reverse(){

}

Node* LinkedList::at(int index){
		int i = 0;
		Node* tmp = root_;
		while (tmp->next!=root_ && i < index){
			Node* t = tmp;
			tmp = tmp->next;
			i++;
		}
		return tmp;
}

void LinkedList::setLength(int length){
	num_items_ = length;
}

int LinkedList::length(){
	if (num_items_ < 0)
		num_items_ = 0;
	return num_items_;
}