#include<iostream>
using namespace std;
int main(){
    int arr[100][100];
    int i,j,r,c,sum=0;
    cout<<"Enter no. of Rows: "<<endl;
    cin>>r;
    cout<<"Enter no. of Columns: "<<endl;
    cin>>c;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cout<<"Enter element: ";
            cin>>arr[i][j];
        }
    }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
           if(sum<arr[i][j]){
            sum=arr[i][j];
           }             
        }
    }
    cout<<"Largest no. is "<<sum;
    return 0;
}