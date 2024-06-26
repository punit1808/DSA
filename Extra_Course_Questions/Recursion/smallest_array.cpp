#include<iostream>
#include<limits.h>
using namespace std;
void smallest(int arr[],int n,int i,int& min){
    if(n<=i){
        return;
    }
    if(min>arr[i]){
        min=arr[i];
    }
    smallest(arr,n,i+1,min);

}
int main(){
    int arr[]={5,6,2,8,4};
    int min=INT_MAX;
    smallest(arr,5,0,min);
    cout<<"Smallest is "<<min;
}