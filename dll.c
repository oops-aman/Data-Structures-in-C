#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next,*prev;
}*head=0,*end=0,*t1,*t2;

void create()
{
    int ch=1;
    while(ch==1)
    {
        t1 = (struct node*)malloc(sizeof(struct node*));
        printf("Enter Data : ");
        scanf("%d",&t1->data);
        t1->next=0;
        t1->prev=0;
        if(head==0)
        {
            head=end=t1;
        }
        else
        {
            end->next=t1;
            end=t1;
        }
        printf("Want to insert more (1-Yes/0-No) : ");
        scanf("%d",&ch);
    }
}

void insert_beg()
{
    t1=(struct node*)malloc(sizeof(struct node*));
    printf("Enter data to insert : ");
    scanf("%d",&t1->data);
    if(head==0)
    {
        t1->next=0;
        t1->prev=0;
        head=t1;
    }
    else
    {
        t1->prev=0;
        t1->next=head;
        head->prev=t1;
        head=t1;
    }
}

void insert_end()
{
     t1=(struct node*)malloc(sizeof(struct node*));
     printf("Enter data to insert : ");
     scanf("%d",&t1->data);
     if(head==0)
     {
         t1->next=0;
         t1->prev=0;
         head=t1;
     }
     else
     {
         t2=head;
         while(t2->next!=0)
         {
             t2=t2->next;
         }
         t2->next=t1;
         t1->prev=t2;
         t1->next=0;
     }
}

void insert_mid()
{
    int pos,n=1;
     t1=(struct node*)malloc(sizeof(struct node*));
     printf("Enter data to insert : ");
     scanf("%d",&t1->data);
     t1->next=0;
     printf("Enter position to insert : ");
     scanf("%d",&pos);
     t2=head;
     while(t2!=0 && n<pos-1)
     {
         t2=t2->next;
         n++;
     }
     t1->next=t2->next;
     t1->prev=t2;
     t2->next=t1;
     t2->next->prev=t1;
}

void display()
{
    t1=head;
    while(t1!=0)
    {
        printf("%d -> ",t1->data);
        t1=t1->next;
    }
}

void del_beg()
{
    t1=head;
    head=head->next;
    head->prev=0;
    free(t1);
}

void del_end()
{
    t1=head;
    while(t1->next!=0)
    {
        t1=t1->next;
    }
    t1->prev->next=0;
    free(t1);
}

void del_mid()
{
    int pos,n=1;
    printf("Enter position to delete : ");
    scanf("%d",&pos);
    t1=head;
    t2=head;
    while(n<pos-1)
    {
        t1=t1->next;
        t2=t2->next;
        n++;
    }
    t1=t1->next;
    t2->next=t1->next;
    t1->next->prev=t2;
    free(t1);
}

int main()
{
    int ch2=1,ch3;
    while(ch2==1)
    {
        printf("\n1.Creation of LL\n2.Display\n3.Insert at beg\n4.Insert at end\n5.Insert at middle\n6.Del beg\n7.Del mid\n8.del end\n");
        printf("Enter your choice: ");
        scanf("%d",&ch3);
        switch(ch3)
        {
            case 1 : create();
                     break;

            case 2 : display();
                     break;

            case 3 : insert_beg();
                     break;

            case 4 : insert_end();
                     break;

            case 5 : insert_mid();
                     break;

            case 6 : del_beg();
                     break;
         
            case 7 : del_mid();
                     break;

            case 8 : del_end();
                     break;

            default : printf("Invalid choice ");
                      break;          
        }
        printf("\nEnter 1 to continue and 0 to exit : ");
        scanf("%d",&ch2);
    }
    return 0;
}