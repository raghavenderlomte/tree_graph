#include "header.h"


int main()
{
	int ip=1;
	//memset(&first,0,sizeof(struct node));
	senti=(struct node *)malloc(sizeof(struct node));
	memset(senti,'\0',sizeof(struct node));
	senti->data = -1;
	senti->color=black;
	root=senti;
	while(ip !=0)
	{
		printf("\n0->exit\n1-> to insert\n2->to display\n");
		scanf("%d",&ip);
	
		switch(ip)
		{

			case 1:  printf("enter the digit\n");
				 scanf("%d",&ip);
				 insert(ip);
			  	 break;	
	
			case 2:  display(root);
				 break;			

			default: printf("invalid entry\n please try again.....!!\n");
		}
		
			
	}
	return 0;
}
