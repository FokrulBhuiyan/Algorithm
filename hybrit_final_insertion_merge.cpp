#include<iostream>
using namespace std;

void InsertionSort(int arr[], int low, int high)
{
    for (int i = low; i <= high; i++)
    {
        int key = arr[i];
        int j = i-1;

        while (j >= low && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
   }

   return;
}

int  quick(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;

            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return ( i + 1);
}

void hybridsortrec(int arr[], int  low,int  high)
{
    int size = high - low;

    if (size < 10)
    {
        InsertionSort(arr, low, high);
        return;
    }
    else{
    int  q = quick(arr, low, high);
    hybridsortrec(arr, low, q-1);
    hybridsortrec(arr, q + 1, high);
    }
    return;
}


void display(int arr[], int n)
{
   for (int i=0; i < n; i++)
       cout<<arr[i]<<" ";
}

int main()
{
    int n;
    cout<<"Enter Total Elements Number: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: "<<endl;
    for(int i = 0;i < n ;i++){
        cin>>arr[i];
    }
    hybridsortrec(arr, 0, n-1);
    display(arr, n);
    return 0;
}
