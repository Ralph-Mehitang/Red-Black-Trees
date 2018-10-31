#ifndef RBTREE_H
#define RBTREE_H
#include <iostream>
using namespace std;

class RBTree{
private:
struct TreeNode {
int key;
//enum color_t color; causes error because type isnt defined work on it later
TreeNode* left;
TreeNode* right;
TreeNode* parent;
};
TreeNode* root;
public:
/* Fill in with methods */
};
#endif