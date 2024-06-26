#include<iostream>
using namespace std;
class Queue{
    private:
    int *arr;
    int front;
    int back;
    int size;
    public:
    Queue(int size){
        this->size=size;
        arr=new int[size];
        front=0;
        back=0;
    }
    // Possible in Queue : Push from back
    void push(int data){
        if(back-front==size){
            cout<<"Queue is full"<<endl;
            return;
        }
        else{
            arr[back]=data;
            back++;
        }
    }
    // Possible in Queue : Pop from front
    void pop(){
        if(front==back){
            cout<<"Queue is empty"<<endl;
            return;
        }
        else{
            arr[front]=-1;
            front++;
        }
    }
     
    int getfront(){
        if(front==back){
            return -1;
        }
        else{
        return arr[front];
        }
    }

    bool isempty(){
        if(front==back){
            return true;
        }
        else{
            return false;
        }
    }

    int getsize(){
        return (back-front);
    }

};
int main(){
    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    cout<<"Size of Queue : "<<q.getsize()<<endl;
    q.pop();
    cout<<"Size of Queue : "<<q.getsize()<<endl;
    cout<<"Front Element : "<<q.getfront()<<endl;
    if(q.isempty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is NON-Empty"<<endl;
    }
    while(!q.isempty()){
        cout<<q.getfront()<<" ";
        q.pop();
    }
    cout<<endl;
    if(q.isempty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is NON-Empty"<<endl;
    }
    return 0;

}