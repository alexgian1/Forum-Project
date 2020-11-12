#include <string>
#include "linkedList.h"

struct BTNode{
	public:
		BTNode *lchild;
		BTNode *rchild;
		std::string content;
		LinkedList postList;
};

class BinaryTree{
	private:
		BTNode *root;
		
		//recursive functions that are called by public functions
		void printInOrderREC(BTNode*);
		void enhanceREC(BTNode*);
		void deleteREC(BTNode*);

		BTNode* createNode(std::string);  //arbitrary function,create node,return its address
		void insertAfter(BTNode*, std::string);
		BTNode* search(BTNode*, std::string);
		BTNode *getRoot() const;
		void insertPost(Post&);
		
	public:
		BinaryTree(Thread&);
		~BinaryTree();
		
		void printInOrder();
		void enhance(BinaryTree&);
};
