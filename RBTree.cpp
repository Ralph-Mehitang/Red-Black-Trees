#include <iostream>
#include <stdlib.h>
#include "RBTree.h"

using namespace std;


RBTree::Treenode* const RBTree::nil=new Treenode({0,black, nullptr,nullptr,nullptr});

void RBTree:: swap (Treenode* one, Treenode* two){

	Treenode* temp;
	temp=one;
	one=two;
	two=temp;
}

//insert function
void RBTree:: insert(int k){
//if the tree is empty, return a new node
    Treenode* node = new Treenode;
    node->key = k;
    node->parent = nil;
    if(root==nil) {
        root = node;
        node->parent = nil;
    } else {
        Treenode* x = nil;
        Treenode* y = root;
        while(y != nil)
        {
            x = y;
            if (k < y->key) {
                y = y->left;
            } else {
                y = y->right;
            }
        }
        if (k < x->key) {
            x->left = node;
        } else {
            x->right = node;
        }
        node->parent = y;
    }
    node->color = red;
    node->left = nil;
    node->right = nil;
    insert_fix(node);
}

void ::RBTree:: insert_fix(Treenode* node){

	Treenode* parent_ptr=NULL;
	Treenode* grandparent_ptr= NULL;
	Treenode *uncle_ptr=NULL;

	while(node->parent->color==red)
	{
		parent_ptr=node->parent;
		grandparent_ptr=node->parent->parent;
		//case when the parent of node is the left child of the grandparent
		if(parent_ptr==grandparent_ptr->left){
			uncle_ptr=grandparent_ptr->right;

			if(uncle_ptr->color==red){
				grandparent_ptr->color=red;
				parent_ptr->color=black;
				uncle_ptr->color=black;
				node=grandparent_ptr;
			}


		else{
			//node is the right child of its parent
			if(node==parent_ptr->right){
				rotateleft(root,parent_ptr);
				node=parent_ptr;
				parent_ptr=node->parent;
			}
			//node is the left child of its parent
			rotateright(root,grandparent_ptr);
			node=parent_ptr;
	}
}
			else {
				//when the uncle of parent is red you need to recolor
				uncle_ptr=grandparent_ptr->left;

				if ((uncle_ptr != NULL) && (uncle_ptr->color==red))
				{
					grandparent_ptr->color=red;
					parent_ptr->color=black;
					uncle_ptr->color=black;
					node=grandparent_ptr;
				}

			else{
				//node is the left child of the parent

				if (node==parent_ptr->left)
				{
					rotateright(root,parent_ptr);
					node=parent_ptr;
					parent_ptr=node->parent;
				}
				rotateleft(root,grandparent_ptr);
				//swap(parent_ptr->color, grandparent_ptr->color);
				node=parent_ptr;
			}

		}


	}

	root->color=black;
}
/*
void RBTree:: remove(int val){
	Treenode* root;
	// base case
	    if (root == NULL) return root;

	    // If the key to be deleted is smaller than the root's key,
	    // then it lies in left subtree
	    if (val < root->key)
	        root->left = remove(root->left, val);

	    // If the key to be deleted is greater than the root's key,
	    // then it lies in right subtree
	    else if (val > root->key)
	        root->right = remove(root->right, val);

	    // if key is same as root's key, then This is the node
	    // to be deleted
	    else
	    {
	        // node with only one child or no child
	        if (root->left == NULL)
	        {
	            struct node *temp = root->right;
	            free(root);
	            return temp;
	        }
	        else if (root->right == NULL)
	        {
	            struct node *temp = root->left;
	            free(root);
	            return temp;
	        }

	        // node with two children: Get the inorder successor (smallest
	        // in the right subtree)
	        struct node* temp = minimumhelper(root->right);

	        // Copy the inorder successor's content to this node
	        root->key = temp->key;

	        // Delete the inorder successor
	        root->right = remove(root->right, temp->key);
	    }
	    return root;
}
*/

// inodertraversal recursive function
void RBTree:: inorderhelper(Treenode *root){

if(root==nil){
	return;
}

inorderhelper(root->left);
cout<<root->key<<" ";
inorderhelper(root->right);
}

void RBTree:: inorder(){
	inorderhelper(root);
}

RBTree ::Treenode* RBTree:: searchhelper(Treenode* node, int key){
//base case
	if(node==nil||node->key==key){
	return node;
}
//key is greater than roots key
	else if(key>node->key){
	return searchhelper(node->right,key);
}
else{
//key is smaller than the roots key
return searchhelper(node->left,key);
}
}
void RBTree:: search(int key){
	Treenode* tmp=searchhelper(root,key);
	if(tmp->key==key){
		cout<<"The value is in the tree"<<endl;
	}
	else
	cout<<"The value is not in the true"<<endl;
}

int RBTree::minimum(){
	 inmin(root);
}
int RBTree ::inmin(Treenode* node){
	if(node!=nil)
	{
	while(node->left!=nil){
		node=node->left;
	}
return node->key;
}

}

RBTree :: Treenode* RBTree:: minimumhelper(Treenode* node){
	if(node!=nil)
	{
	while(node->left!=nil){
		node=node->left;
	}

}
	return node;

}

int RBTree::maximum(){

	maximumhelper(root);
}

int RBTree:: maximumhelper(Treenode* node){

if(node!=nil){
while(node->right!=nil)
{
	node=node->right;
}

return node->key;
}
}

void RBTree:: transplant(Treenode* nance, Treenode *node){
	if (nance->parent==nil){
		root=node;
	}
	else if(nance==nance->parent->left){
	nance ->parent->left=node;
	}
	else {
		nance->parent->right=node;
	}
	node->parent=nance->parent;
}
void RBTree:: succesor(int key){
Treenode*root=nullptr;
Treenode*suc=nullptr;
succesorhelper(root,suc,key);
}

void RBTree:: succesorhelper(Treenode *root, Treenode*suc, int val){
//base case
if(root==NULL){
exit(-1);
}
//if key is present at given root
if(root->key==val){
	//minimum value in right subtree is successor
	if(root->right!=NULL){
		Treenode *tmp=root->right;
		while(tmp->left)
			tmp=tmp->left;
		suc=tmp;
	}
			return;
}
//if key is smaller than the key of the root, move to the left
if(root->key>val){
	suc=root;
	succesorhelper(root->left,suc,val);
}

}
void RBTree:: rotateleft(Treenode* root, Treenode* node){

Treenode* right_ptr=node->right;
node->right=right_ptr->left;
//checks if the inorder value in index 3 is broken
if (right_ptr!=NULL){
	node->right->parent=node;

	right_ptr->parent->left;
}
if (node->parent == NULL){
	root=right_ptr;
}
//vice versa
else if(node==node->parent->left){
	node->parent->left= right_ptr;
}
else
	node->parent->right=right_ptr;
right_ptr->left=node;
node->parent=right_ptr;
}

void RBTree:: rotateright(Treenode* root, Treenode* node){
Treenode* left_ptr=node->right;
node->left=left_ptr->right;
//checks if the inorder value in index 3 is broken
if (node->left!=NULL){
	node->left->parent=node;

	left_ptr->parent=node->parent;
}
if (node->parent == NULL){
	root=left_ptr;
}
//vice versa
else if(node==node->parent->left){
	node->parent->left= left_ptr;
}
else{
	node->parent->right=left_ptr;
left_ptr->right=node;
node->parent=left_ptr;
}

}
