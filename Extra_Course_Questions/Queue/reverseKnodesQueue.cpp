#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void reverseFirstKnodes(queue<int> &q, int k ) {
        //StepA: queue ->k elements  -> stack
        stack<int> s;
        int count = 0;
        int n = q.size();

        if(k <= 0 || k > n){
                return ;
                cout<<"Invalid Input"<<endl;
        }

        while(!q.empty()){
                int temp = q.front();
                q.pop();
                s.push(temp);
                count++;

                if(count == k)
                        break;
        } 

        //stepB: stack -> q me vapas
        while(!s.empty()) {
                int temp = s.top();
                s.pop();
                q.push(temp);
        }

        //step C: push n-k element from q front to back 
        count = 0;
        while(!q.empty() && n-k != 0) {
                int temp = q.front();
                q.pop();
                q.push(temp);
                count++;

                if(count == n-k)
                        break;
        }
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    int k=3;
    reverseFirstKnodes(q,k);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}
