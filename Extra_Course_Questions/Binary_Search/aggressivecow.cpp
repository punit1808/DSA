#include<iostream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;
bool possible(vector<int>& stall,int k,int mid){
int pos=stall[0];
int c=1;
for(int i=1;i<stall.size();i++){
  if(stall[i]-pos>=mid){
c++;
pos=stall[i];
  }
}
  if(c==k){
    return true;
  }
  else{
  return false;}
}
int main(){
    vector<int> stall{10,1,2,7,5};
    sort(stall.begin(),stall.end());
    int k=3;
    int ans=-1;
int s=0;
int e=stall[stall.size()-1]-stall[0];
while(s<=e){
  int mid=s+(e-s)/2;
  if(possible(stall,k,mid)){
       ans=mid;
       s=mid+1;
  }
  else{
    e=mid-1;
  }
}
cout<<"Maximum possible Minimum Gap : "<<ans;
}