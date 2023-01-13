#include <stdio.h>
#include <stdlib.h>

#define V 4

typedef struct node
{
    int i;
    struct node *next;
} node;

node **adjList = NULL;

node *createNode(int);
void addEdge(int, int);
void printGraph();

int main(int argc, char const *argv[])
{
    adjList = (node **)malloc(sizeof(node *) * V);
    for (int i = 0; i < V; i++)
    {
        adjList[i] = createNode(i);
    }
    addEdge(0,1);
    addEdge(1,0);
    addEdge(0,2);
    addEdge(2,0);
    addEdge(0,3);
    addEdge(3,0);
    addEdge(1,2);
    addEdge(2,1);
    printGraph();
    return 0;
}

node *createNode(int v)
{
    node *n = (node *)malloc(sizeof(node));
    n->i = v;
    n->next = NULL;
    return n;
}

void addEdge(int x, int y)
{
    for (int i = 0; i < V; i++)
    {
        if (x == adjList[i]->i)
        {
            node *iter = adjList[i];
            while (iter->next != NULL)
            {
                iter = iter->next;
            }
            iter->next = createNode(y);
        }
    }
}

void printGraph()
{
    for (int i = 0; i < V; i++)
    {
        node *iter = adjList[i];
        printf("%d--> ", iter->i);
        iter = iter->next;
        while (iter != NULL)
        {
            printf("%d ", iter->i);
            iter = iter->next;
        }
        printf("\n");
    }
}
