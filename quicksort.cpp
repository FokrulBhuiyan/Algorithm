#include<iostream>
using namespace std;

int quick(int arr[],int low,int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j = low; j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quicksort(int arr[],int low,int high){
    if(low<high){
        int q = quick(arr,low,high);
        quicksort(arr,low,q-1);
        quicksort(arr,q+1,high);
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
quicksort(arr,0,n-1);

display(arr,n);
return 0;
}
