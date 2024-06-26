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
 void PostOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout<<root->data<<" ";
 }
int main(){
Node* root=NULL;
root=buildTree();
PostOrderTraversal(root);
return 0;
}