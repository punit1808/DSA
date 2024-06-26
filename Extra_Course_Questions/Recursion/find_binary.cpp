#include<iostream>
#include<vector>
using namespace std;
int findnum(vector<int>& arr,int s, int e,int mid,int find){
    if(s>e){
        return -1;
    }
 if(arr[mid]==find){
    return mid;
 }
 arr[mid]>find? findnum(arr,s,e=mid-1,(s+(e-s)/2),find): findnum(arr,s=mid+1,e,(s+(e-s)/2),find);
//  else if(arr[mid]>find){
//     e=mid-1;
//  }
//  else{
//     s=mid+1;
//  }
//  mid=s+(e-s)/2;
//  return findnum(arr,s,e,mid,find);
}
int main(){
    vector<int> arr{1,2,3,4,5,6,7,8};
    int s=0;
    int e=arr.size()-1;
    int mid=s+(e-s)/2;
    int find=10;
int ans=findnum(arr,s,e,mid,find);
cout<<ans;
}