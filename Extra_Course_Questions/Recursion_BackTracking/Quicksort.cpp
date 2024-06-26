#include<iostream>
using namespace std;
int findpivot(int* arr,int s,int e){
    int count=0;
    for(int i=s+1;i<=e;i++){
        if(arr[s]>arr[i]){
            count++;
        }
    }
       int pivoti=s+count;
    swap(arr[s],arr[pivoti]);
 int i=s;
 int j=e;

    while(i<pivoti && j>pivoti){
        while(arr[i]<arr[pivoti]){
            i++;
        }
        while(arr[j]>arr[pivoti]){
            j--;
        }
        if(i<pivoti && j>pivoti){
            swap(arr[i],arr[j]);
        }
    }
    
    return pivoti;
}
void quicksort(int* arr, int s, int e){
    if(s>=e){
        return;
    }
    int p= findpivot(arr,s,e);
    // Left
    quicksort(arr,s,p-1);
    // Right
    quicksort(arr,p+1,e);
}
int main(){
    int arr[]={9,2,1,3,5,14,4};
    int n=7;
    int s=0;
    int e=n-1;
    quicksort(arr,s,e);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}