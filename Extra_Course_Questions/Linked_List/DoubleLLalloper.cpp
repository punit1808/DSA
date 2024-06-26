#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(){
        data=0;
        this->prev=NULL;
        this->next=NULL;
    }
    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
    ~Node(){
        cout<<this->data<<" is deleted from LL"<<endl;
    }
};

void inserthead(Node* &head,Node* &tail,int data){
        if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    //step1:
    Node* newNode = new Node(data);
    //step2:
    newNode -> next = head;
    // step3:
    head->prev=newNode;
    //step4:
    head = newNode;
}

void inserttail(Node* &head,Node* &tail,int data){
    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    // step1:
    Node* newNode=new Node(data);
    // step2:
    tail->next=newNode;
    // step3:
    newNode->prev=tail;
    // step4:
    tail=newNode;
}

int findlength(Node* &head){
        int len = 0;
        Node* temp = head;
        while(temp != NULL) {
                temp = temp->next;
                len++;
        }
        return len;    
}

void insertposition(Node* &head,Node* &tail,int data,int position){
    position=position-1;
    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    if(position==1){
        inserthead(head,tail,data);
        return;
    }
    if(position>=findlength(head)){
        inserttail(head,tail,data);
        return;
    }
    // Inserting in between Nodes
    int i=1;
    // step1:
    Node* left=head;
    while(i<position){
        left=left->next;
        i++;
    }
    Node* curr=left->next;
    // step2:
    Node* newNode=new Node(data);
    // step3:
    newNode->next=curr;
    left->next=newNode;
    curr->prev=newNode;
    newNode->prev=left;
}

void deleteposition(Node* &head,Node* &tail,int position){
    if(head==NULL){
        cout<<"Linked List is Empty"<<endl;
        return;
    }
    if(position>findlength(head)){
        cout<<"Enter a valid Entry."<<endl;
        return;
    }
    if(head->next==NULL){
        Node* temp=head;
        head=NULL;
        tail=NULL;
        delete temp;
        return;
    }
    if(position==1){
        Node* temp=head;
        head=temp->next;
        head->prev=NULL;
        temp->next=NULL;
        delete temp;
        return;
    }
    if(position==findlength(head)){
        Node* temp=tail;
        tail=temp->prev;
        temp->prev=NULL;
        tail->next=NULL;
        delete temp;
        return;
    }
    position=position-1;
    // Deleting middle Nodes
    int i=1;
    // step1:
    Node* prevNode=head;
    while(i<position){
        prevNode=prevNode->next;
        i++;
    }
    Node* curr=prevNode->next;
    Node* nextNode=curr->next;
    //step2:
    prevNode -> next = nextNode;
    //step3:
    nextNode -> prev = prevNode;
    //step4:
    curr -> next = NULL;
    curr ->prev = NULL;
    delete curr;    
}

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    Node* head=NULL;
    Node* tail=NULL;
    inserthead(head,tail,10);
    inserthead(head,tail,20);
    inserthead(head,tail,30);
    inserttail(head,tail,5);
    print(head);
    cout<<endl;
    insertposition(head,tail,15,3);
    print(head);
    cout<<endl;
    deleteposition(head,tail,8);
    print(head);
}