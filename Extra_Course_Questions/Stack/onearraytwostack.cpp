#include<iostream>
using namespace std;
class Stack{
    private:
    int* arr;
    int size;
    int position1;
    int position2;
    public:
    Stack(int size){
        arr=new int[size];
        this->size=size;
        this->position1=-1;
        this->position2=size;
    }
    void push1(int num){
        if(position2-position1!=1){
            position1++;
            arr[position1]=num;
        }
        else{
            cout<<"Stack 1 Overflow"<<endl;
        }
    }

    void pop1(){
        if(position1>-1){
            arr[position1]=0;
            position1--;
            
        }
        else{
            cout<<"Stack 1 Underflow"<<endl;
        }
    }

    void push2(int num2){
        if(position2-position1!=1){
            position2--;
            arr[position2]=num2;
        }
        else{
            cout<<"Stack 2 Overflow"<<endl;
        }
    }

    void pop2(){
        if(position2<size){
            arr[position2]=0;
            position2--;
        }
        else{
            cout<<"Stack 2 is Underflow"<<endl;
        }
    }

    void print(){
        int stacksize=0;
        cout<<"Position1 : "<<position1+1<<endl;
        cout<<"Position2 : "<<position2-1<<endl;        
        while(stacksize<size){
            cout<<arr[stacksize]<<" ";
            stacksize++;
        }
        cout<<endl<<endl<<endl;
    }
};
int main(){
    Stack s(10);
        s.push1(10);
        s.print();
        s.push1(20);
        s.print();
        s.push1(30);
        s.print();
        s.push1(40);
        s.print();
        s.push1(50);
        s.print();

        s.push2(100);
        s.print();
        s.push2(110);
        s.print();
        s.push2(120);
        s.print();
         s.push2(130);
        s.print();
        s.push2(140);
        s.print();
        s.push2(150);
        s.print();
        
        s.pop1();
        s.print();
        s.pop1();
        s.print();

        s.pop1();
        s.print();

        s.pop1();
        s.print();

        s.pop1();
        s.print();

        s.push2(1000);
        s.print();

        s.pop1();
        s.print();
    return 0;
}