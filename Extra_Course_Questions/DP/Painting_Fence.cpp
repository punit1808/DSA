#include<iostream>
#include<vector>
using namespace std;
int solve(int n,int k){
    if(n==1){
        return k;
    }
    if(n==2){
        return k*k;
    }
    int ans=(solve(n-2,k)+solve(n-1,k))*(k-1);
    return ans;
}
int solveusingmem(int n,int k,vector<int>& dp){
    dp[0]=k;
    dp[1]=k*k;
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans=(solve(n-2,k)+solve(n-1,k))*(k-1);
    dp[n]=ans;
    return ans;
}
int solveusingtab(int n,int k){
    vector<int> dp(n+1,-1);
    dp[1]=k;
    dp[2]=k*k;
    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-2]+dp[i-1])*(k-1);   
    }  
    return dp[n];  
}
int solvespaceopt(int n,int k){
    int prev2=k;
    int prev1=k*k;
    for(int i=3;i<=n;i++){
        int curr=(prev2+prev1)*(k-1); 
        prev2=prev1;
        prev1=curr;  
    }  
    return prev1;     
}
int main(){
    int n=4;
    int k=3;
        int ans=solve(n,k);
        vector<int> dp(n+1,-1);
        cout<<"Answer : "<<ans<<endl;
        ans=solveusingmem(n,k,dp);
        cout<<"Answer : "<<ans<<endl;
        ans=solveusingtab(n,k);
        cout<<"Answer : "<<ans<<endl;
        ans=solvespaceopt(n,k);
       cout<<"Answer : "<<ans<<endl;
       return 0;
}