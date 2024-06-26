#include<iostream>
using namespace std;
class Stack{
    private:
    int* arr;
    int size;
    int position;
    public:
    Stack(int size){
        arr=new int[size];
        this->size=size;
        this->position=-1;
    }
    void push(int num){
        if(size-position>1){
            position++;
            arr[position]=num;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop(){
        if(position>-1){
            position--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }
    int topposition(){
        if(position>-1){
            return arr[position];
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }
    int getsize(){
        return position+1;
    }
    bool isempty(){
        if(position==-1){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    Stack s(10);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.pop();
    cout<<"Top element of stack is "<<s.topposition()<<endl;
    cout<<"Size of stack is "<<s.getsize()<<endl;
    while(!s.isempty()){
        cout<<s.topposition()<<" ";
        s.pop();
    }
    cout<<endl;

    // Now Stack is Empty
    
    cout<<"Top element of stack is "<<s.topposition()<<endl;
    cout<<"Size of stack is "<<s.getsize()<<endl;

    return 0;
}