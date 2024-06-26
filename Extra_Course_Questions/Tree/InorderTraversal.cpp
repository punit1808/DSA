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
 void InOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    InOrderTraversal(root->left);
    cout<<root->data<<" ";
    InOrderTraversal(root->right);
 }
int main(){
Node* root=NULL;
root=buildTree();
InOrderTraversal(root);
return 0;
}