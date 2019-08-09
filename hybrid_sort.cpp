#include<iostream>
using namespace std;

void insertionsort(int arr[], int low, int high)
{

    for (int i = low+1; i < high; i++)
    {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j--;
        }
        arr[j+1] = key;
   }

   return;
}

int partition(int arr[], int low, int high)
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

int medianofthree(int a, int b, int c)
{
    if (a < b && b < c)
        return (b);

    if (a < c && c <= b)
        return (c);

    if (b <= a && a < c)
        return (a);

    if (b < c && c <= a)
        return (c);

    if (c <= a && a < b)
        return (a);

    if (c <= b && b <= c)
        return (b);
}

void introsort(int arr[], int low, int high){
    int size = high - low;
    if(size < 16){
        insertionsort(arr,low,high);
        return;
    }
    /*if (depthlimit == 0){
        make_heap(low, high+1);
        sort_heap(low, high+1);
        return;}*/

    int pivot = medianofthree(low, low+size/2,high);

    swap(pivot,high);
    int partitionvalue = partition(arr,low,high);
    introsort(arr,low,partitionvalue-1);
    introsort(arr,partitionvalue+1,high);
}

/*void introsort(int arr[],int *low, int *high){
    int depthlimit = 2*log(high - low);
    introsortrec(arr, low, high, depthlimit);
    return;
}*/

void display(int arr[],int n){
    for(int i = 0;i < n;i++){
        cout<<arr[i]<<" ";
    }

}

int main(){
int n,arr[100],i;
cin>>n;
cout<<"Ente the elements: ";
for(i = 0;i < n;i++){
    cin>>arr[i];
}
display(arr,n);
introsort(arr,0,n-1);
display(arr,n);

return 0;
}
