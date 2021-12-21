#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int max = i;
    int leftChild = 2 * i +1;
    int rightChild= 2 * i + 2;
    
    //if lefft child is greater than root
    if(leftChild < n && arr[leftChild] > arr[max])
    {
        max = leftChild;
    }
    //if right child is greater than root
    if(rightChild < n && arr[rightChild] > arr[max])
    {
        max = rightChild;
    }

    //if max is not root
    if(max != i)
    {
        swap(&arr[i], &arr[max]);
        heapify(arr, n, max);
    }
}

void heapSort(int arr[], int n)
{
    //building heap
    int i;
    for(i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    //extract elements from heap
    for(i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int n, i;
    printf("\nEnter number of elements : ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter array elements : \n");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    heapSort(arr, n);
    printf("\n\nSorted Array : \n");
    for(i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}