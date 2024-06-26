#include <iostream>
using namespace std;
int main() {
int i,j;
int a;
cout<<"Enter number of rows: ";
cin>>a;
for(i=0;i<=a-1;i++){
    for(j=a-1-i;j>=0;j--){
        cout<<" ";
    }
    for(j=1;j<=i+1;j++){
       if(j==1) {cout<<"* ";}
       else if(j==i+1){cout<<"* ";}
       else{cout<<"  ";}
    }
    cout<<endl;
}

for(i=0;i<=a;i++){
    for(j=1;j<=i+1;j++){
        cout<<" ";
        }
    for(j=a-1-i;j>=0;j--){
       if(j==a-1-i) {cout<<"* ";}
       else if(j==0){cout<<"* ";}
        else{cout<<"  ";}
    }
    cout<<endl;
}
    return 0;
}