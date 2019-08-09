#include<iostream>
using namespace std;

typedef struct node{
    int data;
    node *next;
}*nodeptr;

node *head = NULL;
node *curr = NULL;

void add(int data){
    nodeptr newnode = new node;
    newnode->data = data;
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
    }
    else {
        curr->next = newnode;
    }
    curr = newnode;
}

void display(){
    nodeptr ptr = head;
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

bool search(int sn){
    nodeptr ptr = head;
    while(ptr != NULL){
        if(ptr->data == sn){
            return 1;
        }
        ptr = ptr->next;
    }
    if(ptr == NULL){
        return 0;
    }
}

int main(){
    int n,data,sn;
    cout<<"Enter the elements value: ";
    cin>>n;
    cout<<"Enter elements: "<<endl;
    for(int i = 0;i<n ; i++){
    cin>>data;
    add(data);
    }
    display();
    cin>>sn;
    bool found = search(sn);
    if(found == 1){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }
return 0;
}
