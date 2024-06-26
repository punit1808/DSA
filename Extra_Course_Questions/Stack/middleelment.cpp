#include<iostream>
#include<stack>
using namespace std;
void middleelement(stack<int> &s,int &size){
    if(size==0){
        cout<<"Stack Underflow"<<endl;
        return;
    }
    if(size%2==0){
    if(s.size()==(size/2)+1){
        int temp=s.top();
        s.pop();
        cout<<"Middle element is "<<s.top()<<endl;
        s.push(temp);
        return;
    }
    }
    else if(size%2!=0){
        if(s.size()==(size/2)+1){
        cout<<"Middle element is "<<s.top()<<endl;
        return;
    }
    }

    int temp=s.top();
    s.pop();
    middleelement(s,size);
    s.push(temp);
    return;
}
int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    int size=s.size();
    middleelement(s,size);
}