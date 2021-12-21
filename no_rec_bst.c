#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 50

struct node
{
    int data;
    struct node *left;
    struct node *right;
}*root = NULL;

struct node *queue[MAX];
int front = -1, rear = -1;
void insert_queue(struct node *item);
struct node *del_queue();
int queue_empty();

struct node *stack[MAX];
int top = -1;
void push_stack(struct node *item);
struct node *pop_stack();
int stack_empty();

struct node* createNode(int item)
{
    struct node *newNode=(struct node*)malloc(sizeof(struct node*));
    newNode->data = item;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(int item)
{
    struct node *newNode = createNode(item);
    if(root == NULL)
    {
        root=newNode;
        return;
    }

    else
    {
        struct node *current = root,*parent = NULL;
        while(true)
        {
            parent = current;
            if(item < current->data)
            {
                current = current->left;
                if(current == NULL)
                {
                    parent->left = newNode;
                    return;
                }
            }
            else
            {
                current = current->right;
                if(current == NULL)
                {
                    parent->right = newNode;
                    return;
                }
            }
        }
    }
}

void inorder(struct node *temp)
{
    if(root == NULL)
    {
        printf("\nTree is empty !");
        return;
    }
    if(temp != NULL)
    {
        inorder(temp->left);
        printf("%d ",temp->data);
        inorder(temp->right);
    }
}

void preorder(struct node *temp)
{
    if(root == NULL)
    {
        printf("\nTree is empty !");
        return;
    }
    if(temp != NULL)
    {
        printf("%d ",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void postorder(struct node *temp)
{
    if(root == NULL)
    {
        printf("\nTree is empty !");
        return;
    }
    if(temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ",temp->data);
    }
}

void insert_queue(struct node *item)
{
    if(rear == MAX-1)
    {
        printf("Queue Overflow\n");
        return;
    }

    if(front == -1)  
    {
        front = 0;
    }
    rear = rear + 1;
    queue[rear] = item ;
}

struct node *del_queue()
{
        struct node *item;
        if(front == -1 || front == rear+1)
        {
            printf("Queue Underflow\n");
            return 0;
        }
        item = queue[front];
        front = front+1;
        return item;
}

int queue_empty()
{
        if(front == -1 || front == rear+1 )
            return 1;
        else
            return 0;
}


void push_stack(struct node *item)
{
    if(top == (MAX-1))
    {
        printf("Stack Overflow\n");
        return;
    }
    top = top+1;
    stack[top] = item;
}

struct node *pop_stack()
{
    struct node *item;
    if(top == -1)
    {
        printf("Stack Underflow....\n");
        exit(1);
    }
    item = stack[top];
    top = top-1;
    return item;
}

int stack_empty()
{
    if(top == -1)
        return 1;
    else
        return 0;
} 


void display(struct node *ptr, int level)
{
    int i;
    if(ptr == NULL )
        return;
    else
    {
        display(ptr->right, level+1);
        printf("\n");
        for (i = 0; i < level; i++)
            printf("    ");
        printf("%d", ptr->data);
        display(ptr->left, level+1);
    }
}

void no_rec_pre(struct node *root)
{
    struct node *ptr = root;
    if(ptr == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    push_stack(ptr);
    while( !stack_empty() )
    {
        ptr = pop_stack();
        printf("%d  ",ptr->data);
        if(ptr->right != NULL)
        {
            push_stack(ptr->right);
        }
        if(ptr->left != NULL)
        {
            push_stack(ptr->left);
        }
    }
    printf("\n");
}

void no_rec_in(struct node *root)
{
    struct node *ptr=root;

    if(ptr == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    while(1)
    {
        while(ptr->left != NULL )
        {
            push_stack(ptr);
            ptr = ptr->left;
        }

        while(ptr->right == NULL)
                {
                        printf("%d  ",ptr->data);
                        if(stack_empty())
                        {
                                return;
                        }
                        ptr = pop_stack();
                }
                printf("%d  ",ptr->data);
                ptr = ptr->right;
        }
        printf("\n");
}

void no_rec_post(struct node *root)
{
    struct node *ptr = root;
    struct node *q;

    if(ptr == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    q = root;
    while(1)
    {
        while(ptr->left != NULL)
        {
            push_stack(ptr);
            ptr = ptr->left;
        }

        while(ptr->right == NULL || ptr->right == q)
        {
            printf("%d  ",ptr->data);
            q = ptr;
            if( stack_empty() )
            {
                return;
            }
            ptr = pop_stack();
        }
        push_stack(ptr);
        ptr = ptr->right;
    }
    printf("\n");
}

int main()
{
    int ch1 = 1,ch2,ch3,num;
    while(ch1 == 1)
    {
        printf("1.Insertion \n2.Traversal using recursion \n3.Traversal without recursion \n4.Display \n5.Exit");
        printf("\nEnter your choice (1-5) : ");
        scanf("%d",&ch2);
        switch(ch2)
        {
            case 1 : printf("\nEnter data to be inserted : ");
                     scanf("%d",&num);
                     insert(num);
                     break;

            case 2 : printf("\n1.Inorder \n2.Preorder \n3.Postorder");
                     printf("\nEnter your choice (1-3) : ");
                     scanf("%d",&ch3);
                     switch(ch3)
                     {
                         case 1 : inorder(root);
                                  break;

                        case 2 : preorder(root);
                                 break;

                        case 3 : postorder(root);
                                 break;

                        default : printf("\nInvalide Choice !");
                                  break;          
                     }
                     break;

            case 3 : printf("\n1.Inorder \n2.Preorder \n3.Postorder");
                     printf("\nEnter your choice (1-3) : ");
                     scanf("%d",&ch3);
                     switch(ch3)
                     {
                         case 1 : no_rec_in(root);
                                  break;

                        case 2 : no_rec_pre(root);
                                 break;

                        case 3 : no_rec_post(root);
                                 break;

                        default : printf("\nInvalid Choice !");
                                  break;          
                     }
                     break;

            case 4 : display(root,1);
                     break;

            case 5 : exit(0);
                     break;

            default : printf("\nInvalid Choice !");
                      break;
        }
        printf("\nWant to continue ? (1-Yes/0-No) : ");
        scanf("%d",&ch1);
    }
    return 0;
}