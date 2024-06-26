#include<iostream>
using namespace std;
int main(){
    int arr[100];
    int r,i,t,z,j;
    cout<<"Enter number of elements: ";
    cin>>r;
    for(i=0;i<r;i++){
        cout<<"Enter elements: ";
        cin>>arr[i];
    }
    for(i=0;i<r-1;i++){
        t=i;
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

    return 0;
}