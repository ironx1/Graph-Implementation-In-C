#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int v;
    struct node *next;
} node;

typedef struct graph
{
    int numVer;
    node **adjList;
} graph;

node *createNode(int vertex)
{
    node *n = (node *)malloc(sizeof(node));
    n->v = vertex;
    n->next = NULL;
    return n;
}

graph *createGraph(int v)
{
    graph *g = (graph *)malloc(sizeof(graph));
    g->numVer = v;
    g->adjList = (node **)malloc(sizeof(node *) * v);
    for (int i = 0; i < g->numVer; i++)
    {
        g->adjList[i] = createNode(i);
    }
    return g;
}

void addEdge(graph *g, int x, int y)
{

    node *n = createNode(y);
    node *temp = createNode(x);
    for (int i = 0; i < g->numVer; i++)
    {
        if (x == g->adjList[i]->v)
        {
            node *iter = g->adjList[i];
            while (iter->next != NULL)
            {
                iter = iter->next;
            }
            iter->next = n;
        }
    }
    for (int i = 0; i < g->numVer; i++)
    {
        if (y == g->adjList[i]->v)
        {
            node *iter = g->adjList[i];
            while (iter->next != NULL)
            {
                iter = iter->next;
            }
            iter->next = temp;
        }
    }
}

void printGraph(graph *g)
{
    for (int i = 0; i < g->numVer; i++)
    {
        node *iter = g->adjList[i];
        iter = iter->next;
        while (iter != NULL)
        {
            printf("%d->%d\n", g->adjList[i]->v, iter->v);
            iter = iter->next;
        }
    }
}

int main(int argc, char const *argv[])
{
    graph *myGraph = createGraph(4);
    addEdge(myGraph, 0, 1);
    addEdge(myGraph, 0, 2);
    addEdge(myGraph, 0, 3);
    addEdge(myGraph, 1, 2);
    printGraph(myGraph);
    return 0;
}
