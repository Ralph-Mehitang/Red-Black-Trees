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

RBTree:: Treenode* RBTree:: insert(Treenode *root, Treenode* node){
//if the tree is empty, return a new node
	if (root==nil){
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
RBTree:: Treenode* RBTree:: search(Treenode* node, int key){
if(node!=NULL){

	if(key<node->key){
	return search(node->left,key);
}
	if(key>node->key){
	return search(node->right,key);
}
}
	else 
	return search(node->right, key);

}



RBTree:: Treenode* RBTree:: minimum(Treenode* node){
	Treenode *tmp=node;
	//finding the left most leaf
	while(tmp->left!=NULL){
		tmp=tmp->left;
	}
	return tmp;

}

RBTree:: Treenode* RBTree:: maximum(Treenode* node){

if(node==NULL){
	return NULL;
}
else if(node->right==NULL){
	return node;
}
else 
return maximum(node->right);
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
else{
	node->parent->right=left_ptr;
left_ptr->right=node;
node->parent=left_ptr;
}

}

void ::RBTree:: insert_fix(Treenode* root, Treenode* node){

	Treenode* parent_ptr=NULL;
	Treenode* grandparent_ptr= NULL;
	Treenode *uncle_ptr=NULL;

	while((node!=root) && (node->color!=black) && (node->parent->color==red))
	{
		parent_ptr=node->parent;
		grandparent_ptr=node->parent->parent;
		//case when the parent of node is the left child of the grandparent
		if(parent_ptr==grandparent_ptr->left){
			uncle_ptr=grandparent_ptr->right;

			if(uncle_ptr!=nil && uncle_ptr->color==red){
				grandparent_ptr->color=red;
				parent_ptr->color=black;
				uncle_ptr->color=black;
				node=grandparent_ptr;
			}
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
			swap(parent_ptr->color,grandparent_ptr->color);
			node=parent_ptr;

			else {
				//when the uncle of parent is red you need to recolor
				uncle_ptr=grandparent_ptr->left;

				if ((uncle_ptr != NULL) && uncle_ptr->color==red)
				{
					grandparent_ptr->color=red;
					parent_ptr->color=black;
					uncle_ptr->color=black;
					node=grandparent_ptr;
				}

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
				swap(parent_ptr->color, grandparent_ptr->color);
				node=parent_ptr;
			}

		}


	}

	root->color=black;
}
