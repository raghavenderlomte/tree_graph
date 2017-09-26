#include "header.h"

struct node edge[100];

void sort_ascending(int a) /*this function is used to arrange the nodes in ascending order based on source index*/
{
	int i,k,temp1;
	for(i=0;i<a;i++)
	{
		for(k=i+1;k<a;k++)
		{
			if(edge[i].src>edge[k].src)
			{
				temp1=edge[i].src;
				edge[i].src=edge[k].src;
				edge[k].src=temp1;
				
				temp1=edge[i].dest;
				edge[i].dest=edge[k].dest;
				edge[k].dest=temp1;

				temp1=edge[i].weight;
				edge[i].weight=edge[k].weight;
				edge[k].weight=temp1;
			
			}
		}
	}
}		
/*when ever this function gets invoked user will even send the detils of nodes from where to where he wants to link those values gets stored in edge variable,which is of type struct node*/
void index_link(int src,int dest)
{
static int j=0;
	edge[j].src=src;
	edge[j].dest=dest;
	printf("ener the path weightt\n");
	scanf("%d",&edge[j].weight);
	j++;
	sort_ascending(j);


}
void display(int in,int ip) /*this function is used to display all the avaialable nodes and edges*/
{
	int i=0;
	printf("available nodes are\n");
	for(i=0;i<in;i++)
	{
		printf("index->%d data->%d\n",i,vertex[i]);
	}
	printf("links made yet are\n");
	for(i=0;i<ip;i++)
	{
		printf("index->%d src->%d dest->%d weight->%d\n",i,edge[i].src,edge[i].dest,edge[i].weight);
	}
}
