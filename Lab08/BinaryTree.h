#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

class BinaryTree{
private:
	struct TreeNode {
			int key;
			TreeNode* left;
			TreeNode* right;
			TreeNode* parent;
			/*TreeNode(int k){
				key = k;
				left = nullptr;
				right = nullptr;
				parent = nullptr;
			}*/
	};
	TreeNode* root;
	
	void transplant(TreeNode*, TreeNode*);
	//Private is for private verssion of these functions
	TreeNode* Psuccessor(int);
	TreeNode* Pmaximum(TreeNode*);
	TreeNode* Pminimum(TreeNode*);
	TreeNode* Psearch(int);
	void PinOrder(TreeNode*);	
	void Pprint(TreeNode*);

public:
	//Needed for all classes (Runn of 3)
	BinaryTree();
	BinaryTree(const BinaryTree&);
	BinaryTree& operator=(const BinaryTree&);
	~BinaryTree();
	
	//These functions are for recusively adding/delteing the whole list these will work completely with memory adresses
	//Takes the root and then 
	void copyTree(TreeNode*);
	void removeTree(TreeNode*);


	//Only public functions
	void insert(int);
	void inOrder();
	void remove(int);//TODO
	void print();
	
	//Public verssions of private functions
	int successor(int);
	int maximum();
	int minimum();
	bool search(int);
};

#endif
