#include <stdio.h>
#include <iostream>
#include <chrono>

enum color_t{
  RED, BLACK
};

class RBTree{
  private:
    struct TreeNode {
      int key;
      color_t color;
      TreeNode* left;
      TreeNode* right;
      TreeNode* parent;
    };

    static TreeNode* const nil;

    TreeNode* root;

    void _printInOrder(TreeNode* u){
      if( u != nil ){
        _printInOrder(u->left);
        std::cout<<std::endl;
        printf(" %d", u->key);
        std::cout<<" ME: "<<u<<" Parent: "<<u->parent<<" Left: "<<u->left<<" Right: "<<u->right<<"Color: "<<u->color<<std::endl;
        _printInOrder(u->right);
      }
    }

  public:
    /* Fill in with methods */
    RBTree(){
      root = nil;
    }

    //Deconstructor
    ~RBTree(){
    	removeTree(root);
    }
    //Starts at a given Node and deletes everything under it
    void removeTree(TreeNode* T){
    	if(T != nil){
    		removeTree(T->right);
    		removeTree(T->left);
    		delete T;
    	}
    }

    void printInOrder(){
      printf("Tree data in order: ");
      std::cout<<"\nRoot: "<<root<<std::endl;
      std::cout<<"nil: "<<nil<<std::endl;
      _printInOrder(root);
      puts("");
    }


    void insert(int k){
      TreeNode* newNode = new TreeNode;
      newNode->key = k;

      if (root == nil){
        // printf("Inserting %d into empty tree\n", k);
        root = newNode;
        newNode->parent = nil;
      } else {
        TreeNode* y = nil;
        TreeNode* x = root;
        while(x != nil){
          y = x;
          if( k < x->key ){
            x = x->left;
          } else {
            x = x->right;
          }
        }
        if( k < y->key ){
          // printf("Inserting %d on the left of %d\n",k,y->key);
          y->left = newNode;
        } else {
          // printf("Inserting %d on the right of %d\n",k,y->key);
          y->right = newNode;
        }
        newNode->parent = y;
      }
      newNode->color = RED;
      newNode->left = nil;
      newNode->right = nil;
      insertFix(newNode);
    }

    void insertFix(TreeNode* z){
	while (z->parent->color == RED) {
		if (z->parent == z->parent->parent->left) {
			TreeNode* y =  z->parent->parent->right;
			if (y->color == RED) {
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			} else {
				if (z == z->parent->right) {
					z = z->parent;
					leftRotate(z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				rightRotate(z->parent->parent);
			}
		} else {
			TreeNode* y = z->parent->parent->left;
			if (y->color == RED) {
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			} else {
				if (z == z->parent->left) {
					z = z->parent;
					rightRotate(z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				leftRotate(z->parent->parent);
			}
		}
	}
	root->color = BLACK;
}

    void leftRotate(TreeNode* x){
      TreeNode* y = x->right;
      x->right = y->left;
      if(y->left != nil){
        y->left->parent = x;
      }
      y->parent = x->parent;
      if(x->parent == nil){
        root = y;
      }else if(x == x->parent->left){
        x->parent->left = y;
      }else{
          x->parent->right = y;
      }
      y->left = x;
      x->parent = y;
    }
    void rightRotate(TreeNode* x){
      TreeNode* y = x->left;
      x->left = y->right;
      if(y->right != nil){
        y->right->parent = x;
      }
      y->parent = x->parent;
      if(x->parent == nil){
        root = y;
      }else if(x == x->parent->right){
        x->parent->right = y;
      }else{
          x->parent->left = y;
      }
      y->right = x;
      x->parent = y;
    }

		void RBDelete(int k){
      try{
        TreeNode* z = Psearch(k);
        TreeNode* y=z;
        TreeNode* x;
  			color_t yOriginalColor = y->color;
  			if(z->left == nil){
  				x = z->right;
  				transplant(z,z->right);
          delete z;
  			}else if(z->right == nil){
  				x = z->left;
  				transplant(z,z->left);
          delete z;
  			}else{
  				y = Pminimum(z->right);
  				yOriginalColor = y->color;
  				x = y->right;
  				if(y->parent == z){
  					x->parent = y;
  				}else{
  					transplant(y, y->right);
            // delete y;
  					y->right = z->right;
  					y->right->parent = y;
  				}
  				transplant(z, y);
  				y->left = z->left;
  				y->left->parent = y;
  				y->color = z->color;
          delete z;
  			}
  			if(yOriginalColor == BLACK){
  				RBDeleteFix(x);
  			}
      }catch(std::string s){
        throw s;
      }catch(...){
        std::cout<<"Delete Unknown error"<<std::endl;
      }
		}

		void RBDeleteFix(TreeNode* x){
      try{
      	while(x != root && x->color == BLACK){
  				if(x == x->parent->left){
  					TreeNode* w = x->parent->right;
  					if(w->color == RED){
  						w->color = BLACK;
  						x->parent->color - RED;
  						leftRotate(x->parent);
  						w = x->parent->right;
  					}
  					if(w->left->color == BLACK && w->right->color == BLACK){
  						w->color = RED;
  						x=x->parent;
  					}else if(w->right->color == BLACK){
  						w->left->color = BLACK;
  						w->color = RED;
  						rightRotate(w);
  						w = x->parent->right;
  					}
  					w->color = x->parent->color;
  					x->parent->color=BLACK;
  					w->right->color = BLACK;
  					leftRotate(x->parent);
  					x = root;
  				}else{
            TreeNode* w = x->parent->left;
            if(w->color == RED){
              w->color = BLACK;
              x->parent->color - RED;
              rightRotate(x->parent);
              w = x->parent->left;
            }
            if(w->right->color == BLACK && w->left->color == BLACK){
              w->color = RED;
              x=x->parent;
            }else if(w->left->color == BLACK){
              w->right->color = BLACK;
              w->color = RED;
              leftRotate(w);
              w = x->parent->left;
            }
            w->color = x->parent->color;
            x->parent->color=BLACK;
            w->left->color = BLACK;
            rightRotate(x->parent);
            x = root;
  				}
  				x->color = BLACK;
  			}
      }catch(std::string s){
        throw s;
      }catch(...){
        std::cout<<"Delete Unknown error"<<std::endl;
      }
		}



























    //Copy constructor TODO
    RBTree(const RBTree& T){
    		root=nullptr;
    		copyTree(T.root);
    }

    //= operator
    RBTree& operator=(const RBTree& T){
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

    //Takes the Root and recusively makes (this) be the same list as the given
    void copyTree(TreeNode* T){
    	if(T){
    		this->insert(T->key);
    		copyTree(T->right);
    		copyTree(T->left);
    	}
    }

    //Prints out the tree as it is internally
    void Pprint(TreeNode* T){
    	if(T){
    		std::cout<<T<<" : "<< T->key <<"| ";
    		Pprint(T->left);
    		Pprint(T->right);
    	}
    }

    //This returns the largest number in the tree
    int maximum(){
    	try{
    	return Pmaximum(root)->key;
    	}catch(std::string s){
    		throw s;
    	}catch(...){
    		std::string UE = "Unkown Error";
    		throw UE;
    	}
    }

    //Runs all the ways down the right side of the tree where the highest number lives
    RBTree::TreeNode* Pmaximum(TreeNode* T){
    	if(!T){
    		std::string s = "Error: No root!";
    		throw s;
    	}
    	TreeNode* cursor = T;
    	while(cursor->right != nil){
    		cursor=cursor->right;
    	}
    	return cursor;
    }

    //This returns the smallest number in the tree
    int minimum(){
    	try{
    		return Pminimum(root)->key;
    	}catch(std::string s){
    		throw s;
    	}catch(...){
    		std::string UE = "Unknown Error";
    		throw UE;
    	}
    }

    //Runs all the way down the left sid eof the tree, where the smallest number lives
    RBTree::TreeNode* Pminimum(TreeNode* T){
    	if(!T){
    		std::string s = "Error: No root!";
    		throw s;
    	}
    	TreeNode* cursor = T;
    	while(cursor->left != nil){
    		cursor = cursor->left;
    	}
    	return cursor;
    }

    //Searches the tree for the given key and returns true or flase if it is in the tree or not
    bool search(int k){
    	try{
    		if(Psearch(k)->key == k)
    			return true;
    		return false;
    	}catch(...){
    		return false;
    	}
    }

    //Searches the tree for the given key and returns the address of that node, otherwise it will throw it is not found
    RBTree::TreeNode* Psearch(int k){
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

    		if(prev->key == k){
    			return prev;
    		}
    	}
    	std::string s = "Not in list";
    	throw s;
    }

    //Transplant: will takes a root of a tree and a node from this tree and replace this nodes tree with the fiven root
    void transplant(TreeNode* U,TreeNode* V){
    	if(U->parent == nil){
    		root = V;
    	}else if(U->parent->right == U){
    		U->parent->right = V;
    	}else{
    		U->parent->left = V;
    	}
    		V->parent = U->parent;
    }

    //Successor:: will return the address to the closeest bigger key
    RBTree::TreeNode* Psuccessor(int k){
    	TreeNode* U;
    	try{
    		U = Psearch(k);
    	}catch(std::string s){
    		throw s;
    	}
    	TreeNode* start = U;
    	if(U->right){
    		return Pminimum(U->right);
    	}else{
    		while(U->parent && U != U->parent->left){
    			U=U->parent;
    		}
    		if(!U->parent){
    			return start;
    		}
    		return U->parent;
    	}
    }

    int successor(int k){
    	if(!root){
    		std::string s = "No root!";
    		throw s;
    	}
    	return Psuccessor(k)->key;//TODO breaks if there is no successor (if k is the max)
    }
};

// Intialize non-int static members outside
// need -std=c++11 to use the intializer-list constructor call
RBTree::TreeNode* const RBTree::nil = new TreeNode({0, BLACK, nullptr, nullptr, nullptr});


//Takes a sorting algorithm calls it and prints it's meta data
double timeFuncInsert(int A, RBTree& t){
  //The "auto" type determines the corret type at compile-time
  auto start=std::chrono::system_clock::now();

  t.insert(A);

  auto end=std::chrono::system_clock::now();
  auto elapsed = end - start;
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  //std::cout<<"Finished at: "<<std::ctime(&end_time)<<"elapsed time: "<<elapsed_seconds.count()<<"s\n";

return std::chrono::duration<double>(elapsed).count();
}

//Takes a sorting algorithm calls it and prints it's meta data
double timeFuncDelete(int A, RBTree& t){
  //The "auto" type determines the corret type at compile-time
  auto start=std::chrono::system_clock::now();

  t.RBDelete(A);

  auto end=std::chrono::system_clock::now();
  auto elapsed = end - start;
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  //std::cout<<"Finished at: "<<std::ctime(&end_time)<<"elapsed time: "<<elapsed_seconds.count()<<"s\n";

  return std::chrono::duration<double>(elapsed).count();
}

int main(int argc, char* argv[]){
  srand (time(NULL));
  //printf("Warning! Insert-Fixup not implemented! RBT properties will not be enforced!\n");
  RBTree t;
  t.insert(3);
  t.insert(2);
  t.insert(5);
  t.insert(15);
  t.insert(10);
  std::cout<<std::endl;
  t.printInOrder();
  std::cout<<std::endl;
  std::cout<<"Deleting 10"<<std::endl;
  t.RBDelete(10);
  t.printInOrder();
  std::cout<<"Deleting 3"<<std::endl;
  t.RBDelete(3);
  t.printInOrder();

  t.insert(15);
  t.insert(10);
  t.insert(3);
  t.insert(0);
  t.insert(1);
  t.printInOrder();

  // timeFuncInsert(4,t);
  // timeFuncDelete(4,t);
  try{

    RBTree tester;
    double timerI=0.0;
    double timerD=0.0;

    for(int i = 10; i<10000; i+=1000){
      for(int j=0; j<i; j++){
        tester.insert(i+j);
      }
      int boi;
      for(int j=0; j<10; j++){
        boi = rand() % 100 + 1;
        timerI += timeFuncInsert(boi, tester);

        try{
          timerD += timeFuncDelete(boi, tester);
        }catch(std::string s){
          std::cout<<boi<<" was in the tree"<<std::endl;
        }
      }
      timerI/=10.0;
      timerD/=10.0;
      std::cout<<"# of elements: "<< i <<" Insert time: "<<timerI<<" Delete time: "<<timerD<<std::endl;
    }
  }catch(std::string s){
    std::cout<<s<<std::endl;
  }catch(...){
    std::cout<<"Delete Unknown error"<<std::endl;
  }
  return 0;
}
