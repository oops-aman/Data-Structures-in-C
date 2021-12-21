#include<stdio.h>
#include<stdlib.h>

int getMax(int arr[], int n)
{
    int mx = arr[0];
    int i;
    for(i = 1; i < n; i++)
    {
        if(arr[i] > mx)
        {
            mx = arr[i];
        }
    }
    return mx;
}

void countingSort(int arr[], int n, int place)
{
    int output[n+1], i;
    int count[10] = {0};

    //count of elements
    for(i = 0; i < n; i++)
    {
        count[(arr[i] / place) % 10]++;
    }

    //calculate cumulative frequency
    for(i = 1; i < 10; i++)
    {
        count[i] += count[i-1];
    }

    //place elements in sorted order
    for(i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }

    for(i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n)
{
    int max = getMax(arr, n); //maximum element of array

    int place;
    for(place = 1; max/place > 0; place *= 10)
    {
        countingSort(arr, n, place);
    }
}

int main()
{
    int n, i;
    printf("\nEnter number of elements : ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter array elements : ");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    radixSort(arr, n);
    printf("\nSorted Array is : \n");
    for(i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}