#include<iostream>
using namespace std;

double fractionalknapsack(int w[],int v[],int n,int cap){
    for(int i =0;i<n;i++){
    if(cap==0){
        return 0;
    }
    else{
    int max = 0;
    int x = 0;
    if(w>0 && max < v[i]/w[i]){
        max = v[i]/w[i];
        int a = min(w[i],cap);
        int x = x + a*max;
        w[i]=w[i]-a;
        v[i]=v[i]+a;
        cap = cap - a;
        return v[i];
    }
    }
    }
}

int main(){
int  n, w[100],v[100],cap;
cout<<"Enter value of n and capacity: ";
cin>>n>>cap;
cout<<"Enter elements: "<<endl;
for(int i = 0; i<n ;i++){
    cin>>w[i]>>v[i];
}


cout<<fractionalknapsack(w, v, n,cap);
return 0;
}
