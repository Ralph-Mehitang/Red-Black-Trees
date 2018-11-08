#ifndef RBTREE_H
#define RBTREE_H
#include <iostream>
using namespace std;

enum color_t {red,black};
class RBTree{
private:
struct Treenode {
int key;
enum color_t color; 
Treenode* left;
Treenode* right;
Treenode* parent;
};

static Treenode* const nil;
Treenode* root=nullptr;
public:
/* Fill in with methods */
RBTree(){root=nil;}
~RBTree(){
	while(root!=NULL){
		delete root;
	}
}
void insert(int);
void inorderhelper(Treenode*);
void inorder();
void search(int);
Treenode* searchhelper(Treenode*, int key);
int minimum();
int minimumhelper(Treenode*);
int maximum();
int maximumhelper(Treenode*);
void remove(Treenode*);
int succesor();
int succesorhelper(Treenode*);
void print();
void rotateleft(Treenode*, Treenode*);
void rotateright(Treenode*,Treenode*);
void insert_fix(Treenode*);
void swap(Treenode*, Treenode*);
};
#endif