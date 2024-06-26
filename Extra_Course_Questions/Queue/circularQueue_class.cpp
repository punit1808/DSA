#include<iostream>
using namespace std;
class cirQueue{
    private: 
    int *arr;
    int size;
    int front;
    int back;

    public:
    cirQueue(int size){
        this->size=size;
        arr=new int[size];
        front=-1;
        back=-1;
    }

    // Push from front
    void push(int data){
        // Empty Queue
        if(front==-1){
            front=0;
            back=0;
            arr[back]=data;
        }
        // Queue is Full
        else if(back-front+1==size || back-front+1==0){
            cout<<"Queue is full"<<endl;
            return;
        }
        // Back is at last
        else if(back==size-1 && front!=0){
            back=0;
            arr[back]=data;
        }
        else{
            back++;
            arr[back]=data;
        }
        
    }
 void pop() {
        // Empty Queue
        if(front == -1) {
                cout << "Q is empty , cannot pop" << endl;
        }
        // Single element
        else if (front == back) {
                arr[front] = -1;
                front = -1;
                back = -1;  
        }
        // Front at last element
        else if(front == size-1) {
                arr[front]=-1;
                front = 0;
        }
        else {
                arr[front]=-1;
                front++;
        }
    }
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

int main(){
    cirQueue cq(5);
    cq.push(10);
    cq.push(20);
    cq.push(30);
    cq.push(40);
    cq.push(50);
    cq.print();
    cq.pop();
    cq.print();
    cq.push(10);
    cq.print();
    cq.push(100);
    cq.print();
    cq.pop();
    cq.print();
    cq.pop();
    cq.print();
    cq.pop();
    cq.print();
    cq.push(100);
    cq.print();
    cq.push(101);
    cq.print();
    cq.push(102);
    cq.print();
    cq.push(103);
    cq.print();

    return 0;
}