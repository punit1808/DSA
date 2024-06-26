#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node() {
          this->data = 0;
          this->next = NULL;
        }
   Node(int data){
    this->data=data;
     this->next = NULL;
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
    //step3:
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
    //step2: connect with tail ndoe
    tail->next = newNode;
    //step3: update tail;
    tail = newNode; 
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

void insertposition(int position,Node* &head,Node* &tail,int data){
    position=position-1;
     if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
     if(position == 0) {
         inserthead(head, tail , data);
         return;
        }    
    int len = findlength(head);
        
        if(position >= len) {
                inserttail(head, tail, data);
                return;
        }
        //step1:find prev and curr
        int i = 1;
        Node* prev = head;
        while(i < position) {
                prev= prev -> next;
                i++;
        }
        Node* curr = prev -> next;

        //step2;
        Node* newNode = new Node(data);

        //step3:
        newNode -> next = curr;

        //step4:
        prev -> next = newNode;        
}

void deletenode(int position,Node* &head,Node* &tail){
  if(head == NULL) {
                cout << "Cannot delete, LL is empty";
                return;
        }
        //deleting first node
        if(position == 1) {
                Node* temp = head;
                head = head -> next;
                temp -> next = NULL;
                delete temp;
                return;
        }
        int len  = findlength(head);
        //deleting last node
        if(position == len) {
                //find prev
                int i = 1;
                Node* prev = head;
                while(i < position - 1) {
                        prev = prev->next;
                        i++;
                }
                //step2:
                prev->next = NULL;
                //step3:
                Node* temp = tail;
                //step4:
                tail = prev;
                //step5:
                delete temp;
                return;
        }

        //deleting middle node

        //step  : find prev and curr
        int i =1;
        Node* prev = head;
        while( i < position-1) {
                prev= prev -> next;
                i++;
        }
        Node* curr = prev -> next;

        //step2:
        prev -> next = curr -> next;
        //step3:
        curr -> next = NULL;
        //step4:
        delete curr;
}

Node* reverseusingrecursion(Node* prevNode,Node* curr){
        if(curr==NULL){
                return prevNode;
        }
        Node* forward=curr->next;
        curr->next=prevNode;
        prevNode=curr;
        return reverseusingrecursion(curr,forward);

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
  inserthead(head,tail,40);
  inserttail(head,tail,1);
  print(head);
  cout<<endl;
  insertposition(2,head,tail,35);
  print(head);
  cout<<endl;
  deletenode(2,head,tail);
  print(head);
  cout<<endl;
  Node* prevNode=NULL;
  Node* curr=head;
  head=reverseusingrecursion(prevNode,curr);
  print(head);
    return 0;
}