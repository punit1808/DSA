#include<iostream>
using namespace std;
int main(){
    int i,j,n;
    cout<<"Enter n: ";
    cin>>n;
    for(i=0;i<n-1;i++){
        for(j=0;j<i;j++){
          cout<<" ";
        }
        cout<<"*";
        for(j=2*n-2*i-1;j>0;j--){
             cout<<" ";
        }
        cout<<"*";
        cout<<endl;
    }
    for(i=0;i<n;i++){
        cout<<" ";
    }
    cout<<"*"<<endl;
     for(i=0;i<n-1;i++){
        for(j=n-i-2;j>0;j--){
             cout<<" ";
        }
        cout<<"*";
         for(j=0;j<=2*i+2;j++){
          cout<<" ";
        }
        cout<<"*";
       
        cout<<endl;
    }

   
}