#include<iostream>
#include<vector>
using namespace std;



// Also Solved on LeetCode


void solve(vector<string> &mapping,vector<string> &ans,string digits,int index, string output){
    // Base Case
    if(index>=digits.length()){
        ans.push_back(output);
        return;
    }
    // First Case
    int digit=digits[index]-'0';
    string value=mapping[digit];
    for(int i=0;i<value.length();i++){
char ch=value[i];
output.push_back(ch);
solve(mapping,ans,digits,index+1,output);
// Recursive Call
output.pop_back();
    }
}
int main(){
    string digits="2";
    vector<string> ans;
    string output="";
    int index=0;
    vector<string> mapping(10);
    mapping[2]="abc";
    mapping[3]="def";
    mapping[4]="ghi";
    mapping[5]="jkl";
    mapping[6]="mno";
    mapping[7]="pqrs";
    mapping[8]="tuv";
    mapping[9]="wxyz";
    if(digits==""){
        return 0;
    }
    solve(mapping,ans,digits,index,output);
    for(auto i:ans){
        cout<<i<<" ";
    } 

}