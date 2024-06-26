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
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
    }
    }
int main(){
  Node* head=new Node(10);
  Node* head1=new Node(20);
  Node* head2=new Node(30);
  head->next=head1;
  head1->next=head2;

print(head);
    return 0;
}