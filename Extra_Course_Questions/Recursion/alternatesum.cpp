#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
void solve(vector<int>& arr,int i,int ans,int& maxi){
    if(i>=arr.size()){
        maxi=max(ans,maxi);
        return ;
    }
    // including
    solve(arr,i+2,ans+arr[i],maxi);
    // excluding 
    solve(arr,i+1,ans,maxi);
}
int main(){
    int i=0;
        int ans=0;
        int maxi=INT_MIN;
    vector<int> arr{1,2,5,9};
  solve(arr,i,ans,maxi);
    cout<<"Maximum Sum : "<<maxi;
    return 0;
}