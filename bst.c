#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
}*root = NULL;

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

struct node* minNode(struct node *root)
{
    if(root->left != NULL)
    {
        return minNode(root->left);
    }
    else
    {
        return root;
    }
}

struct node* delete(struct node *current, int item)
{
    if(current == NULL)
    {
        return NULL;
    }
    else
    {
        if(item < current->data)
        {
            current->left = delete(current->left, item);
        }
        else if(item >current->data)
        {
            current->right = delete(current->right, item);
        }
        else
        {
            if(current->left == NULL && current->right == NULL)
            {
                current = NULL;
            }
            else if(current->left == NULL)
            {
                current = current->right;
            }
            else if(current->right == NULL)
            {
                current = current->left;
            }
            else
            {
                struct node *temp = minNode(current->right);
                current->data = temp->data;
                current->right = delete(current->right, temp->data);
            }
        }
        return current;
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

void display(struct node *temp, int level)
{
    int i;
    if(temp != NULL)
    {
        display(temp->right, level+1);
        printf("\n");
        for(i = 0; i < level; i++)
        {
            printf("  ");
        }
        printf("%d",temp->data);
        display(temp->left, level+1);
    }
}

int main()
{
    int ch1 = 1,ch2,ch3,num;
    while(ch1 == 1)
    {
        printf("1.Insertion \n2.Deletion \n3.Traversal \n4.Display \n5.Exit");
        printf("\nEnter your choice (1-5) : ");
        scanf("%d",&ch2);
        switch(ch2)
        {
            case 1 : printf("\nEnter data to be inserted : ");
                     scanf("%d",&num);
                     insert(num);
                     break;

            case 2 : printf("Enter data to be deleted : ");
                     scanf("%d",&num);
                     delete(root, num);
                     break;

            case 3 : printf("\n1.Inorder \n2.Preorder \n3.Postorder");
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