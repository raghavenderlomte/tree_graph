#include "header.h"
#define MAX 9999
int j=0;
int a[100]={MAX};
struct node edge[100];
  	/*initially we take an array wahich stores the list if nodes here that is a[125] and when ever this function gets invoke
			  we will be getting a partiucular edge details and we try to compare the source and destination indexes with the existing
			  of array a if that particular node is not present then we copy that into array,if that node is already available then no
			  need to copy that node if any particular node gets repeated in array that means there is a loop and we have to avoid it.*/

int check(int data) 
{
	int i,rtrn=0,rtrn1=0,rtrn2=0;
	static inc=0;
	
	if(a[0]==MAX)
	{
		a[0]=edge[data].src;
		a[1]=edge[data].dest;
		inc=2;	
	}
	for(i=0;i<inc;i++)
	{
		if(a[i]==edge[data].src)
		{
			break;
		}
		if(i==(inc-1))
		{
			rtrn1=1;
			
			a[inc]=edge[data].src;
			inc++;
		}
	}
	for(i=0;i<inc;i++)
	{
		if(a[i]==edge[data].dest)
		{
			break;
		}
		if(i == (inc-1))
		{
			rtrn2=1;
			a[inc]=edge[data].dest;
			inc++;
		}
	}
	rtrn = (rtrn1 || rtrn2);
	return rtrn;
			
}
void edge_bal()
{
	int i,l,ret=0,k=0,x,y;
	int b[10];
	b[0]=0;
	for(k=1,i=0;i<j;i++)  /*here we check for each edge */
	{
		ret=check(i);	
		if(ret == 1)
		{
			b[k]=i;
			k++;
		}
	}
	for(l=0;l<k;l++)
	{
		x=b[l];
		printf("src-> %d dest %d \n",edge[x].src,edge[x].dest);
	}
		
}
/*
void sort_ascending(int a)
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
}*/
void ascending_order() /*this function is used to arrange the node in ascending order according to weight*/
{
	int i,k,temp;
	for(i=0;i<j;i++)
	{
		for(k=i+1;k<j;k++)
			{
				if(edge[i].weight >= edge[k].weight)
				{
					temp=edge[i].src;
					edge[i].src=edge[k].src;
					edge[k].src=temp;
				
					temp=edge[i].dest;
					edge[i].dest=edge[k].dest;
					edge[k].dest=temp;

					temp=edge[i].weight;
					edge[i].weight=edge[k].weight;
					edge[k].weight=temp;

				}
			}
	}

}

void minimal_spanning()
{
	ascending_order();
	edge_bal();


}


void index_link(int src,int dest)/*this function basically used to link the different nodes(to form the edges.here we will be getting the index
				   values of the nodes and we form a edge in between those two.*/
{
	edge[j].src=src;
	edge[j].dest=dest;
	printf("ener the path weightt\n");
	scanf("%d",&edge[j].weight);
	j++;
	/*sort_ascending(j);*/


}
void display(int in,int ip) /*this function is used to display all the available nodes*/
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

