#include<iostream>
#include<vector>
using namespace std;
int peakelement(vector<int> arr,int mid){
    int s=0;
    int e=arr.size()-1;
 while(s<e){
        if(arr[mid]<arr[mid+1]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return mid;
}
int main(){
vector<int> arr{0,10,5,2};
int ans;
int s=0;
int e=arr.size();
int mid= s+(e-s)/2;
  ans=peakelement(arr,mid);

    cout<<"Peak element is "<<arr[ans]<<endl;
    return 0;
}