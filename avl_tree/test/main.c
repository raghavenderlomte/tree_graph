#include "header.h"


int main()
{
int ip=1,ret=0;
struct Node *first=NULL,*min,*het;
//memset(&first,0,sizeof(struct node));
while(ip !=0)
{
	printf("\n1-> to insert\n2->to display\n");
	scanf("%d",&ip);

	switch(ip)
	{
		case 1:  printf("enter the digit\n");
			 scanf("%d",&ip);
			 first=insert(first,ip);
		  	 break;

		case 2:  printf("the elements avilable in tree are\n");
			 display(first);
			 break;
		
		default: printf("invalid entry\n please try again.....!!\n");
	}
	
		
}
}
