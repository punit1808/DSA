#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> q;
    // Inputing elements
    // Will be input in back
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout<<"Length of queue : "<<q.size()<<endl;
    // Removing one element
    // Will be removed from front
    q.pop();
    cout<<"Length of queue : "<<q.size()<<endl;
    // Empty Check function
    if(q.empty()){
        cout<<"Empty queue"<<endl;
    }
    else{
        cout<<"Non-Empty queue"<<endl;
    }
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    if(q.empty()){
        cout<<"Empty queue"<<endl;
    }
    else{
        cout<<"Non-Empty queue"<<endl;
    }
}