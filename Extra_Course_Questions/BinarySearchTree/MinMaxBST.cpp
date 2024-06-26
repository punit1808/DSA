#include<iostream>
#include<queue>
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
Node* InsertBST(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(root->data<data){
        root->right=InsertBST(root->right,data);
    }
    else{
        root->left=InsertBST(root->left,data);
    }
    return root;
}
Node* makeBSTree(Node* root){
    int data;
    cin>>data;
    while(data!=-1){
        root=InsertBST(root,data);
        cout<<"Enter Data : ";
        cin>>data; 
    }
    return root; 
}
void levelOrderTraversal(Node* root){
queue<Node*> q;
q.push(root);
q.push(NULL);
while(!q.empty()){
    Node* temp=q.front();
    q.pop();
    if(temp==NULL){
        cout<<endl;
        if(!q.empty()){
            q.push(NULL);
        }
    }
    else{
        cout<<temp->data<<" ";
        if(temp->left){
            // cout<<"Left Data";
            q.push(temp->left);
        }
        if(temp->right){
            // cout<<"Right Data";
            q.push(temp->right);
        }
    }
    }
}
int minBST(Node* root){
    Node* temp=root;
    if(temp==NULL){
        return -1;
    }
    while(temp->left != NULL){
        temp=temp->left;
    }
    return temp->data;
}
int maxBST(Node* root){
    Node* temp=root;
    if(temp==NULL){
        return -1;
    }
    while(temp->right != NULL){
        temp=temp->right;
    }
    return temp->data;
}
int main(){
    Node* root=NULL;
    cout<<"Enter Data : ";
    root=makeBSTree(root);
    cout<<"Printing BST : "<<endl;
    levelOrderTraversal(root);
    cout<<"Minimum Value : "<<minBST(root)<<endl;
    cout<<"Maximum Value : "<<maxBST(root)<<endl;
    return 0;
}