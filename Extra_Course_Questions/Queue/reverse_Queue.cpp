#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverseQueue(queue<int>& q){
    stack<int> s;
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        s.push(temp);
    }
    while(!s.empty()){
        int top=s.top();
        s.pop();
        q.push(top);
    }
}

void reverseQueueusingRecursion(queue<int>& q){
    //Base case
    if(q.empty()) {
        return;
    }
        int temp = q.front();
        q.pop();
        reverseQueueusingRecursion(q);
        q.push(temp);
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    // reverseQueue(q);
    // while(!q.empty()){
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }
    reverseQueueusingRecursion(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}