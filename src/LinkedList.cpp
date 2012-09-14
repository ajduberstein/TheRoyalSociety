#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Resources.h"
//#include "TheRoyalSocietyApp.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class LinkedList : public AppBasic {
	public:
		void insertAfter(Node* input_marker, Rectangle new_rect);
		void remove();
		void at();
		void LinkedList(kListLength);
	private:
		struct Node{
			int Node* next_;
			Rectangle data_;
		};
		static const int kListLength=10;
		Node list[kListLength];
};



void LinkedList::insertAfter(Node* input_marker, Rectangle new_rect){
	Node* tmp_p = new Node;
	tmp_p -> data_ = new_rect;
	tmp_p -> next_ = input_marker -> next_;
}
