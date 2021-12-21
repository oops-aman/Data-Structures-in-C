#include<stdio.h>
#include<stdlib.h>

void quick_sort(int arr[], int low, int high)
{
    int pivot, i, j, temp;
    if(low < high)
    {
        pivot = low;
        i = low; 
        j = high;
        while(i < j)
        {
            while(arr[i] <= arr[pivot] && i <= high)
            {
                i++;
            }
            while(arr[j] > arr[pivot])
            {
                j--;
            }
            if(i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
            temp = arr[j];
        arr[j] = arr[pivot];
        arr[pivot] = temp;
        quick_sort(arr, low, j-1);
        quick_sort(arr, j+1, high);
    }
}

int main()
{
    int n, i;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter array elements : \n");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    quick_sort(arr, 0, n-1);
    printf("\nSorted Array is : \n");
    for(i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}