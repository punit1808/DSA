#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void interlinkQueue(queue<int>& q){
    int size=q.size();
    int count=0;
    queue<int> q1;
    queue<int> q2;
    if(size&1){
    while(count<size/2){
        int temp=q.front();
        q.pop();
        q1.push(temp);
        count++;
    }
    while(count<size-1){
        int temp=q.front();
        q.pop();
        q2.push(temp);
        count++;
    }
    while(!q1.empty() && !q2.empty()){
        int temp1=q1.front();
        q1.pop();
        q.push(temp1);

        int temp2=q2.front();
        q2.pop();
        q.push(temp2);
    }
            //odd wala case
        if(size&1) {
               int element = q.front();
               q.pop();
               q.push(element);
        }
    }
    else{
    while(count<size/2){
        int temp=q.front();
        q.pop();
        q1.push(temp);
        count++;
    }
    while(count<size){
        int temp=q.front();
        q.pop();
        q2.push(temp);
        count++;
    }
    while(!q1.empty() && !q2.empty()){
        int temp1=q1.front();
        q1.pop();
        q.push(temp1);

        int temp2=q2.front();
        q2.pop();
        q.push(temp2);
    }
    }

}

void interleaveQueue(queue<int> &q) {
        //Step A: separate both halves
        int n = q.size();
        if(q.empty())
                return;
        int k = n/2;
        int count = 0;
        queue<int> q2;

        while(!q.empty()) {
                int temp = q.front();
                q.pop();
                q2.push(temp);
                count++;

                if(count == k)
                        break;
        }

        //stepB: interleaving start krdo
        while(!q.empty() && !q2.empty()) {
                int first = q2.front();
                q2.pop();

                q.push(first);

                int second = q.front();
                q.pop();

                q.push(second);
        }
        //odd wala case
        if(n&1) {
               int element = q.front();
               q.pop();
               q.push(element);
        }
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    interlinkQueue(q);
    // interleaveQueue(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}