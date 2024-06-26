#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int> pq;
    pq.push(5);
    pq.push(10);
    pq.push(4);
    pq.push(1);
    pq.push(9);
    cout<<"Data on Top : "<<pq.top()<<endl;
    pq.pop();
    cout<<"Data on Top : "<<pq.top()<<endl;
    pq.pop();
    cout<<"Data on Top : "<<pq.top()<<endl;
    pq.pop();
    cout<<"Data on Top : "<<pq.top()<<endl;
    pq.pop();
    cout<<"Data on Top : "<<pq.top()<<endl;
    pq.pop();
    if(pq.empty()){
        cout<<"Priority Queue is Empty"<<endl;
    }
    return 0;
}