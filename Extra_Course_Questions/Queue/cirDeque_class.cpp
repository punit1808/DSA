#include<iostream>
using namespace std;
class cirDeque{
    private: 
    int *arr;
    int size;
    int front;
    int back;

    public:
    cirDeque(int size){
        this->size=size;
        arr=new int[size];
        front=-1;
        back=-1;
    }

    // Push from back
    void push_back(int data){
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
    // Push from front
    void push_front(int data){
        // Empty Queue
        if(front==-1){
            front=0;
            back=0;
            arr[front]=data;
        }
        // Queue is Full
        else if(back-front+1==size || back-front+1==0){
            cout<<"Queue is full"<<endl;
            return;
        }
        // Front is at zero
        else if(front==0 && back!=size-1){
            front=size-1;
            arr[front]=data;
        }
        else{
            front--;
            arr[front]=data;
        }        
    }
 void pop_front() {
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
    // Pop from back
     void pop_back() {
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
        // back at first element
        else if(back==0) {
                arr[back]=-1;
                back=size-1;
        }
        else {
                arr[back]=-1;
                back--;
        }
    }

    void print(){
        cout<<"Front : "<<front<<endl;
        cout<<"Back : "<<back<<endl;
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

int main(){
    cirDeque cd(5);
    cd.push_front(5);
    cd.print();
    cd.push_back(10);
    cd.print();
    cd.push_back(20);
    cd.print();
    cd.push_back(30);
    cd.print();
    cd.push_back(40);
    cd.print();
    cd.pop_front();
    cd.print();
    cd.pop_back();
    cd.print();
    cd.push_front(2);
    cd.print();
    cd.push_back(40);
    cd.print();
    cd.push_back(50);

    return 0;
}