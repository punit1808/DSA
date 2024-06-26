#include<iostream>
#include<vector>
using namespace std;


// Also Solved on LeetCode


bool safe(vector<vector<char>> &board,int row, int col, int n){
    int i=row;
    int j=col;
    // Checking in Row
    while(j>=0){
    if(board[i][j]=='Q'){
        return false;
    }
    j--;
    }
    i=row;
    j=col;
    // Checking in upper Diagonal
    while(i>=0 && j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i--;
        j--;
    }
    i=row;
    j=col;
    // Checking in lower Diagonal
    while(i<n && j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
void printsol(vector<vector<char>> &board,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void solve(vector<vector<char>> &board,int col, int n){
    // Base Case
    if(col>=n){
        printsol(board,n);
        return;
    }
    // Placing First Queen
  for(int row=0;row<n;row++){
    if(safe(board,row,col,n)){
        // First Case
        board[row][col]='Q';
        // Recursive Function
        solve(board,col+1,n);
        // Backtracking
         board[row][col]='-';
    }
  }
}
int main(){
    int n=4;
    vector<vector<char>> board(n,vector<char>(n,'-'));
    int col=0;
    solve(board,col,n);
}