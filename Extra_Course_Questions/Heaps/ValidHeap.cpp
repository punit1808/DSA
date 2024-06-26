#include<iostream>
#include<limits.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
pair<bool,int> ValidHeap(Node* root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,INT_MIN);
        return p;
    }
    if(root->left == NULL && root->right == NULL){
        pair<bool,int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool,int> leftAns=ValidHeap(root->left);
    pair<bool,int> rightAns=ValidHeap(root->right);

    if(leftAns.first && rightAns.first && root->data>leftAns.second && root->data>rightAns.second){
        pair<bool,int> p=make_pair(true,root->data);
        return p;
    }
    else{
        pair<bool,int> p=make_pair(false,root->data);
        return p;
    } 
}
Node* buildTree(){
    int data;
    cout<<"Enter data: ";
    cin>>data;
    if(data==-1){
        return NULL;
    }
    Node* root=new Node(data);
    cout<<"Left";
    root->left=buildTree();
    cout<<"Right";
    root->right=buildTree();
    return root;
}
int main(){
    Node* root=NULL;
    root=buildTree();
    pair<bool,int> p=ValidHeap(root);
    if(p.first){
        cout<<"Tree is a Valid Heap"<<endl;
    }
    else{
        cout<<"Tree is not a Valid Heap"<<endl;
    }

    return 0;
}