#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define initial 1
#define waiting 2
#define visited 3

int n;
int adj[MAX][MAX];
int state[MAX];
void enQueue(int vertex);
int deQueue();
int isEmptyQueue();
void BFS(int v);
void bfsTraversal();


int queue[MAX], front = -1, rear = -1;

void createGraph()
{
    int count, max_edge, origin, destination;
    printf("\nEnter number of vertices : ");
    scanf("%d",&n);
    max_edge = n*(n-1);
    for(count = 1; count <= max_edge; count++)
    {
        printf("Enter edge %d : ",count);
        scanf("%d %d",&origin,&destination);

        if(origin == -1 && destination == -1)
        {
            break;
        }
        else if(origin >= n || destination >= n || origin < 0 || destination < 0)
        {
            printf("\nInvalid Edge !");
        }
        else 
        {
            adj[origin][destination] = 1;
        }
    }
}

void enQueue(int vertex)
{
    if(rear == MAX-1)
    {
        printf("\nOverflow");
        return ;
    }
    else
    {
        if(front == -1)
        {
            front = 0;
        }
        rear = rear + 1;
        queue[rear] = vertex;
    }
}

int deQueue()
{
    if(front == -1 || front > rear)
    {
        printf("\nUnderflow");
        exit(1);
    }
    int delete_item = queue[front];
    front = front + 1;
    return delete_item;
}

int isEmptyQueue()
{
    if(front == -1 || front > rear)
        return 1;
    else
        return 0;
}

void bfsTraversal()
{
    int v;
    for(v = 0; v < n; v++)
    {
        state[v] = initial;
    }
    printf("\nEnter starting vertex for BFS : ");
    scanf("%d",&v);
    BFS(v);
}

void BFS(int v)
{
    int i;
    enQueue(v);
    state[v] = waiting;
    while(!isEmptyQueue())
    {
        v = deQueue();
        printf("%d ",v);
        state[v] = visited;
        for (i = 0; i < n; i++)
        {
            if(adj[v][i] == 1 && state[i] == initial)
            {
                enQueue(i);
                state[i] = waiting;
            }
        } 
    }
}

int main()
{
    createGraph();
    bfsTraversal();
    return 0;
}