#include <stdio.h>
#define MAX 50
int queue[MAX];
int rear = - 1,front = - 1;
 
void enqueue()
{
    int data;
    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        front = 0;
        printf("\nInset the element in queue : ");
        scanf("%d", &data);
        rear = rear + 1;
        queue[rear] = data;
    }
}

void dequeue()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("\nElement dequeued from queue is : %d\n", queue[front]);
        front = front + 1;
    }
}

void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("\nQueue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: enqueue();
                    break;

            case 2: dequeue();
                    break;

            case 3: display();
                    break;

            default: printf("Wrong choice \n");
                     break;
        } 
    } 
} 