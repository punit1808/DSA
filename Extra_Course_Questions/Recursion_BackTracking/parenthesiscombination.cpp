#include<iostream>
#include<vector>
using namespace std;


// Also solved on LeetCode


void solve(int open, int close,vector<string> &ans, string output){
    // Base Case
    if(open==0 && close==0){
        ans.push_back(output);
        return;
    }
    // For open Bracket
    if(open>0){
        output.push_back('(');
        solve(open-1,close,ans,output);
        // Backtracking
        output.pop_back();
    }

    // For close Bracket
    if(close>open){
         output.push_back(')');
        solve(open,close-1,ans,output);
        // Backtracking
        output.pop_back();
    }
}
int main(){
    int open =3;
    int close=3;
    vector<string> ans;
    string output;
    solve(open,close,ans,output);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}