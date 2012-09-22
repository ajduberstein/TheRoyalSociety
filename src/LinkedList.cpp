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
