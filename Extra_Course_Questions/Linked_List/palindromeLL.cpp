#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
        Node(){
        this->data=0;
        this->next=NULL;
        }
    Node(int data){
        this->data=data;
        this->next=NULL;
        }
};
Node* reversefrommiddle(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* next = curr -> next;
        while(curr != NULL) {
                next = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = next;
        }
        return prev;
}
bool checkpalindrome(Node* head){
        Node* slow=head;
        Node* fast=head;
        while(fast->next!=NULL){
        fast=fast->next;
        if(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        }
        Node* temp1=head;
        Node* temp2=reversefrommiddle(slow->next);
                while(temp2 != NULL) {
                if(temp1 -> data != temp2 -> data) {
                        // not a palindome
                        return false;
                }
                else {
                        //if data is equal, then aage badh jao
                        temp1 = temp1 -> next;
                        temp2 = temp2 -> next;
                }
        }
        return true;
}
int main(){
        Node* first=new Node(10);
        Node* second=new Node(20);
        Node* third=new Node(30);
        Node* fourth=new Node(30);
        Node* fifth=new Node(20);
        Node* sixth=new Node(10);
        first->next=second;
        second->next=third;
        third->next=fourth;
        fourth->next=fifth;
        fifth->next=sixth;
       if(checkpalindrome(first)){
        cout<<"LL is a Palindrome"<<endl;
       }
       else{
        cout<<"LL is not a Palindrome"<<endl;
       }
}