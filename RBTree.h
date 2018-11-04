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
Treenode* root;
public:
/* Fill in with methods */
RBTree(){root=NULL;}
Treenode* insert(Treenode*,Treenode*);
void inorder(Treenode*);
void search();
void minimum();
void maximum();
void remove();
void print();
void rotateleft(Treenode*, Treenode*);
void rotateright(Treenode*,Treenode*);
void insert_fix(Treenode*,Treenode*);
};
#endif