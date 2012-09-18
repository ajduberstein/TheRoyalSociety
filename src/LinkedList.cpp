#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Resources.h"
#include <vector>
#include <string.h>
//#include "TheRoyalSocietyApp.h"

using namespace ci;
using namespace ci::app;
using namespace std;

//TODO ACTIVATE THIS
/*struct Shape{
		float topRightCorner;
		float bottomLeftCorner;
		float radius;
		int sides;
};
*/
struct Node{
	//TODO ACTIVATE THIS Shape shape;
	int data;
	Node* next;
	Node(int x) : data(x){}
}*p;

class LinkedList {
	public:
		//TODO Activate this
		LinkedList(int array[], int arrlen);
		void insertAfter(Node* input_marker, /*Shape*/ int new_instance);
		void remove();
		void at();
		void printList();
		void addToFront(int new_instance);
		void removeNode(int index);
	private:
		Node *root_;
		Node *tail_;
		int num_items_;
		int front_index_;
};

//TODO Activate this
//Credit to SO user Seth Carnegie for this constructor. Code viewable at
//stackoverflow.com/questions/7298781/constructor-for-linkedlist-to-recieve-an-array-c
//I've modified it to work with the node struct above.
LinkedList::LinkedList(int array[], int arrlen)
{
    root_->data = array[0]; //setData method stores the integer at position 0 inside headPtr

    Node *cur = root_;

    for (int i = 0; i < arrlen; ++i)    //for loop to add the integers to the next node
    {
    //    cur->next =  new Node; //creates a new node with the integer value of array position i

    }
}

/**
 * Adds an item to the front of the list.
 *
 */
void LinkedList::addToFront(int new_instance){
	Node *tmp;
	tmp = (Node*)malloc(sizeof(Node));
	tmp->data = new_instance;
	tmp->next = root_;
	root_ = tmp;
}


/**
 * Inserts an item after a specified index.
 * TODO Activate this
 */
void LinkedList::insertAfter(Node* input_marker, /*Shape*/ int new_instance){
//	Node* tmp_p = new Node;
//	tmp_p -> /*shape*/ data = new_instance;
//	tmp_p -> next = input_marker -> next;
}

/**
 * Prints to a string all the items in a linked list
 * 
 */
void LinkedList::printList(){
	Node* cur = root_;
	while(cur != NULL){
		console() << &cur << std::endl;
		cur = cur->next;
	}
}

/**
 * Deletes node from list
 *
 */
void LinkedList::removeNode(int index){

}