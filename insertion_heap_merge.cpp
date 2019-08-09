#include<bits/stdc++.h>
using namespace std;

// A utility function to swap the values pointed by
// the two pointers
void swapValue(int *a, int *b)
{
    int *temp = a;
    a = b;
    b = temp;
    return;
}

/* Function to sort an array using insertion sort*/
void InsertionSort(int arr[], int *low, int *high)
{
    // Get the left and the right index of the subarray
    // to be sorted
    int left = low - arr;
    int right = high - arr;

    for (int i = left+1; i <= right; i++)
    {
        int key = arr[i];
        int j = i-1;

       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= left && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
   }

   return;
}

// A function to parition the array and return
// the partition point
void merge(int *arr, int *pivot, int *mid, int *high){
    int array[100];
    int i = pivot - arr, k = pivot - arr, j = mid+1-arr;

    while(i<=*mid && j<=*high){
        if(arr[i] <= arr[j]){
            array[k] = arr[i];
            i++;
        }
        else{
            array[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i<=*mid){
        array[k] = arr[i];
            k++;
            i++;
    }
    while(j<=*high){
        array[k] = arr[j];
            k++;
            j++;
    }
    for(i = *pivot; i<k;i++){
        arr[i] = array[i];
    }
}

// A function that find the middle of the
// values pointed by the pointers a, b, c
// and return that pointer
/*int *MedianOfThree(int * a, int * b, int * c)
{
    if (*a < *b && *b < *c)
        return (b);

    if (*a < *c && *c <= *b)
        return (c);

    if (*b <= *a && *a < *c)
        return (a);

    if (*b < *c && *c <= *a)
        return (c);

    if (*c <= *a && *a < *b)
        return (a);

    if (*c <= *b && *b <= *c)
        return (b);
}*/

// A Utility function to perform intro sort
void IntrosortUtil(int arr[], int * low,int * high,int depthLimit)
{
    // Count the number of elements
    int size = high - low;

      // If partition size is low then do insertion sort
    if (size < 16)
    {
        InsertionSort(arr, low, high);
        return;
    }

    // If the depth is zero use heapsort
    if (depthLimit == 0)
    {
        make_heap(low, high+1);
        sort_heap(low, high+1);
        return;
    }

    // Else use a median-of-three concept to
    // find a good pivot
    //int * pivot = MedianOfThree(low, low+size/2, high);

    // Swap the values pointed by the two pointers

    int * mid = low+(high-low)/2;
        /*mergesort(arr,pivot,mid );
        mergesort(arr,mid+1,high);
        merge(arr,pivot,mid,high);*/
   // Perform Quick Sort
    //int * partitionPoint = Partition(arr, low-arr, high-arr);
    IntrosortUtil(arr, low, mid-1, depthLimit - 1);
    IntrosortUtil(arr, mid + 1, high, depthLimit - 1);
    merge(arr,low,mid,high);

    return;
}

/* Implementation of introsort*/
void Introsort(int arr[], int *begin, int *end)
{
    int depthLimit = 2 * log(end-begin);

    // Perform a recursive Introsort
    IntrosortUtil(arr, begin, end, depthLimit);

      return;
}

// A utility function ot print an array of size n
void printArray(int arr[], int n)
{
   for (int i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}

// Driver program to test Introsort
int main()
{
    int arr[] = {3, 1, 23, -9, 233, 23, -313, 32, -9};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Pass the array, the pointer to the first element and
    // the pointer to the last element
    Introsort(arr, arr, arr+n-1);
    printArray(arr, n);

    return(0);
}
