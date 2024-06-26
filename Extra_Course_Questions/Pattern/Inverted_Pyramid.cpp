#include <iostream>
using namespace std;
int main() {
int i,j;
int a;
cout<<"Enter number of rows: ";
cin>>a;
for(i=0;i<=a;i++){
    for(j=1;j<=i;j++){
        cout<<" ";}
    for(j=a-1-i;j>=0;j--){
        cout<<"* ";
    }
    cout<<endl;
}
    return 0;
}