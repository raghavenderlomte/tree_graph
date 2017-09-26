#ifndef AVL_TREE
#define AVL_TREE
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
/*this is the structure of our node where key stores the data of node,height is used to store the height of node,left is self refferential pointer which points to left side of tree and right is another self referential pointer which is used to poin to the right sub tree */
struct Node{
struct Node *left;
struct Node *right;
int key,height;
};

void display(struct Node *);/*this function is used to display all the available nodes in preorder*/
int height(struct Node *);/*this function is used to display the height of a node*/
int max(int,int);	/*this function is used to compare the heights of left and right sub tree and perform the operation*/
struct Node* newNpde(int); /*used to create the new node*/
struct Node* rightRotate(struct Node *); /*used to perform the right rotate operation*/
struct Node* leftRotate(struct Node *);/*used to perform the left rotate operation*/
int getBalance(struct Node *);/*used to check wether the tree is balanced or not*/
struct Node* insert(struct Node*,int);/*used to insert a particular entry into the tree*/
#endif
