#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int getlength(Node* head){
    Node* temp=head;
    int LLlength=0;
    while(temp!=NULL){
        LLlength++;
        temp=temp->next;
    }
    return LLlength;
}
Node* reverseKnodes(Node* head,int k){
    if(head==NULL){
        cout<<"LL is empty"<<endl;
        return head;
    }
    int len=getlength(head);
    if(len<k){
        return head;
    }
    Node* prev=NULL;
    Node* curr=head;
    Node* forward=curr->next;
    int l=0;
    while(l<k){
        forward=curr->next;
        curr->next=prev;
        prev=curr;        
        curr=forward;
        l++;
    }
    if(forward!=NULL){
        head->next=reverseKnodes(forward,k);
    }
    return prev;
}
int main(){
    Node* first=new Node(10);
    Node* second=new Node(20);
    Node* third=new Node(30);
    Node* fourth=new Node(40);
    Node* fifth=new Node(50);
    Node* sixth=new Node(60);
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    print(first);
    cout<<endl;
    int k=3;
    Node* reversed=reverseKnodes(first,k);
    print(reversed);
}