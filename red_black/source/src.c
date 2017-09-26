#include "header.h"


void display(struct node *inp) /*By using the traversing logic of preorder, i'm visiting every node and printing the data in it*/
{
char a[2][10]={"black","red"};
struct node *trev=NULL;
trev=inp;
if(trev == NULL)
{
	return;
}

printf("data->%dcolor->%s\n",trev->data,a[trev->color]);
display(trev->left);
display(trev->right);
}


void insert(int data)
{

struct node *temp,*par,*ptr;
par=senti;
ptr=root;
	while(ptr!=NULL) /*checking wether the node is empty or not it will travese once it reaches the leaf node of it then it comes out of while 				loop */
	{
		par=ptr;
		if(data < ptr->data)	/*check wether the incoming data is greater or less if it is greater then move towards right or towards left						*/
		{
			ptr=ptr->left;
		}
		else if(data > ptr->data)
		{
			ptr=ptr->right;
		}
		else
		{
			printf("duplicates are not allowed\n");
			return;
		}
	}
	temp=(struct node *)malloc(sizeof(struct node));/*once we reach the appropriate leaf node allocate memory in a temporary node assign the 								data and link it with the previous node of it.*/
	memset(temp,'\0',sizeof(struct node));
	temp->data=data;
	temp->color=red;
	temp->left=NULL;
	temp->right=NULL;
	temp->parent=par;
	if(par == senti)
	{
		root=temp;
	}
	else if( data < par->data)
	{
		par->left=temp;
	}
	else
	{
		par->right = temp;
	}

	balancing_node(temp);
}

void balancing_node(struct node *ip)
{
struct node *grandpa,*uncle,*par;
	while(ip->parent->color == red)		/*operation is dependent on the uncle node so if the colour of uncle node is red then just change
						 uncle node,parent node colour to black and grandpa(parent of parent)to red,all the time we have to						      maintain root node as black*/
	{
		par=ip->parent;
		grandpa= par->parent;
		if(ip->parent == grandpa->left)		
		{
			uncle=grandpa->right;
			if((uncle==NULL)||(uncle->color == black))/*if the uncle node is black then based on the position of the node we have to
									perform rotation operations and change the colours accordingly*/
			{
				if(ip==par->right)
				{
					rotate_left(par); 
					ip=par;
					par=ip->parent;
				}
				par->color=black;
				grandpa->color=red;
				rotate_right(grandpa);

			}
			else
			{
				par->color=black;
				uncle->color=black;
				grandpa->color=red;
				ip=grandpa;
			}
		}
		else
		{
			uncle=grandpa->left;
			if((uncle!=NULL)&&(uncle->color == red))
			{
				par->color=black;
				uncle->color=black;
				grandpa->color=red;
				ip=grandpa;
			}
			else
			{
				if(ip == par->left)
				{
					rotate_right(par);
					ip=par;
					par=ip->parent;
				}
				par->color=black;
				grandpa->color=red;
				rotate_left(grandpa);
			}
		
		}
	}
	root->color=black;


}
void rotate_left(struct node *nd) /* it performs the left rotate operation*/
{

	struct node *aux=NULL;
	aux=nd->right;
	nd->right= aux->left;
	
	if(aux->left!=NULL)
	{
		aux->left->parent=nd;
	}
	aux->parent=nd->parent;
	if(nd->parent ==senti)
	{
		root=aux;
	}
	else if(nd->parent->left==nd)
	{
		nd->parent->left=aux;
	}
	else
	{
		nd->parent->right=aux;
	}
	aux->left=nd;
	nd->parent=aux;
}
void rotate_right(struct node *nd) /*it performs the right rotate operation*/
{
	struct node *aux=NULL;
	aux=nd->left;
	nd->left=aux->right;
	
	if(aux->right!=NULL)
	{
		aux->right->parent=nd;
	}
	aux->parent=nd->parent;
	if(nd->parent == senti)
	{
		root=aux;
	}
	else if(nd->parent->right == nd)
	{
		nd->parent->right=aux;
	}
	else
	{
		nd->parent->left=aux;
	}
	aux->right=nd;
	nd->parent=aux;
}
