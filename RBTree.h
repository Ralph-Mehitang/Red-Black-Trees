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
Treenode* insert(Treenode*,Treenode*);
void inorder(Treenode*);
Treenode* search(Treenode*, int key);
Treenode* minimum(Treenode*);
Treenode* maximum(Treenode*);
void remove();
void print();
void rotateleft(Treenode*, Treenode*);
void rotateright(Treenode*,Treenode*);
void insert_fix(Treenode*,Treenode*);
void swap(Treenode*, Treenode*);
};
#endif