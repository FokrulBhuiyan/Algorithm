#include<iostream>
using namespace std;
#define range 9

void countsort(int arr[],int n){
    int count[range+1],b[range+1];
    for(int i = 0;i<range+1;i++){
        count[i] = 0;
    }
    for(int i = 0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i = 1;i<=range;i++){
        count[i]= count[i]+count[i-1];
    }
    for(int i = 0;i<n;i++){
        b[count[arr[i]]-1]= arr[i];
         count[arr[i]]--;
    }
    for (int i = 0; i<n ; i++)
        arr[i] = b[i];
    delete count;
    delete b;
}

void dispaly(int arr[],int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){

int arr[100],n;
cout<<"Enter the value where n<9: ";
cin>>n;
cout<<"Enter the elements: "<<endl;
for(int i = 0; i<n ; i++){
    cin>>arr[i];
}
countsort(arr,n);
dispaly(arr,n);
return 0;
}
