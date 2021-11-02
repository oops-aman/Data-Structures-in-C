#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node *front = NULL;
struct node *rear = NULL;
void enqueue(int d) //Insert elements in Queue
{
	struct node* t1;
	t1 = (struct node*)malloc(sizeof(struct node));
	t1->data = d;
	t1->next = NULL;
	if((r==NULL)&&(f==NULL))
	{
		front = rear = t1;
		rear->next = front;
	}
	else
	{
		rear->next = t1;
		rear = t1;
		t1->next = front;
	}
} 
void dequeue() // Delete an element from Queue
{
	struct node* t;
	t = front;
	if((front==NULL)&&(rear==NULL))
		printf("\nQueue is Empty");
	else if(front == rear){
		front = rear = NULL;
		free(t);
	}
	else{
		front = front->next;
		rear->next = front;
		free(t);
	}
	
	
}
void print(){ // Print the elements of Queue
	struct node* t;
	t = front;
	if((front==NULL)&&(rear==NULL))
		printf("\nQueue is Empty");
	else{
		do{
			printf("\n%d",t->data);
			t = t->next;
		}while(t != front);
	}
}
int main()
{
	int opt,n,i,data;
	printf("Enter Your Choice:-");
	do{
		printf("\n\n1 for Insert the Data in Queue\n2 for show the Data in Queue \n3 for Delete the data from the Queue\n0 for Exit");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("\nEnter the number of data");
				scanf("%d",&n);
				printf("\nEnter your data");
				i=0;
				while(i<n){
					scanf("%d",&data);
					enqueue(data);
					i++;
				}
				break;
			case 2:
				print();
				break;
			case 3:
				 dequeue();
				break;
			case 0:
				break;
			default:
				printf("\nIncorrect Choice");
			
		}
	}while(opt!=0);
return 0;
}