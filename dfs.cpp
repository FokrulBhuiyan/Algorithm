#include<iostream>
using namespace std;
#define unvisited -1
#define marked 0
#define visited 1
#define CONNECTED 1
#define DISCONNECTED 0


int graph[100+1][100+1];

int stack[100],head=0,tail=0;

int nodes,edge;

void push(int nodes){
    stack[tail]=nodes;
    tail++;
}
int pop(){
    tail--;
    return stack[tail];
}

void dfs(int source,int nodes){
    int level[100];
    for(int i=1;i<=nodes;i++){
        level[i]=unvisited;
    }
    push(source);
    level[source]=marked;
    while(head!=tail){
        int value=pop();
        cout<<value<<" ";
        for(int i =1;i<=nodes;i++){
            if(graph[value][i]==1){
                if(level[i]==unvisited){
                    level[i]=marked;
                    push(i);
                }
            }
        }
        level[value]=visited;
    }
    cout<<endl;
}

int main()
{
    int x,y,source;
    cout<<"Enter the nodes: ";
    cin>>nodes;
    for( int i = 1; i<=nodes;i++){
        for(int j = 1;j<=nodes;j++){
        graph[i][j]=0;
        }
    }
    cout<<"Enter the edge: ";
    cin>>edge;
    for( int i = 1; i<=edge;i++){
    cout<<"Enter the vertexes for edge: ";
    cin>>x>>y;
    graph[x][y]=graph[y][x]=1;
    }

    cout<<"Enter source: ";
    cin>>source;
    dfs(source,nodes);
}
