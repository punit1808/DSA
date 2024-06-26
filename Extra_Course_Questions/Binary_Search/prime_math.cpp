#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<bool> prime(10,true);
    int ans=0;
    prime[0]=prime[1]=false;
    for(int i=2;i<10;i++){
        if(prime[i]){
          ans++;
          int j=2*i;
          while(j<10){
            prime[j]=false;
            j+=i;
          }
        }
    }
    cout<<ans;
}