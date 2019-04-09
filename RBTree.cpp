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

void RBTree:: remove(int val){
	Treenode* node= new Treenode;
	node= searchhelper(root,val); // sets node to the value that has been inputed
	if(node==nil){
		cout<<"the value you want deleted does not exist"<<endl;
		return;
	}

		//remove(node);
}

void RBTree:: removehelper(Treenode* node){
	color_t col;
	Treenode* childnode;
}

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
	minimumhelper(root);
}

int RBTree:: minimumhelper(Treenode* node){
	if(node!=nil)
	{
	while(node->left!=nil){
		node=node->left;
	}

}
	return node->key;

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
int RBTree::succesor(){
	Treenode* root;
	Treenode* tmp=root->left->right->right;
	return succesorhelper(root,tmp);
}


int RBTree:: succesorhelper(Treenode *root, Treenode *node){
	cout<<"debug"<<endl;
 	if(node->right!=NULL){
		return minimumhelper(node->right);
	}
	cout<<"debug two"<<endl;
	Treenode* tmp =node->parent;
	while(tmp!=NULL && node==tmp->right){
		node=tmp;
		cout<<"debug three"<<endl;
		tmp=tmp->parent;
	}

	return tmp->key;
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
