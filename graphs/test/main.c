#include "header.h"

int main()
{
int ip,i=0,src,dest,j=0;

		/*here we take the input from the user by using below switch.based on the input from the user respecive function gets invoke*/
	while(1)
	{
		printf("\n1->insert\n2->link\n3->display\n");
		scanf("%d",&ip);
		switch(ip)
		{
			case 1: printf("enter the vertex\n");
				scanf("%d",&vertex[j]);
				j++;
				break;		
				
			case 2:	printf("enter the source and destination indexes which you want to link\nenter source value as -1 to quit it\n");
				printf("index range available is from 0-%d\n",j);
				printf("enter the source index\n");
				scanf("%d",&src);
				printf("enter the destination address\n");
				scanf("%d",&dest);
				if((src<j &&src>=0) &&(dest<j && dest>=0))
				{
					index_link(src,dest);
					i++;
				}
				else
				{
					printf("not a valid entry\n");
				}
				break;
				
			
			case 3:	display(j,i);
				break;
		}
	}

}
