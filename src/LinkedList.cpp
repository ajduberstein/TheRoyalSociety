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

class LinkedList : public AppBasic {
	public:
		//TODO Activate this
		LinkedList(const std::vector<Shape>& array);
		void insertAfter(Node* input_marker, Shape new_instance);
		void remove();
		void at();
		string LinkedList::toString();
	private:
		Node *root;
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

void LinkedList::addToFront(int new_instance){
	node *tmp;
	tmp = (node*)malloc(sizeof(node));
	tmp->data = info;
	tmp->next = root;
	root = temp;
}


/**
 * TODO Activate this
 *
 */
void LinkedList::insertAfter(Node* input_marker, /*Shape*/ int new_instance){
	Node* tmp_p = new Node;
	tmp_p -> /*shape*/ current = new_instance;
	tmp_p -> next = input_marker -> next;
}

string LinkedList::toString(){
	root = new Node;
	root->shape=array[0];
	root->next=p;
}