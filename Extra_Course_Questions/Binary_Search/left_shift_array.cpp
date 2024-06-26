#include<iostream>
#include<vector>
using namespace std;
int main(){
    int k,s,z=0;
     cout<<"Enter Array Size: ";
    cin>>s;
    vector<int> arr(s);
    vector<int> brr(s);
    cout<<"Enter Times of Shift: ";
    cin>>k;
    for(int i=0;i<s;i++){
        cout<<"Enter element "<<i+1<<endl;
        cin>>arr[i];
    }
    for(int i=0;i<s;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    if(k<s){
    for(int i=0;i<s;i++){
      if(i<s-k){  brr[i]=arr[i+k];}
      else{
brr[i]=arr[z];
z++;
      }
    }
     for(int i=0;i<s;i++){
        cout<<brr[i]<<" ";
    }
    }
    else{
        cout<<"Invalid Values Entered!!";
    }
 return 0;
}