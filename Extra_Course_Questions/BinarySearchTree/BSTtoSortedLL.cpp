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
Node* BSTusingInorder(int *Inorder,int start,int end){
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    Node* root=new Node(Inorder[mid]);

    root->left=BSTusingInorder(Inorder,start,mid-1);
    root->right=BSTusingInorder(Inorder,mid+1,end);
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
void BSTtoSortedLL(Node* root,Node* &head){
    if(root==NULL){
        return;
    }
    BSTtoSortedLL(root->right,head);
    root->right=head;
    if(head!=NULL){
        head->left=root;
    }
    head=root;
    BSTtoSortedLL(root->left,head);
}
void printLL(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->right;
    }
}
int main(){
    int Inorder[]={1,2,3,4,5,6,7,8,9};
    int size=sizeof(Inorder)/4;
    Node* root=NULL;
    root=BSTusingInorder(Inorder,0,size-1);
    cout<<"Printing BST : "<<endl;
    levelOrderTraversal(root);
    Node* head=NULL;
    BSTtoSortedLL(root,head);
    cout<<"Printing LL : "<<endl;
    printLL(head);
    return 0;
}
