#include <iostream>
#include <stdlib.h>
#include "RBTree.h"

using namespace std;

RBTree:: Treenode* RBTree:: insert(Treenode *root, Treenode* node){
//if the tree is empty, return a new node
	if (root==NULL){
		exit(-1);
	}

	if(node->key<root->key){
		root->left=insert(root->left,node);
		root->left->parent=root;	
	}
	else if (node->key>root->key){
		root->right=insert(root->right,node);
		root->right->parent=root;
	}
	return root;
}
// inodertraversal recursive function	
void RBTree:: inorder(Treenode *root){

if(root==NULL){
	return;
}

inorder(root->left);
cout<<root->key;
inorder(root->right);
}

void RBTree:: search(){


}

void RBTree:: minimum(){


}

void RBTree:: maximum(){

}

void RBTree:: remove(){

}

void RBTree:: print(){

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
else
	node->parent->right=left_ptr;
left_ptr->right=node;
node->parent=left_ptr;
}

void ::RBTree:: insertfix(Treenode* root, Treenode* node){

	Treenode* parent_ptr=NULL;
	Treenode* grandparent_ptr= NULL;

	while((node!=root) && (node->color!=black) && (node->parent->color==red))
	{
		parent_ptr=node->parent;
		grandparent_ptr=node->parent->parent;
		
	}
}