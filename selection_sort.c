#include<stdio.h>
#include<stdlib.h>

void selection_sort(int arr[],int n)
{
    int count = 0;
    int i,j,k;
    for(i = 0; i < n; i++)
    {
        int small = arr[i];
        int pos = i;
        for(j = i+1; j < n; j++)
        {
            if(arr[j] < small)
            {
                small = arr[j];
                pos = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }
}

int main()
{
    int n,i;
    printf("Entetr the size of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements : \n");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    selection_sort(arr,n);
    printf("\nSorted Array : \n");
    for(i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}