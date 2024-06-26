#include<iostream>
using namespace std;
int main(){
    int arr[100];
    int i,j,a=2,r,z;
    cout<<"Enter no. of elements: ";
    cin>>r;
   for(i=0;i<r;i++){
    cout<<"Enter element: ";
    cin>>arr[i];
   }
   for(i=0;i<r-1;i++){
    for(j=i+1;j<r;j++){
      if(arr[i]>arr[j]){
        z=arr[i];
        arr[i]=arr[j];
        arr[j]=z;  
        }
    }
   }
    for(i=0;i<r;i++){
    cout<<arr[i]<<" ";
   }
   cout<<endl;
    for(i=0;i<r-1;i++){
      if(a!=i){
        z=arr[i];
        arr[i]=arr[r-1];
        arr[r-1]=z;  
        }
        else{
            z=arr[i];
            arr[i]=arr[r-2];
            arr[r-2]=z;
            a+=3;
        }
   }
   for(i=0;i<r;i++){
    cout<<arr[i]<<" ";
   }
    return 0;
}