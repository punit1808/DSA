#include<iostream>
using namespace std;

void merge(int* arr,int s, int e){
    int mid=(s+e)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    
    int* left=new int[len1];
    int* right=new int[len2];
    // Copying in new array
    int k=s;
    
    for(int i=0;i<len1;i++){
        left[i]=arr[k];
        k++;
    }
    k=mid+1;
    for(int i=0;i<len2;i++){
        right[i]=arr[k];
        k++;
    }
    // Merge and compare
    int lefti=0;
    int righti=0;
    int maini=s;
    while(lefti<len1&&righti<len2){
        if(left[lefti]<right[righti]){
            arr[maini++]=left[lefti++];
        }
        else{
            arr[maini++]=right[righti++];
        }
    }
    // Merging pending array
    while(lefti<len1){
        arr[maini++]=left[lefti++];
    }
    while(righti<len2){
        arr[maini++]=right[righti++];
    }
    }

void sort(int* arr, int s, int e){
    // Base Case
    if(s>=e){
        return;
    }
    int mid=(s+e)/2;
    // Left array
    sort(arr,s,mid);

    // Right array
    sort(arr,mid+1,e);

    // Merging Logic
    merge(arr,s,e);
}
int main(){
    int arr[]={1,3,11,4,2};
    int n=sizeof(arr)/sizeof(int);
    int s=0;
    int e=n-1;
    for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
    sort(arr,s,e);
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
    return 0;
}