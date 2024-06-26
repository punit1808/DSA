#include <iostream>
#include<vector>
using namespace std;
int missingelement(vector<int> arr,int s,int e, int mid){
    int ans=0;
    if(arr[0]!=1){
        return 0;
    }
    else if(arr[e]!=e+1){
        return e-1;
    }
    else{
    while(s<=e){
        if(s!=e){
        if(arr[mid]==mid+1){
            s=mid+1;
        }
       else if(arr[mid]==mid+2){
            ans=mid;
             e=mid-1;
            return ans;
           
        }
    mid=s+(e-s)/2;}
    else{
                mid=s+(e-s)/2;
                ans=mid;
            return ans;
            break;
            
    }
} }
if(ans==0){
    return -1;
}
   
}
int main() {
 vector<int> arr{1,2,3,4,5,6,7,8,9};
 int s=0;
 int e=arr.size()-1;
 int mid=s+(e-s)/2;
 int ans=missingelement(arr,s,e,mid);
 if(ans!=-1){
cout<<"Missing element is "<<ans+1;
}
else{
    cout<<"No Missing element";
}
    return 0;
}