//program to implement graph data structure using adjacency list

#include<stdio.h>
#include<stdlib.h>
#define N 6

struct Graph{
	struct a_list{
		int vertex;
		struct a_list *next;
	} *head[N];

};

struct Edge
{
	int src;
	int dest;
};

struct Graph* createGraph(struct Edge edges[], int E)
{
	//allocate memory to graph and initialize the head pointer to Null
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	int i;
	for(i=0;i<N;i++)
		graph->head[i] = NULL;
	
	//build the graph
	for(i=0;i<E;i++)
	{
		int src = edges[i].src;
		int dest = edges[i].dest;
		struct a_list* new_a_list = (struct a_list*)malloc(sizeof(struct a_list));
		
		new_a_list->vertex = dest;
		new_a_list->next = graph->head[src];

		graph->head[src] = new_a_list;	

	}
	return graph;

}

void printGraph(struct Graph* graph)
{
	int i;
	for(i=0; i<N;i++)
	{
		struct a_list* ptr = graph->head[i];
		while(ptr)
		{
			printf("%d --> %d)\t",i,ptr->vertex);
			ptr = ptr->next;
		}
		printf("\n");
	}
}

int main()
{
	struct Edge edges[] = {{0,1},{1,2},{2,0},{2,1},{3,2},{4,5},{5,4},{0,3}};
	int E = sizeof(edges)/sizeof(edges[0]);
	struct Graph *graph = createGraph(edges,E);
	printGraph(graph);

	return 0;
}

