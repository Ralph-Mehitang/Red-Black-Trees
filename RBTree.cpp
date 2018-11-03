#include <iostream>
#include <stdlib.h>
#include "RBTree.h"

using namespace std;

void RBTree:: insert(Treenode *root, Treenode* node){
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