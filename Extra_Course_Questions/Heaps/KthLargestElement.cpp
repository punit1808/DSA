#include<iostream>
#include<queue>
using namespace std;
int KthLargestElement(int *arr,int k,int size){
    priority_queue<int,vector<int>,greater<int> > pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    for(int i=k;i<size;i++){
        if(arr[i]>pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
int main(){
    int arr[]={2,4,5,1,7,9,3};
    int k=1;
    int size=sizeof(arr)/4;
    int ans=KthLargestElement(arr,k,size);
    cout<<k<<" th Largest Element : "<<ans<<endl;
    return 0;
}