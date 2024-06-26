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
bool searchBST(Node* root,int find){
    if(root==NULL){
        return false;
    }
    if(root->data==find){
        return true;
    }
    if(root->data<find){
        searchBST(root->left,find);
    }
    if(root->data>find){
        searchBST(root->right,find);
    }
}
Node* deleteNode(Node* root,int target){
    Node* temp=root;
    if(root==NULL){
        return NULL;
    }
    if(root->data==target){
        // 4 Cases
        if(temp->right==NULL && temp->left==NULL){
            delete temp;
            return NULL;
        }
        else if(temp->right==NULL && temp->left!=NULL){
            Node* child=temp->left;
            delete temp;
            return child;
        }
        else if(temp->left==NULL && temp->right!=NULL){
            Node* child=temp->right;
            delete temp;
            return child;
        }
        else{
            int max=maxBST(root->left);
            cout<<"Max in BST : "<<max<<endl;
            root->data=max;
            root->left=deleteNode(temp->left,max);
            return root;
        }
    }
    if(root->data>target){
        root->left=deleteNode(root->left,target);
    }
    if(root->data<target){
        root->right=deleteNode(root->right,target);
    }
    return root;
}
int main(){
    Node* root=NULL;
    cout<<"Enter Data : ";
    root=makeBSTree(root);
    cout<<"Printing BST : "<<endl;
    levelOrderTraversal(root);
    int target=4;
    root=deleteNode(root,target);
    cout<<"Printing BST : "<<endl;
    levelOrderTraversal(root);

    return 0;
}