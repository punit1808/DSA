#include<iostream>
#include<vector>
using namespace std;
    int oddelement(vector<int> arr){
   int s=0;
    int e=arr.size()-1;
    int mid=s+(e-s)/2;
    if(s==e){
        return s;
    }
 if(mid%2==0){
        s=mid;
    }
    else {
        e=mid-1;
    }
    }
int main(){
vector<int> arr{1,1,2,2,3,4,4,5,5};
cout<<"Odd element is "<<oddelement(arr);
    return 0;
}