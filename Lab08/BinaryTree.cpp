#include "BinaryTree.h"

//Defualt constructor
BinaryTree::BinaryTree(){
	root = nullptr;
}

//Copy constructor TODO
BinaryTree::BinaryTree(const BinaryTree& T){
	if(!T.root){
		root=nullptr;
	}else{
		copyTree(T.root);
	}
}

//= operator
BinaryTree& BinaryTree::operator=(const BinaryTree& T){
	if(&T == this)
		return *this;
	
	if(root)
		removeTree(root);
	
	if(!T.root){
		root = nullptr;
	}else{
		copyTree(T.root);
	}
	return *this;
}

//Deconstructor
BinaryTree::~BinaryTree(){
	removeTree(root);
}

//Takes the Root and recusively makes (this) be the same list as the given
void BinaryTree::copyTree(TreeNode* T){
	if(T){
		this->insert(T->key);
		copyTree(T->right);
		copyTree(T->left);
	}
}

//Starts at a given Node and deletes everything under it
void BinaryTree::removeTree(TreeNode* T){
	if(T){
		removeTree(T->right);
		removeTree(T->left);
		delete T;
	}
}

//Used to insert a key in the correct spot with a given k key
void BinaryTree::insert(int k){
	//TODO TreeNode* newNode(k); this is breaking for some reason
	TreeNode* newNode;
	newNode->key = k;
	newNode->left = nullptr;
	newNode->right = nullptr;
	newNode->parent = nullptr;
	if(!root){
		root = newNode;
		return;
	}
	
	TreeNode* cursor = root;
	TreeNode* prev = root;
	while(cursor){
		if(cursor->key > newNode->key){
			prev = cursor;
			if(!cursor->left){
				prev->left = newNode;
				newNode->parent = prev;
				return;
			}
			cursor = cursor->left;
		}else{
			prev = cursor;
			if(!cursor->right){
				prev->right = newNode;
				newNode->parent = prev;
				return;
			}
			cursor = cursor->right;
		}
	}
}

//Wrapper function for PinOrder
void BinaryTree::inOrder(){
	PinOrder(root);
	std::cout<<std::endl;
}


//In order printing / prints the binary tree in order, recursivly prints all elements starting at node T
void BinaryTree::PinOrder(TreeNode* T){
	if(T){
		PinOrder(T->left);
		std::cout<< T->key <<" ";
		PinOrder(T->right);
	}
}

//Wrapper function for Pprint
void BinaryTree::print(){
	Pprint(root);
	std::cout<<std::endl;
}

//Prints out the tree as it is internally
void BinaryTree::Pprint(TreeNode* T){
	/*TreeNode* cursor = T;
	int j=1;
	for(int i=1; cursor; i*=2){
		if( j == i ){
			std::cout<<std::endl;
		}
		j++;

	}*/
	if(T){
		std::cout<< T->key <<" ";
		Pprint(T->left);
		Pprint(T->right);	
	}
}

//This returns the largest number in the tree
int BinaryTree::maximum(){
	try{
	return Pmaximum()->key;
	}catch(std::string s){
		throw s;
	}catch(...){
		std::string UE = "Unkown Error";
		throw UE;
	}
}

//Runs all the ways down the right side of the tree where the highest number lives 
TreeNode* BinaryTree::Pmamimum(){
	if(!root){
		std::string s = "Error: No root!";
		throw s;
	}
	TreeNode* cursor = root;
	while(cursor->right){
		cursor=cursor->right;
	}
	return cursor;
}

//This returns the smallest number in the tree
int BinaryTree::minimum(){
	try{
		return Pminimum()->key;
	}catch(std::string s){
		throw s;
	}catch(...){
		std::string UE = "Unknown Error";
		throw UE;
	}
}

//Runs all the way down the left sid eof the tree, where the smallest number lives
TreeNode* BinaryTree::Pminimum(){
	if(!root){
		std::string s = "Error: No root!";
		throw s;
	}
	TreeNode* cursor = root;
	while(cursor->left){
		cursor = cursor->left;
	}
	return cursor;
}

//Searches the tree for the given key and returns true or flase if it is in the tree or not
bool BinaryTree::search(int k){
	try{
		if(Psearch(k)->key == k)
			return true;
		return false;
	}catch(...){
		return false;
	}
}

//Searches the tree for the given key and returns the address of that node, otherwise it will throw it is not found
TreeNode* BinaryTree::Psearch(int k){
	TreeNode* cursor = root;
	TreeNode* prev = root;
	while(cursor){
		if(cursor->key > k){
			prev=cursor;
			cursor = cursor->left;
		}else{
			prev = cursor;
			cursor = cursor->right;
		}
	}
	if(prev->key == k){
		return prev;
	}
	std::string s = "Not in list";
	throw s;
}







//oof
