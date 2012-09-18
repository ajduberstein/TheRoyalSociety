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
}*p;

class LinkedList {
	public:
		//TODO Activate this
		//LinkedList(const std::vector<Shape>& array);
		//TODO Activate this
		void insertAfter(Node* input_marker, /*Shape*/ int new_instance);
		void remove();
		void at();
		void printList();
		void addToFront(int new_instance);
		void removeNode(int index);
	private:
		Node *root;
		Node *tail;
		int num_items;
		int front_index;
};
//TODO Activate this
//Credit to SO user Seth Carnegie for this constructor. Code viewable at
//stackoverflow.com/questions/7298781/constructor-for-linkedlist-to-recieve-an-array-c
/*I've modified it to work with the node struct above.
LinkedList::LinkedList(const std::vector<Shape>& array){
	root = new Node;
	root->shape=array[0];
	root->next=p;
	//iterate through every pointer
}
*/

/**
 * Adds an item to the front of the list.
 *
 */
void LinkedList::addToFront(int new_instance){
	Node *tmp;
	tmp = (Node*)malloc(sizeof(Node));
	tmp->data = new_instance;
	tmp->next = root;
	root = tmp;
}


/**
 * Inserts an item after a specified index.
 * TODO Activate this
 */
void LinkedList::insertAfter(Node* input_marker, /*Shape*/ int new_instance){
	Node* tmp_p = new Node;
	tmp_p -> /*shape*/ data = new_instance;
	tmp_p -> next = input_marker -> next;
}

/**
 * Prints to a string all the items in a linked list
 * 
 */
void LinkedList::printList(){
}

/**
 * Deletes node from list
 *
 */
void LinkedList::removeNode(int index){
	
}