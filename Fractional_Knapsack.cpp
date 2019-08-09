#include<iostream>
using namespace std;

double fractionalknapsack(int w,int arr[],int n){
sort(a,a+n,cmp);
int curweight = 0;
double finalvalue=0.0;

for(int i = 0; i<n;i++){
    if(curweight+a[i].weight<=w){
        curweight = curweight+a[i].weight;
        finalvalue = finalvalue+a[i].value;
    }
    else{
        int remain = w - curweight;
        finalvalue = finalvalue+a[i].value*((double)remain / arr[i].weight);
        break;
    }
}
return finalvalue;
}

int main(){
int w, n, a[100];
cout<<"Enter value of n and w: ";
cin>>n>>w;
cout<<"Enter elements: "<<endl;
for(int i = 0; i<n ;i++){
    cin>>a[i];
}
cout<<fractionalknapsack(w, a, n);
return 0;
}
