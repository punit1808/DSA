#include<iostream>
#include<stack>
using namespace std;
void print(stack<int> s,int size){
    // while(size--){
    // cout<<s.top()<<" ";
    // s.pop();
    // } 

    // Alternate Method
    while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();        
    }
}
int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    int size=s.size();
    print(s,size);
    s.pop();
    cout<<endl;
    size=s.size();
    print(s,size);
    return 0;
}