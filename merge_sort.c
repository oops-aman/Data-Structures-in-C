#include <stdio.h>  
  
/* Function to merge the subarrays of a[] */  
void merge(int arr[], int beg, int mid, int end)    
{    
    int i, j, k;  
    int n1 = mid - beg + 1;    
    int n2 = end - mid;    
      
    int LeftArray[n1], RightArray[n2]; //temporary arrays  
      
    /* copy data to temp arrays */  
    for (i = 0; i < n1; i++)    
    LeftArray[i] = arr[beg + i];    
    for (j = 0; j < n2; j++)    
    RightArray[j] = arr[mid + 1 + j];    
      
    i = 0; /* initial index of first sub-array */  
    j = 0; /* initial index of second sub-array */   
    k = beg;  /* initial index of merged sub-array */  
      
    while (i < n1 && j < n2)    
    {    
        if(LeftArray[i] <= RightArray[j])    
        {    
            arr[k] = LeftArray[i];    
            i++;    
        }    
        else    
        {    
            arr[k] = RightArray[j];    
            j++;    
        }    
        k++;    
    }    
    while (i < n1)    
    {    
        arr[k] = LeftArray[i];    
        i++;    
        k++;    
    }    
      
    while (j < n2)    
    {    
        arr[k] = RightArray[j];    
        j++;    
        k++;    
    }    
}    
  
void mergeSort(int arr[], int beg, int end)  
{  
    if (beg < end)   
    {  
        int mid = (beg + end) / 2;  
        mergeSort(arr, beg, mid);  
        mergeSort(arr, mid + 1, end);  
        merge(arr, beg, mid, end);  
    }  
}  
  
/* Function to print the array */  
void printArray(int arr[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", arr[i]);  
    printf("\n");  
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
    printArray(arr, n);  
    mergeSort(arr, 0, n - 1);  
    printf("\nSorted Array : \n");  
    printArray(arr, n);  
    return 0;  
}  