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
        printf("ENter data: ");
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
        printf("Want to inset more ? (Yes - 1/ NO - 0");
        scanf("%d",&ch);
    }
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
    printf("ENter position to insert: ");
    scanf("%d",&pos);
    t2=head;
    while(t2!=0 && n<pos-1)
    {
        t2=t2->next;
        n++;
    }
    t2->next=t1->next;
    t2->next=t1;
}

void insert_end()
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

void del_beg()
{
    t1=head;
    head=t1->next;
    t1->next=0;
    free(t1);
}

void del_end()
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

void del_mid()
{
    int n=1,pos2;
    printf("ENter position to delete : ");
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
        printf("Enter 1 to continue and 0 to exit : ");
        scanf("%d",&ch2);
    }
    return 0;
}
