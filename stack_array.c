#include<stdio.h>
#include<stdlib.h>
 
#define MAX 50 //Maximum number of elements that can be stored
 
int top=-1,stack[MAX];
void push();
void pop();
void peek();
int isempty();
void display();
 
int main()
{
    int ch,x;
    while(1) 
    {
        printf("\n*** Stack Menu ***");
        printf("\n\n1.Push\n2.Pop\n3.Peek\n4.IsEmpty\n5.Display");
        printf("\n\nEnter your choice(1-5):");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push();
                    break;
            
            case 2: pop(); 
                    break;
            
            case 3:  peek();
                     break;

            case 4: x=isempty();
                    if(x==0)
                    {
                        printf("\nThe stack is empty!");
                    }
                    break;
            
            case 5: display();
                    break;
                     
            default: printf("\nWrong Choice!!");
                     break;
        }
    }
}
 
void push()
{
    int val;
    if(top==MAX-1)
    {
        printf("\nOverflow");
    }
    else
    {
        printf("\nEnter element to push:");
        scanf("%d",&val);
        top=top+1;
        stack[top]=val;
    }
}
 
void pop()
{
    if(top==-1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nDeleted element is %d",stack[top]);  
        top=top-1;
    }
}
 
void peek()
{
    printf("Top Element is: %d",stack[top]);
}

int isempty() 
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
      return 0;
    }
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("\nStack is empty!!");
    }
    else
    {
        printf("\nStack is...\n");
        for(i=top;i>=0;--i)
        printf("%d\n",stack[i]);
    }
}