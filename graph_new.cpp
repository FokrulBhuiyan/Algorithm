#include<iostream>
using namespace std;


void addvertex(int graph[100][100],int node,int node1){
    for(int i = node+1;i<=node1;i++){
        for(int j = node+1;j<=node1;j++){
            graph[i][j]= 0;
        }
    }
    for(int i = 1;i<=node1;i++){
        for(int j = 1;j<=node1;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

void addedge(int aedge,int graph[100][100],int edge,int node1){
    int edge1 = edge+aedge,x,y;
    for(int i = edge+1;i<=edge1;i++){
        cout<<"Enter connection in node a and b"<<endl;
        cin>>x>>y;
        graph[x][y]= 1 ;
    }
    for(int i = 1;i<=node1;i++){
        for(int j = 1;j<=node1;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }

}
void isreachable(int graph[100][100]){
    int edge,x,y;
    cout<<"Enter how many edge you check: ";
    cin>>edge;
    for(int i = 1;i<=edge;i++){
        cout<<"Enter them: "<<endl;
        cin>>x>>y;
        if(graph[x][y]==1){
            cout<<"Reachable"<<endl;
        }
        else{
            cout<<"Not Reachable"<<endl;
        }
    }
    }

int main(){
    int node,edge,x,y,av,aedge,source;
    int graph[100][100];
    cout<<"Enter the element value: ";
    cin>>node;
    for(int i = 1;i<=node;i++){
        for(int j = 1;j<=node;j++){
            graph[i][j]= 0;
        }
    }
    cout<<"Enter edge: ";
    cin>>edge;
    for(int i = 1;i<=edge;i++){
        cout<<"Enter connection in node a and b"<<endl;
        cin>>x>>y;
        graph[x][y]= 1 ;
    }
    for(int i = 1;i<=node;i++){
        for(int j = 1;j<=node;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    cin>>av;
    int node1 = node + av;
    addvertex(graph,node,node1);


    cout<<"Enter add edge: ";
    cin>>aedge;

    addedge(aedge,graph,edge,node1);

    isreachable(graph);
}
