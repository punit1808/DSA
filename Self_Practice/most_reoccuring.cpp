#include<iostream>
using namespace std;
int main(){
int arr[100];
int i,j,r,repeat,z=0;
cout<<"Enter number of rows: ";
cin>>r;
for(i=0;i<r;i++){
cout<<"Enter element: ";
cin>>arr[i];
}

for(i=0;i<r;i++){
    repeat=1;
    int test=arr[i];
    for(j=i+1;j<r;j++){
        if(test==arr[j]){
            repeat++;
        }
        if(repeat>z){
            z=repeat;
        }
    }
            cout<<arr[i]<<" repeats "<<repeat<<" Times"<<endl;

}
for(i=0;i<r;i++){
    repeat=1;
    int test=arr[i];
    for(j=i+1;j<r;j++){
        if(test==arr[j]){
            repeat++;
        }
       
    }
     if(repeat==z){
            cout<<"Maximum Repeated element is "<<arr[i];
        }
}
    return 0;
}