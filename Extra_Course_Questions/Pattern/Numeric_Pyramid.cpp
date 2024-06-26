#include<iostream>
using namespace std;
int main(){
int i,j,n;
cout<<"Enter N: ";
cin>>n;
for(i=0;i<n;i++) {
    for(j=n-1-i;j>0;j--){
cout<<" ";
    }
    for(j=1;j<=i+1;j++){
        cout<<" "<<j;
    }
    cout<<endl;
}   
}