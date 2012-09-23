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

/**
 * Appends a node to the circular list with the given data.
 */
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

/**
 * Moves all nodes one space forward (tail becomes head).
 */
void LinkedList::bump(){
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


/**
 * Credit to
 * http://datastructuresblog.wordpress.com/2007/03/10/reversing-a-circular-single-linked-list-using-pointers/
 * Slightly modified--the post's pointers weren't working for my code.
 */
void LinkedList::reverse()
{
  Node* tmp = NULL;
  Node* cur = root_;
  Node* next;
  while (cur != NULL)
  {
    next = cur->next; 
    cur->next = tmp;
    tmp = cur;
    cur = next;
    if (cur == root_)
    {
      break;
    }
  }
  root_->next = tmp;
  root_ = tmp;
}

/**
 * Retrieves the particular index of the list
 */
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


/**
 * Sets length
 */
void LinkedList::setLength(int length){
	num_items_ = length;
}

/**
 * Gets length
 */
int LinkedList::length(){
	if (num_items_ < 0)
		num_items_ = 0;
	return num_items_;
}