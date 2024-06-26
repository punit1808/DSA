#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> d;
    d.push_front(10);
    d.push_back(20);
    d.push_front(5);
    d.push_back(30);
    cout<<"Size of Deque : "<<d.size()<<endl;
    while(!d.empty()){
        cout<<d.front()<<" ";
        cout<<d.back()<<" ";
        cout<<endl;
        d.pop_front();
        d.pop_back();
    }
    cout<<endl;
    if(d.empty()){
        cout<<"Empty deque"<<endl;
    }
    else{
        cout<<"Non-Empty deque"<<endl;
    }
}