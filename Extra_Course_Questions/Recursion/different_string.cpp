#include<iostream>
using namespace std;
void formstring(string s,string output,int i){
    if(i>=s.length()){
        cout<<output<<endl;
        return;
    }
    // Excluding s[i] in output
     formstring(s,output,i+1);
    //  Including s[i] in output
    output.push_back(s[i]);
    formstring(s,output,i+1);
}
int main(){
    string s="abc";
    string output="";
    int i=0;
    formstring(s,output,i);
}