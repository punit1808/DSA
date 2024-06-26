#include<iostream>
#include<queue>
using namespace std;
int main(){
    string input="abcdabcd";
    queue<int> q;
    int arr[26]={0};
    for(int i=0;i<input.length();i++){
       arr[input[i]-'a']++;
    }
    for(int i=0;i<input.length();i++){
        if(arr[input[i]-'a']==1){
            q.push(i);
            break;
        }
    }
    if(!q.empty())
    cout<<"First Non-repeating character : "<<input[q.front()]<<endl;
    else{
        cout<<"String have 0 Non-repeating character's "<<endl;
    }
    return 0;
}