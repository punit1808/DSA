#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    int row;
    int col;
    Node(){

    }
    Node(int d,int r,int c){
        data=d;
        row=r;
        col=c;
    }
};
class compare{
    public:
    bool operator()(Node* a,Node* b){
        return a->data>b->data;
    }
};
vector<int> MergeKSortedArray(int arr[][4],int k,int n){
    priority_queue<Node*,vector<Node*>,compare> minHeap;
    for(int i=0;i<k;i++){
        Node* temp=new Node(arr[i][0],i,0);
        minHeap.push(temp);
    }
    vector<int> ans;
    while(!minHeap.empty()){

        Node* temp=minHeap.top();
        int topElement=temp->data;
        int topRow=temp->row;
        int topCol=temp->col;
        ans.push_back(topElement);
        minHeap.pop();
        if(topCol+1<n){
        Node* newNode=new Node(arr[topRow][topCol+1],topRow,topCol+1);
        minHeap.push(newNode);
        }
    }
    return ans;
}
int main(){
    int arr[][4]={{3,4,6,7},{0,2,5,8},{1,9,10,11}};
    int k=3;
    int n=4;
    vector<int> ans=MergeKSortedArray(arr,k,n);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}