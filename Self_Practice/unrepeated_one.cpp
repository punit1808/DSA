#include<iostream>
using namespace std;
// Only for single unique element
int main(){
    int arr[100];
    int r,x,z=0;
    cout<<"Enter r: ";
    cin>>r;
        for(int i=0;i<r;i++){
        cout<<"Enter element: ";
        cin>>arr[i];
    }
for(int i=0;i<r;i++){
z=z^arr[i];
}
cout<<"Unique element is: "<<z;
    return 0;
}