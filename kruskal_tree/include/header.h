#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

int vertex[100]; /*this array is used to store the data of all vertexes*/

/*this is the structure of our edge  where it contains source and destination indexes,which is actually the indexes of each edge from which to which index it is connected*/
struct node{
int src;
int dest;
int weight;
};

void index_link(int,int);
void display(int,int);
void minimal_spanning(void);
