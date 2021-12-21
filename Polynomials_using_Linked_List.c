#include<stdio.h>
#include<stdlib.h>

struct poly
{
    int coeff,pow;
    struct poly *next;
}*t1,*t2;

void create()
{
    int flag=1;
    t1=(struct poly*)malloc(sizeof(struct poly*));
    do
    {
        printf("Enter coefficient : ");
        scanf("%d",&t1->coeff);
        printf("Enter power : ");
        scanf("%d",&t1->pow);
        printf("Want to insert more terms (1-Yes/0-No) : ");
        scanf("%d",&flag);
        if(flag==1)
        {
            t1->next=(struct poly*)malloc(sizeof(struct poly*));
            t1=t1->next;
            t1->next=0;
        }
    }while(flag==1);
}

void display(struct poly *head)
{
    t2=head;
    printf("%dx^%d",t2->coeff,t2->pow);
    t2=t2->next;
    if(t2!=0)
    {
        printf(" + ");
        display(t2);
    }
}

int main()
{
    struct poly *poly1,*poly2;
    printf("First Polynomial : \n");
    create(&poly1);
    printf("\nSecond Polynomial : \n");
    create(&poly2);

    printf("\n\nPolynomial 1 : ");
    display(poly1);
    printf("\nPolynomial 2 : ");
    display(poly2);
    return 0;
}