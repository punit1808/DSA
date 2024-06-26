#include<iostream>
#include<queue>
#include<limits.h>
using namespace std;
class Nodedata{
    public:
    int size;
    int max;
    int min;
    bool valid;
    Nodedata(){

    }
    Nodedata(int size,int max,int min,bool valid){
        this->size=size;
        this->max=max;
        this->min=min;
        this->valid=valid;
    }
};

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
Nodedata* maxBSTinBS(Node* root,int &ans){
    if(root==NULL){
        Nodedata* temp=new Nodedata(0,INT_MIN,INT_MAX,true);
        return temp;
    }
    Nodedata* leftAns=maxBSTinBS(root->left,ans);
    Nodedata* rightAns=maxBSTinBS(root->right,ans);

    Nodedata* currAns=new Nodedata();
    currAns->size=leftAns->size+rightAns->size+1;
    currAns->max=max(root->data,rightAns->max);
    currAns->min=min(root->data,leftAns->min);

    if(leftAns->valid && rightAns->valid && (root->data>leftAns->max && root->data<rightAns->min)){
        currAns->valid=true;
    }
    else{
        currAns->valid=false;
    }
    if(currAns->valid){
    ans=max(currAns->size,ans);
    }
    return currAns;
}
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

int main(){
    int Inorder[]={1,2,3,4,5,6,7,8,9};
    int size=sizeof(Inorder)/4;
    Node* root=NULL;
    root=BSTusingInorder(Inorder,0,size-1);
    cout<<"Printing BST : "<<endl;
    levelOrderTraversal(root);
    int ans=0;
    maxBSTinBS(root,ans);
    cout<<"Length of max BST : "<<ans<<endl;
    return 0;
}