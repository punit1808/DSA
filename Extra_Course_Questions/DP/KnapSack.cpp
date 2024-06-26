#include<iostream>
#include<vector>
using namespace std;
int solve(int weight[],int value[],int index,int capacity){
    if(index==0){
        if(weight[0]<=capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }
    int include=0;
    if(weight[index]<=capacity){
    include=value[index]+solve(weight,value,index-1,capacity-weight[index]);
    }
    int exclude=solve(weight,value,index-1,capacity);
    int ans=max(include,exclude);
    return ans;
}
int solveusingmem(int weight[],int value[],int index,int capacity,vector<vector<int>>& dp){
    if(index==0){
        if(weight[0]<=capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }
        if(dp[index][capacity]!=-1){
            return dp[index][capacity];
        }
    int include=0;
    if(weight[index]<=capacity){
    include=value[index]+solveusingmem(weight,value,index-1,capacity-weight[index],dp);
    }
    int exclude=solveusingmem(weight,value,index-1,capacity,dp);
    dp[index][capacity]=max(include,exclude);
    return dp[index][capacity];
}
int solveusingtab(int weight[],int value[],int n,int capacity){
    vector<vector<int>> dp(n,vector<int>(capacity+1,0));
    for(int w=weight[0];w<=capacity;w++){
        if(weight[0]<=capacity){
            dp[0][w]=value[0];
        }
        else{
            dp[0][w]=0;
        }
    }
    for(int i=1;i<n;i++){
        for(int wt=0;wt<=capacity;wt++){
            int include=0;
            if(weight[i]<=wt){
            include=value[i]+dp[i-1][wt-weight[i]];
            }
            int exclude=dp[i-1][wt];
            dp[i][wt]=max(include,exclude);
            }
    }
    return dp[n-1][capacity];
}
int solvespaceopt(int weight[],int value[],int n,int capacity){
    vector<vector<int>> dp(n,vector<int>(capacity+1,0));
    vector<int> prev(capacity+1,0);
    vector<int> curr(capacity+1,0);
    for(int w=weight[0];w<=capacity;w++){
        if(weight[0]<=capacity){
            prev[w]=value[0];
        }
        else{
            prev[w]=0;
        }
    }
    for(int i=1;i<n;i++){
        for(int wt=0;wt<=capacity;wt++){
            int include=0;
            if(weight[i]<=wt){
            include=value[i]+prev[wt-weight[i]];
            }
            int exclude=prev[wt];
            curr[wt]=max(include,exclude);
            }
            prev=curr;
    }
    return prev[capacity];
}
int solvespaceopt2(int weight[],int value[],int n,int capacity){
    vector<vector<int>> dp(n,vector<int>(capacity+1,0));
    vector<int> curr(capacity+1,0);
    for(int w=weight[0];w<=capacity;w++){
        if(weight[0]<=capacity){
            curr[w]=value[0];
        }
        else{
            curr[w]=0;
        }
    }
    for(int i=1;i<n;i++){
        for(int wt=capacity;wt>=0;wt--){
            int include=0;
            if(weight[i]<=wt){
            include=value[i]+curr[wt-weight[i]];
            }
            int exclude=curr[wt];
            curr[wt]=max(include,exclude);
            }
    }
    return curr[capacity];
}
int main(){
    int weight[]={4,5,1};
    int value[]={1,2,3};
    int n=3;
    int capacity=4;

// int ans=solve(weight,value,n-1,capacity);
// cout<<"Answer : "<<ans<<endl;
// vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
// int ans=solveusingmem(weight,value,n-1,capacity,dp);
// cout<<"Answer : "<<ans<<endl;
// int ans=solveusingtab(weight,value,n,capacity);
// cout<<"Answer : "<<ans<<endl;
// int ans=solvespaceopt(weight,value,n,capacity);
// cout<<"Answer : "<<ans<<endl;
int ans=solvespaceopt2(weight,value,n,capacity);
cout<<"Answer : "<<ans<<endl;
    return 0;
}