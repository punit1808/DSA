#include<iostream>
#include<limits.h>
using namespace std;
void smallest(char arr[],int n,int i,char& min){
    if(n<=i){
        return;
    }
    if(min==arr[i]){
        min='*';
    }

    smallest(arr,n,i+1,min);

}
int main(){
   char arr[]="Hello";
   char min='r';
    smallest(arr,5,0,min);
    if(min=='*')
    cout<<"Found";
    else
    cout<<"Not Found";
}