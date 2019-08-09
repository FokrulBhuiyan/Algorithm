#include<iostream>
using namespace std;

int binarysearch(int arr[],int sv,int low,int high){
    if(low<=high){
    int mid = low + (high - low)/2;
    if(arr[mid] == sv){
        return mid;
    }
    else if(arr[mid]>sv){
        binarysearch(arr,sv,low,mid-1);
    }
    else{
         binarysearch(arr,sv,mid+1,high);
    }
    }
        return 0;
}

int main(){
int arr[100],n,svalue;
cout<<"Enter elements value: ";
cin>>n;
cout<<"Enter elements: "<<endl;
for(int i=0;i<n;i++){
    cin>>arr[i];
}
cout<<"Enter Searching Value: ";
cin>>svalue;
cout<<endl;
int result = binarysearch(arr,svalue,0,n-1);
if(result == 0){
    cout<<"Not found";
}
else{
     cout<<"Found, Index NO: "<<result;
}
return 0;
}
