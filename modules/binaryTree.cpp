#include <iostream>
#include "binaryTree.h"
using namespace std;

BinaryTree::BinaryTree(Thread &t){
	root = new BTNode;
	root->lchild = NULL;
	root->rchild = NULL;
	root->content = "";
	//cout << "Constructing a BinaryTree" << endl;
	Post *posts = t.getPosts();

	for(int i=0;i<5;i++){  //5 posts per thread
		insertPost(posts[i]);
	}
}

BinaryTree::~BinaryTree(){
	deleteREC(root);
	//cout << "Destroying a BinaryTree" << endl;
}

void BinaryTree::deleteREC(BTNode *node){
	if (node==NULL) return;
	deleteREC(node->lchild);
	deleteREC(node->rchild);
	delete node;
}

BTNode* BinaryTree::createNode(string text){   //arbitrary function to create a new node and return its address
	BTNode *node = new BTNode;
	node->content = text;
	node->lchild = NULL;
	node->rchild = NULL;
	return node;
}

BTNode* BinaryTree::search(BTNode *node, string text){
	//cout << "Searching for " << text << endl;
	if (root->content == "") return NULL;  //empty tree
	if (node == NULL) return NULL;  //reached the end
	if (text.compare(node->content) == 0) return node;
	else{
		if (text.compare(node->content) < 0) {
				//cout << "Going left"  << endl;
				return search(node->lchild, text);
		}
		else if (text.compare(node->content) > 0) {
			//cout << "Going right"  << endl;
			return search(node->rchild, text);
		}
	}
}

void BinaryTree::insertAfter(BTNode *node, string text){
	//cout << "Inserting " << text << endl;
	if (root->content=="")
	{
		root->content = text;   //if the tree is empty insert root
	}
	else{
		if (text.compare(node->content) < 0)   //alphabetical order is lower
		{
			if (node->lchild == NULL){  //final node so insert it
				node->lchild = createNode(text);
				//cout << "Node inserted at " << node->lchild << endl;
				return;
			}
			return insertAfter(node->lchild,text); //not final node so continue
		}
		else   //alphabetical order is higher or the same
		{
			if (node->rchild == NULL){    //final node so insert it
				node->rchild = createNode(text);
				//cout << "Node inserted at " << node->rchild << endl;
				return;
			}
			return insertAfter(node->rchild,text); //not final node so continue
		}
	}
}

BTNode* BinaryTree::getRoot() const { return root; }

void BinaryTree::insertPost(Post &p){
	BTNode* curAuthor = search(root,p.get_author());  //search for the author in the tree
	if (curAuthor == NULL){  //if author not in the tree insert him
		insertAfter(root,p.get_author());
	}
	curAuthor = search(root,p.get_author());  //get the node that contains the author of the current post
	curAuthor->postList.insertLast(&p);   //insert the post
}

void BinaryTree::printInOrderREC(BTNode* node) {
	if (node == NULL) return; //end of tree
	printInOrderREC(node->lchild);  //go left recursively

	cout << node->content << " posts: " << endl;   //print author and his posts
	node->postList.print(); 

	printInOrderREC(node->rchild);  //go right recursively
}

void BinaryTree::printInOrder(){
	printInOrderREC(this->getRoot());
}

void BinaryTree::enhanceREC(BTNode *node){
	if (node == NULL) return;
	enhanceREC(node->lchild);
	if (search(root,node->content) == NULL){  //node does not exist in the first tree
		insertAfter(root,node->content);
	}
	BTNode *curNode = search(root,node->content); //get the node with the current author
	//ADD POSTLIST FROM NODE TO CURNODE
	curNode->postList.addList(node->postList);
	enhanceREC(node->rchild);
}

void BinaryTree::enhance(BinaryTree &bt2){
	enhanceREC(bt2.root);
}

