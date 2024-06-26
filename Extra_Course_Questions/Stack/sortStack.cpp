#include<iostream>
#include<stack>
using namespace std;
void putatPosition(stack<int>& s,int top){
    if(s.empty()){
        s.push(top);
        return;
    }
    if(s.top()>=top){
        s.push(top);
        return;
    }
    int temp=s.top();
    s.pop();
    putatPosition(s,top);
    // Backtrack
    s.push(temp);
}
void sortStack(stack<int>& s){
    if(s.empty()){
        return;
    }
    int top=s.top();
    s.pop();
    sortStack(s);
    putatPosition(s,top);
}
int main(){
    stack<int> s;
    s.push(30);
    s.push(20);
    s.push(60);
    s.push(50);
    s.push(10);
    s.push(40);
    sortStack(s);
        while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}