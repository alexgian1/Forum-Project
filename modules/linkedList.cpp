#include <iostream>
#include "linkedList.h"
using namespace std;

LinkedList::LinkedList(){
	first = new LLNode;
	first->next = NULL;
	first->postPtr = NULL;
	last = first;
	//cout << "Constructing LinkedList" << endl;
}

LinkedList::~LinkedList(){
	while (first != last){
		LLNode *curNode = first;
		while (curNode->next != last) curNode = curNode->next;  //reach the node before the last
		delete last;
		last = curNode;
	}
	delete first;
	//cout << "Destroying LinkedList" << endl;
}

LLNode* LinkedList::getLast() const { return last; }

LLNode* LinkedList::getFirst() const { return first; }

LLNode* LinkedList::createNode(Post* post){  //create a new node and return its address
	LLNode *node = new LLNode;
	node->next = NULL;
	node->postPtr = post;
	return node;
}

LLNode* LinkedList::getNode(int index) const{
	LLNode* curNode = first;
	while (curNode != NULL && index != 0){  //run the list until the end is reached or index becomes 0 which means node found
		index--;
		curNode = curNode->next; 
	}
	return curNode;
}

void LinkedList::insertLast(Post* post){
	//cout << "Inserting post " << post->get_id() << endl;

	if (first->postPtr == NULL) first->postPtr = post;  //list is empty, last node remains the first

	else{   //list not empty
		last->next = createNode(post);
		last = last->next;
	}

}

void LinkedList::print() const{
	cout << "---------------------------------" << endl;
	LLNode* curNode = first;

	while(curNode != last){

		curNode->postPtr->print();   //print the post of every node until the last

		curNode = curNode->next;
	}
	last->postPtr->print();   //print the last
	cout << "---------------------------------" << endl;
}

void LinkedList::addList(LinkedList &list){
	LLNode *curNode = list.getFirst();
	while (curNode != list.getLast()){ //for every post in the secondary list until the last insert it in the primary list
		insertLast(curNode->postPtr);
		curNode = curNode->next;
	}
	insertLast(list.getLast()->postPtr); //insert the last post
}

/*
int main(){
	LinkedList list;
	Post p1,p2,p3,p4;

	list.insertLast(&p1);
	list.insertLast(&p2);
	list.insertLast(&p3);
	list.insertLast(&p4);

	list.print();

}
*/
