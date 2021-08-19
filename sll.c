#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*head=0,*t1,*t2,*end=0;

void create()
{
    int ch=1;
    while(ch==1)
    {
        t1= (struct Node*)malloc(sizeof(struct Node*));
        printf("Enter data: ");
        scanf("%d",&t1->data);
        t1->next=0;
        if(head==0)
        {
            head=end=t1;
        }
        else
        {
            end->next=t1;
            end=end->next;
        }
        printf("Want to inset more ? (Yes - 1/ NO - 0) :");
        scanf("%d",&ch);
    }
}

void display()
{
    if(head==0)
    {
        printf("List is empty!!");
    }
    else
    {
        int count=nodeCount();
        t1=head;
        while(t1!=0)
        {
            printf("%d -> ",t1->data);
            t1=t1->next;
        }
        printf("\nThe number of nodes is : %d",count);
    }
}

int nodeCount()
{
    int nc;
    t1=head;
    while(t1!=0)
    {
        nc++;
        t1=t1->next;
    }
    return nc;
}

void insert_beg()
{
    t1 = (struct Node*)malloc(sizeof(struct Node*));
    printf("Enter data to insert: ");
    scanf("%d",&t1->data);
    t1->next=0;
    if(head==0)
    {
        head=end=t1;
    }
    else
    {
        t1->next=head;
        head=t1;
    }
}

void insert_mid()
{
    int pos,n=1;
    t1=(struct Node*)malloc(sizeof(struct Node*));
    printf("Enter data to insert : ");
    scanf("%d",&t1->data);
    t1->next=0;
    printf("Enter position to insert: ");
    scanf("%d",&pos);
    t2=head;
    while(t2!=0 && n<pos-1)
    {
        t2=t2->next;
        n++;
    }
    t1->next=t2->next;
    t2->next=t1;
}

void insert_end()
{
    if(head==0)
    {
        printf("List is empty!");
    }
    else
    {
        t1=(struct Node*)malloc(sizeof(struct Node*));
        printf("Enter data to insert: ");
        scanf("%d",&t1->data);
        t1->next=0;
        t2=head;
        while(t2->next!=0)
        {
            t2=t2->next;
        }
        t2->next=t1->next;
        t2->next=t1;
    }
}

void del_beg()
{
    if(head==0)
    {
        printf("List is empty!!");
    }
    else
    {
        t1=head;
        head=t1->next;
        t1->next=0;
        free(t1);
    }
    
}

void del_end()
{
    if(head==0)
    {
        printf("List is empty !");
    }
    else
    {
        t1=head;
        while(t1->next->next!=0)
        {
            t1=t1->next;
        }
        end=t1;
        t1=t1->next;
        end->next=0;
        free(t1);
    }
}

void del_mid()
{
    if(head==0)
    {
        printf("List is empty!!");
    }
    else
    {
        int n=1,pos2;
        printf("Enter position to delete : ");
        scanf("%d",&pos2);
        t1=head;
        t2=head;
        while(n<pos2-1)
        {
            t1=t1->next;
            t2=t2->next;
            n++;
        }
        t2=t2->next;
        t1->next=t2->next;
        t2->next=0;
        free(t2);
    }
}

int main()
{
    int ch2=1,ch3,x,p;
    while(ch2==1)
    {
        printf("\n1.Creation of Linked List \n2.Insertion \n3.Deletion \n4.Display");
        printf("\nEnter your choice: ");
        scanf("%d",&ch3);
        switch(ch3)
        {
            case 1 : create();
                     break;

            case 2 : printf("------Insertion-------");
                     printf("\n5.Insertion at the beginning \n6.Insertion at the end \n7.Insertion at desired location\n");
                     printf("Enter your choice (1-3): ");
                     scanf("%d",&x);
                     switch(x)
                     {
                        case 1 : insert_beg();
                                  break;

                        case 2 : insert_end();
                                 break;

                        case 3 : insert_mid();
                                 break;

                        default : printf("Invalid Choice !\n");
                                  break;
                     }
                     break;
                     
            case 3 :  printf("------Deletion------");
                      printf("\n8.Deletion at beginning \n9.Deletion at the end \n10.Deletion at desired location\n");
                      printf("Enter your choice (1-3) : ");
                      scanf("%d",&p);
                      switch (p)
                      {
                      case 1 : del_beg();
                               break;
                      
                      case 2 : del_end();
                               break;

                      case 3 : del_mid();
                               break;
                
                      default : printf("Invalid Choice !");
                                break;
                      }
                      break;

            case 4 : display();
                     break;

            default : printf("Invalid choice ");
                      break;          
        }
        printf("\nEnter 1 to continue and 0 to exit : ");
        scanf("%d",&ch2);
    }
    return 0;
}
