#include<iostream>
#include<queue>
using namespace std;
void solve(int* arr,int n,int k){
    queue<int> q;
    // Solving for First Window
    for(int i=0;i<k;i++){
        if(arr[i]<0){
            q.push(i);
        }
    }
    // Solving for Sliding Window
    for(int i=k;i<n;i++){
        // Printing Output for Window
        if(q.empty()){
            cout<<0<<" ";
        }
        else{
            cout<<arr[q.front()]<<" ";
        }
        // Checking for Extra Node
        if(!q.empty() && i-q.front()>=k){
            q.pop();
        }
        // Inserting Next Node
        if(arr[i]<0){
            q.push(i);
        }
    }
        // Printing Output for last Window
        if(q.empty()){
            cout<<0<<" ";
        }
        else{
            cout<<arr[q.front()]<<" ";
        }
}
int main(){
    int arr[]={12,-1,-7,8,-15,30,16,28};
    int size = 8;
    
    int k = 3;

    solve(arr,size,k);
    return 0;
}