#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head=0,*end=0,*t1,*t2;

void create()
{
    int ch=1;
    while(ch==1)
    {
        t1=(struct node*)malloc(sizeof(struct node*));
        printf("Enter data : ");
        scanf("%d",&t1->data);
        t1->next=0;
        if(head==0)
        {
            head=end=t1;
        }
        else
        {
            end->next=t1;
            end=t1;
        }
        end->next=head;
        printf("Want to insert more ?(1-Yes/0-No) : ");
        scanf("%d",&ch);
    }
}

void insert_beg()
{
    t1=(struct node*)malloc(sizeof(struct node*));
    printf("Enter data to be inserted : ");
    scanf("%d",&t1->data);
    if(head==0)
    {
        head=end=t1;
        t1->next=head;
    }
    else
    {
        t2=head;
        while(t2->next!=head)
        {
            t2=t2->next;
        }
        t1->next=head;
        t2->next=t1;
        head=t1;
    }
}

void insert_end()
{
    t1=(struct node*)malloc(sizeof(struct node*));
    printf("Enter data to be inserted : ");
    scanf("%d",&t1->data);
    t1->next=0;
    t2=head;
    while(t2->next!=head)
    {
        t2=t2->next;
    }
    t2->next=t1;
    t1->next=head;
}

void insert_mid()
{
    int pos,n=1;
    t1=(struct node*)malloc(sizeof(struct node*));
    printf("Enter data to insert : ");
    scanf("%d",&t1->data);
    printf("Enter position to insert : ");
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

void del_beg()
{
    t1=head;
    while(t1->next!=head)
    {
        t1=t1->next;
    }
    t1->next=head->next;
    free(head);
    head=t1->next;
}

void del_end()
{
    t1=head;
    do
    {
        t1=t1->next;
    }while(t1->next->next!=head);
    end=t1;
    t1=t1->next;
    end->next=head;
    free(t1);
}

void del_mid()
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

void display()
{
    t1=head;
    if(head==0)
    {
        return;
    }
    else
    {
        do
        {
            printf("%d -> ",t1->data);
            t1=t1->next;
        } while (t1!=head);
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
                     printf("\n1.Insertion at the beginning \n2.Insertion at the end \n3.Insertion at desired location\n");
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
                      printf("\n1.Deletion at beginning \n2.Deletion at the end \n3.Deletion at desired location\n");
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
