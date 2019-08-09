#include<iostream>
using namespace std;

void merge(int arr[], int pivot, int mid, int high){
    int array[high+1];
    int i = pivot, k = pivot, j = mid+1;

    while(i<=mid && j<=high){
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
    while(i<=mid){
        array[k] = arr[i];
            k++;
            i++;
    }
    while(j<=high){
        array[k] = arr[j];
            k++;
            j++;
    }
    for(i = pivot; i<k;i++){
        arr[i] = array[i];
    }
}

void mergesort(int arr[],int pivot,int high){
    if(pivot<high){
        int mid = pivot+(high-pivot)/2;
        mergesort(arr,pivot,mid );
        mergesort(arr,mid+1,high);
        merge(arr,pivot,mid,high);
    }
}

void display(int arr[],int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
int arr[100],n;
cout<<"Enter elements value: ";
cin>>n;
cout<<"Enter elements: "<<endl;
for(int i=0;i<n;i++){
    cin>>arr[i];
}
mergesort(arr,0,n-1);

display(arr,n);
return 0;
}
