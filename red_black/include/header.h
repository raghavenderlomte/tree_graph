#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
/*this is our node which contains the members as data,colour of node,three self refferential pointers for left sub-tree,right-subtree and parent node*/
struct node{
enum{black,red} color;
struct node *left;
struct node *right;
struct node *parent;
int data;
};
void display(struct node *); /*to display all the nodes of tree*/
struct node *root;	/*pointer which stores the address of root node*/
struct node *senti;	/*on top of root node we link it with empty node */


void insert(int);	/*this function is used to insert the given element into the tree*/
void rotate_right(struct node *);	/*this function performs the left shift operation of the given node*/
void rotate_left(struct node *);	/*this function performs the right shift opearation of the given node*/
void balancing_node(struct node *);	/*this function checks,once after the inserting operation to check wether the tree is balanced or not
					  if the tree is not balanced then it will perform certain operation based on uncle node colour*/
