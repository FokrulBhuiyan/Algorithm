#include<iostream>
using namespace std;

int main(){
    int x,y,source;
    cout<<"Enter the nodes: ";
    cin>>nodes;
    for( int i = 1; i<=nodes;i++){
    for(int j = 1;j<=nodes;j++){
    graph[i][j]=DISCONNECTED;
    }
    }
    cout<<"Enter the edge: ";
    cin>>edge;
    for( int i = 1; i<=edge;i++){
    cout<<"Enter the vertexes for edge: ";
    cin>>x>>y;
    graph[x][y]=graph[y][x]=CONNECTED;
    }
    cout<<"Give source: ";
    cin>>source;
    dfs(source,nodes);

}
