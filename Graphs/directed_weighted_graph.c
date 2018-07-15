#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define N 6

struct Graph 
{
	struct node{
		int vertex;
		int weight;
		struct node* next;
	}*head[N];
};

struct Edge{
	int src;
	int dest;
	int weight;
};

struct Graph* createGraph(struct Edge edge[],int E)
{
	int i;
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	for(i=0;i<N;i++)
		graph->head[i] = NULL;
	for(i=0;i<E;i++)
	{
		int src = edge[i].src;
		int dest = edge[i].dest;
		int weight = edge[i].weight;
		struct node* newnode = (struct node*)malloc(sizeof(struct node));
		newnode->vertex = dest;
		newnode->weight = weight;
		newnode->next = graph->head[src];
		graph->head[src] = newnode;
	}
	return graph;

}

void printGraph(struct Graph* graph)
{
	int i;
	for(i = 0;i<N;i++)
	{
		struct node* ptr = graph->head[i];
		while(ptr)
		{
			printf("%d -> %d (%d)",i,ptr->vertex,ptr->weight);
			gotoxy(i,ptr->vertex);
			printf("*");
			ptr = ptr->next;
		}
	}

}

int main()
{

	struct Edge edge[] = {
		{0,1,6}
	};
	int E = sizeof(edge)/sizeof(edge[0]);
	struct Graph *graph = createGraph(edge,E);
	printGraph(graph);
	return 0;
}