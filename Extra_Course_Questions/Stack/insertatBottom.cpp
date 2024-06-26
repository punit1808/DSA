#include<iostream>
#include<stack>
using namespace std;
void insertatBottom(stack<int>& s,int target){
    if(s.empty()){
        s.push(target);
        return;
    }
    int temp=s.top();
    s.pop();
    insertatBottom(s,target);
    // Backtrack
    s.push(temp);

}
int main(){
    stack<int> s;
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    insertatBottom(s,10);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}