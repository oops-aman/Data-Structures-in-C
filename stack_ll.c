#include<stdio.h>
#include<stdlib.h>

struct node   
{  
int data;  
struct node *next;  
}*head,*t1;

void push ()  
{  
    int data;  
    t1 = (struct node*)malloc(sizeof(struct node));   
    if(t1 == NULL)  
    {  
        printf("Not able to push the element");   
    }  
    else   
    {  
        printf("Enter the data : ");  
        scanf("%d",&data);  
        if(head==NULL)  
        {         
            t1->data = data;  
            t1 -> next = NULL;  
            head=t1;  
        }   
        else   
        {  
            t1->data = data;  
            t1->next = head;  
            head=t1;  
               
        }  
    }  
}  
  
void pop()  
{  
    int item;  
    struct node *t1;  
    if (head == NULL)  
    {  
        printf("Underflow");  
    }  
    else  
    {  
        item = head->data;  
        t1 = head;  
        head = head->next;  
        free(t1);  
    }  
} 

void display()  
{  
    int i;  
    struct node *t1;  
    t1=head;  
    if(t1 == NULL)  
    {  
        printf("Stack is empty\n");  
    }  
    else  
    {  
        printf("Printing Stack elements :\n");  
        while(t1!=NULL)  
        {  
            printf("%d ",t1->data);  
            t1 = t1->next;  
        }  
    }  
} 

int isEmpty() 
{
    return head == NULL;
}
 
int peek()
{
    if (!isEmpty(head)) {
        return head->data;
    }
}
  
int main ()  
{  
    int x,choice;     
    printf("\n---------Stack operations using linked list---------\n");  
    while(1)  
    {  
        printf("\n\nChose one from the below options...\n");  
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display");  
        printf("\nEnter your choice :\n");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1: push();  
                    break;  

            case 2: pop();  
                    break;  
            
            case 3: x = peek();
                    printf("Top Element is : %d",x);
                    break;
        
            case 4: display();
                    break;

            default: printf("Please Enter valid choice ");  
                     break;
        }
    }
    return 0;  
}  

 




