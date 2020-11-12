#include "forum.h"

struct LLNode{
	public:
		LLNode *next;
		Post *postPtr;
};

class LinkedList{
	private:
		LLNode *first;
		LLNode *last;

		LLNode* createNode(Post*);
		LLNode* getNode(int) const;
		LLNode* getLast() const;
		LLNode* getFirst() const;
		
	public:
		LinkedList();
		~LinkedList();
		
		void insertLast(Post*);
		void print() const;
		void addList(LinkedList&);  //add another list at the end
};
