#include<stdio.h>   
#include<stdlib.h>  
struct node   
{  
    int data;   
    struct node *next;  
} *front,*rear,*ptr; 

void enQueue()
{ 
    int item;    
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    else  
    {   
        printf("\nEnter value : ");  
        scanf("%d",&item);  
        ptr -> data = item;  
        if(front == NULL)  
        {  
            front = ptr;  
            rear = ptr;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   
        {  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
        }  
    }  
}

void deQueue()
{
    struct node *ptr;  
    if(front == NULL)  
    {  
        printf("\nUNDERFLOW\n");  
        return;  
    }  
    else   
    {  
        ptr = front;  
        front = front -> next;  
        free(ptr);  
    }  
} 

void display()
{  
    ptr = front;      
    if(front == NULL)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nPrinting values : \n");  
        while(ptr != NULL)   
        {  
            printf("\n%d ",ptr -> data);  
            ptr = ptr -> next;  
        }  
    } 
}
int main ()  
{  
    int choice;   
    while(1)   
    {      
        printf("\n1.Insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");  
        printf("\nEnter your choice :");  
        scanf("%d",& choice);  
        switch(choice)  
        {  
            case 1: enQueue();  
                    break;  
            
            case 2: deQueue();  
                    break;  
            
            case 3: display();  
                    break; 

            case 4: exit(0);  
                    break; 

            default: printf("\nEnter valid choice??\n");  
                     break;
        }  
    }
    return 0;  
}  