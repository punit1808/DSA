#include<iostream>
#include<vector>
using namespace std;
int binarysearch(vector<int> arr,int f){
   int s=0;
   int e=arr.size()-1;
   int mid=s+(e-s)/2;
   while(s<e){
    if(arr[mid]==f){
        return mid;
    }
    else if(arr[mid-1]==f){
        return (mid-1);
    }
    else if(arr[mid+1]==f){
        return (mid+1);
    }
    else if(arr[mid]>f){
        e=mid-2;
    }
    else if(arr[mid]<f){
        s=mid+2;
    }
   }
   return -1;
}
int main(){
    vector<int> arr{1,2,3,5,4};
    int find=5;
   int result=binarysearch(arr,find);
if(result==-1)
cout<<"Not Found";
else
cout<<"Found";
}